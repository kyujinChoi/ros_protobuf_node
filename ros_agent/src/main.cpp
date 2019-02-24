
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "ros/ros.h"
#include "ros_agent/curVelocity.h"
#include <geometry_msgs/TwistStamped.h>

using namespace std;
#define BUF_SIZE 255

int sockfd;
double send_buffer[2];
double recv_buffer[1];

double convert_mps_to_kmh(double linear_x)
{
    return linear_x * 3.6;
}

void sendmsg()
{
    int bytecount;
    int i = 0;

    printf("Sending target_V : %lf\n", send_buffer[0]);
    printf("Sending target_W : %lf\n", send_buffer[1]);
    //printf("currnet vel : %lf\n",convert_mps_to_kmh(buffer[2]));

    if ((bytecount = send(sockfd, send_buffer, sizeof(send_buffer), 0)) == -1)
    {
        fprintf(stderr, "Error sending data %d\n", errno);
    }
}

void curVelCallback(const geometry_msgs::TwistStampedConstPtr &msg)
{
    //buffer[2]= convert_mps_to_kmh(msg->twist.linear.x);
}

void twistCallback(const geometry_msgs::TwistStampedConstPtr &input_msg)
{
    send_buffer[0] = convert_mps_to_kmh(input_msg->twist.linear.x);
    send_buffer[1] = input_msg->twist.angular.z;
    sendmsg();
}

int main(int argc, char **argv)
{
    int bytecount;
    ros::init(argc, argv, "ros_agent_node");
    ros::NodeHandle nh;

    ros::Subscriber agent_sub = nh.subscribe("/twist_cmd", 1, twistCallback);
    //ros::Subscriber agent_sub1 = nh.subscribe("/current_velocity", 1, curVelCallback);
    ros::Publisher agent_pub = nh.advertise<ros_agent::curVelocity>("/my_cur_vel", 100);
    ros_agent::curVelocity msg;
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
    printf("connected...\n");

    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        if((bytecount = recv(sockfd, recv_buffer, sizeof(recv_buffer), MSG_WAITALL)) == -1)
        {
            fprintf(stderr, "Error receiving data %d\n", errno);
        }
        msg.cur_vel = recv_buffer[0];
        agent_pub.publish(msg);
        printf("\tReceiving current_V : %lf, %lf\n",msg.cur_vel,convert_mps_to_kmh(msg.cur_vel));
    }
    

    ros::spin();
}
