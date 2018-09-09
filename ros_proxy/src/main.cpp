
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "ros/ros.h"
#include "ros_proxy/umsg.pb.h"

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

char message[BUF_SIZE] ;
int idx=0;
int halfsd;
void send_msg()
{
    int siz;
    char *pkt;
    int bytecount;
    siz = oper_msg.ByteSize();
    pkt = new char[siz + 2];
    google::protobuf::io::ArrayOutputStream aos(pkt, siz + 2);
    CodedOutputStream *coded_output = new CodedOutputStream(&aos);
    coded_output->WriteVarint32(1);
    coded_output->WriteVarint32(siz);
    oper_msg.SerializeToCodedStream(coded_output);
    if ((bytecount = send(halfsd, (void *)pkt, siz + 2, 0)) == -1)
    {   
        fprintf(stderr, "Error sending data %d\n", errno);
    }
    delete pkt;
    usleep(1);
}

int main(int argc, char**argv)
{
    ros::init(argc, argv,"ros_proxy_node");
    ros::NodeHandle nh;
    
    
    struct sockaddr_in server_addr;

    halfsd = socket(PF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(9000);
    inet_aton("127.0.0.1", &server_addr.sin_addr);
    memset(&(server_addr.sin_zero), 0, 8);

    if(connect(halfsd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) ==-1)
    {
        printf("connect error=n");
        return 0;
    }
    
    printf("connected...\n");
    
    
    int str_len, recv_len, recv_cnt;
    int i,result;
    int count=0;
    
    sleep(1);
    while(1)
    {
        //sprintf(message, "Message from client %d", count++);    
        //str_len=write(halfsd, message, strlen(message));
        //message[str_len] = 0;
        oper_msg.set__seqno(1);
        oper_msg.set__to(1);
        oper_msg.set__name("Ecat_State");
        oper_msg.set__value(count++);
        oper_msg.set__msg("ecatup");
        oper_msg.set__from(0);
        oper_msg.set__result(1);
        send_msg();
        sleep(1);
    }
}

