
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include "ros/ros.h"
#include "ros_agent/curVelocity.h"
#include <geometry_msgs/TwistStamped.h>
#define BUF_SIZE 10
using namespace std;

int sockfd;
char recv_buffer[BUF_SIZE];
char send_buffer[BUF_SIZE];
void flushBuffer()
{
    for(int i = 0; i < BUF_SIZE; i++)
    {
        recv_buffer[i] = '\0';
        send_buffer[i] = '\0';
    }
}
void sendmsg()
{
    int bytecount;
    int i = 0;

    printf("Sending send_buffer[0] : %c\n", send_buffer[0]);
    printf("Sending send_buffer[1] : %c\n", send_buffer[1]);

    if ((bytecount = send(sockfd, send_buffer, strlen(send_buffer)+1, 0)) == -1)
    {
        fprintf(stderr, "Error sending data %d\n", errno);
    }
}
void intHandler(int sig)
{
    printf("SIG INT CALLED\n");
    close(sockfd);
    exit(0);
}

int main(int argc, char **argv)
{
    int bytecount;
    ros::init(argc, argv, "ros_agent_node");
    ros::NodeHandle nh;

    struct sockaddr_in server_addr;

    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    signal(SIGINT, intHandler);
    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(9000);
    inet_aton("192.168.0.4", &server_addr.sin_addr);
    memset(&(server_addr.sin_zero), 0, 8);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        printf("connect error=n");
        return 0;
    }
    printf("connected...\n");
    flushBuffer();
    // ros::Rate loop_rate(10);
    while(1)
    {
        bytecount = recv(sockfd, recv_buffer, BUF_SIZE, MSG_WAITALL);
        if(bytecount == -1)
        {
            printf("bytecount : %d\n",bytecount );
            printf("sizeof(recv_buffer) : %d\n",sizeof(recv_buffer) );
            printf("recv_buffer[0] : %c\n", recv_buffer[0] );
            printf("recv_buffer[1] : %c\n", recv_buffer[1] );
            fprintf(stderr, "Error receiving data %d\n", errno);
            close(sockfd);
            return 0;
        }
        else if(bytecount == 0)
        {
            printf("closed by server\n");
            close(sockfd);
            return 0;
        }
        if(strcmp(recv_buffer, "y") == 0)
        {
            sprintf(send_buffer, "y");
            printf("\tReceiving true\n");
            sendmsg();
        }
        if(strcmp(recv_buffer, "n") == 0)
        {
            sprintf(send_buffer, "n");
            printf("\tReceiving false\n");
            sendmsg();
        }
    }
    close(sockfd);
}
