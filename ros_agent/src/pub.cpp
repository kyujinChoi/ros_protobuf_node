
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "ros/ros.h"
#include "ros_agent/umsg.pb.h"
#include "ros_agent/motorPose.h"
#include <geometry_msgs/TwistStamped.h>

#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

using namespace google::protobuf::io;
using namespace vcf;
using namespace std;
#define BUF_SIZE 255

vcf::Operational_msg oper_msg;
int sockfd;
int left_pose, right_pose, msg_cnt;

void readHdr(google::protobuf::uint32 hdr[], char *buf)
{
    google::protobuf::io::ArrayInputStream ais(buf, 2);
    CodedInputStream coded_input(&ais);
    coded_input.ReadVarint32(&hdr[0]);
    coded_input.ReadVarint32(&hdr[1]);
    //cout << "\tHDR: type (in int32) " << hdr[0] << endl;
    //cout << "\tHDR: content (in int32) " << hdr[1] << endl;
}

Operational_msg *operational_ReadBody(int sockfd, google::protobuf::uint32 *hdr)
{
    int bytecount;
    char buffer[hdr[1] + 2];
    Operational_msg *oper_msg = new Operational_msg;
    //Read the entire buffer including the hdr
    //printf("******start operational function**********\n");
    //printf("\tsockfd = %d\n", sockfd);
    if ((bytecount = recv(sockfd, (void *)buffer, hdr[1] + 2, MSG_WAITALL)) == -1)
    {
        fprintf(stderr, "Error receiving data %d\n", errno);
    }
    //cout << "\tBODY: bytecount = " << bytecount << endl;
    //Assign ArrayInputStream with enough memory
    google::protobuf::io::ArrayInputStream ais(buffer, hdr[1] + 2);
    CodedInputStream coded_input(&ais);
    //Read an unsigned integer with Varint encoding, truncating to 32 bits.
    coded_input.Skip(2);
    //After the message's length is read, PushLimit() is used to prevent the CodedInputStream
    //from reading beyond that length.Limits are used when parsing length-delimited
    //embedded messages
    google::protobuf::io::CodedInputStream::Limit msgLimit = coded_input.PushLimit(hdr[1]);
    //De-Serialize
    oper_msg->ParseFromCodedStream(&coded_input);
    //Once the embedded message has been parsed, PopLimit() is called to undo the limit
    coded_input.PopLimit(msgLimit);
    //Print the message
    //cout << "\tMessage is \n"
    // << oper_msg->DebugString() << endl;
    return oper_msg;
}

int main(int argc, char **argv)
{
    char buffer[2];
    int bytecount = 0;
    google::protobuf::uint32 hdr[2];

    memset(buffer, '\0', 2);

    ros::init(argc, argv, "ros_agent_pub");
    ros::NodeHandle nh;

    ros::Publisher agent_pub = nh.advertise<ros_agent::motorPose>("/motor_pos", 100);

    struct sockaddr_in server_addr;

    sockfd = socket(PF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(9000);
    inet_aton("127.0.0.1", &server_addr.sin_addr);
    memset(&(server_addr.sin_zero), 0, 8);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        printf("connect error=n");
        return 0;
    }

    printf("publisher connected...\n");

    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        if (msg_cnt == 2)
        {
            ros_agent::motorPose msg;
            msg.left_pos = left_pose;
            msg.right_pos = right_pose;
            agent_pub.publish(msg);
            msg_cnt = 0;
        }

        if ((bytecount = recv(sockfd, buffer, 2, MSG_PEEK)) == -1)
        {
            fprintf(stderr, "Error receiving data %d\n", errno);
        }
        else if (bytecount == 0)
        {
            printf("connection fail\n");
            break;
        }

        readHdr(hdr, buffer);

      
            Operational_msg *oper_msg;

            //printf("#############It's Operational_msg################\n\t");
            //printf("\tin recv in if: client_idx = %d cliets[*client_idx].sockfd= %d \n", client_idx, clients[client_idx].sockfd);
            oper_msg = operational_ReadBody(sockfd, hdr);
            if (strcmp(oper_msg->_name().c_str(), "Left_Wheel") == 0)
            {
                left_pose = (int)(oper_msg->_value());
                msg_cnt++;
                printf("GOT Left Wheel Pos : %d\n",(int)(oper_msg->_value()));
            }
            else if (strcmp(oper_msg->_name().c_str(), "Right_Wheel") == 0)
            {
                right_pose = (int)(oper_msg->_value());
                msg_cnt++;
                printf("GOT Right Wheel Pos : %d\n",(int)(oper_msg->_value()));
            }
            else
            {
                printf("******** Unknown Msg*********\n");
                continue;
            }

            
            //printf("\tbefor PostOperationalMsg\n client_idx = %d\n", client_idx);
            //send_thread[client_idx]->PostOperationalMsg((const Operational_msg *)umsg);
      
    }
}
