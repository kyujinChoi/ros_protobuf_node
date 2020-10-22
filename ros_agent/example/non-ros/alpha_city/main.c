#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <syslog.h>

#include <pthread.h>
#include <wiringPi.h>
#include <signal.h>
// OUTPUT
#define GPIO_12 12
#define GPIO_16 16
#define GPIO_18 18
#define GPIO_20 20
#define GPIO_21 21
#define GPIO_23 23
#define GPIO_24 24
#define GPIO_25 25

// INPUT
#define GPIO_26 26
#define GPIO_19 19
#define GPIO_13 13
#define BUF_SIZE 10

char send_buffer[BUF_SIZE];
char recv_buffer[BUF_SIZE];
int halfsd, fullsd;
struct sockaddr_in sockaddr;
bool is_connected = false;
bool is_pressed = true;
int startupServer(char *ipaddr, int portno)
{
  struct sockaddr_in sockaddr;
  int sockfd;
  int val = 1;

  // create an unnamed socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // set a socket option to reuse the server address
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) != 0)
  {
    printf("error: setsockopt(): %s\n", strerror(errno));
    syslog(LOG_ERR, "error: setsockopt(): %s\n", strerror(errno));
    return -1;
  }

  // name the socket with the server address
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_addr.s_addr = inet_addr(ipaddr); //htonl(INADDR_ANY);
  sockaddr.sin_port = htons(portno);
  memset(&sockaddr.sin_zero, 0, 8);

  if (bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) != 0)
  {
    printf("error: bind(): %s\n", strerror(errno));
    syslog(LOG_ERR,"error: bind(): %s\n", strerror(errno));
    return -1;
  }

  // set the maximum number of pending connection requests
  if (listen(sockfd, 10) != 0)
  {
    printf("error: listen(): %s\n", strerror(errno));
    syslog(LOG_ERR, "error: listen(): %s\n", strerror(errno));
    return -1;
  }

  return sockfd;
}
void setPinMode()
{
	pinMode(GPIO_12, OUTPUT);
	pinMode(GPIO_16, OUTPUT);
	pinMode(GPIO_18, OUTPUT);
	pinMode(GPIO_20, OUTPUT);
	pinMode(GPIO_21, OUTPUT);
	pinMode(GPIO_23, OUTPUT);
	pinMode(GPIO_24, OUTPUT);
	pinMode(GPIO_25, OUTPUT);

	pinMode(GPIO_26, OUTPUT);
	pinMode(GPIO_19, OUTPUT);
	pinMode(GPIO_13, OUTPUT);
	digitalWrite(GPIO_26, LOW);
	digitalWrite(GPIO_19, LOW);
	digitalWrite(GPIO_13, LOW);
	pinMode(GPIO_26, INPUT);
	pinMode(GPIO_19, INPUT);
	pinMode(GPIO_13, INPUT);
}
bool echoMsg()
{
	int bytecnt;
	printf("size : %d\n", sizeof(send_buffer)); 
	printf("message[0] : %c\n", send_buffer[0]);
	printf("message[1] : %c\n", send_buffer[1]);
	syslog(LOG_ERR, "size : %d\n", sizeof(send_buffer)); 
	syslog(LOG_ERR, "message[0] : %c\n", send_buffer[0]);
	syslog(LOG_ERR, "message[1] : %c\n", send_buffer[1]);
	if((bytecnt = send(fullsd, send_buffer, BUF_SIZE, 0)) == -1)
	{
		fprintf(stderr, "Error sending data %d\n", errno);
	}
	printf("send bytecnt : %d\n", bytecnt);
	syslog(LOG_ERR, "send bytecnt : %d\n", bytecnt);

	if(recv(fullsd, recv_buffer, BUF_SIZE, MSG_WAITALL) > 0)
	{
		printf("received %c\n", recv_buffer[0]);
		return true;
	}
	else
	{
		return false;
	}
	
}
void turnOffAll()
{
//printf("TURN OFF\n");
	digitalWrite(GPIO_12, HIGH);
		digitalWrite(GPIO_16, HIGH);
		digitalWrite(GPIO_18, HIGH);
		digitalWrite(GPIO_20, HIGH);
		digitalWrite(GPIO_21, HIGH);
		digitalWrite(GPIO_23, HIGH);
		digitalWrite(GPIO_24, HIGH);
		digitalWrite(GPIO_25, HIGH);

}
void turnOnAll()
{
//printf("TURN ON\n");
	digitalWrite(GPIO_12, LOW);
		digitalWrite(GPIO_16, LOW);
		digitalWrite(GPIO_18, LOW);
		digitalWrite(GPIO_20, LOW);
		digitalWrite(GPIO_21, LOW);
		digitalWrite(GPIO_23, LOW);
		digitalWrite(GPIO_24, LOW);
		digitalWrite(GPIO_25, LOW);

}
void intHandler(int sig)
{
	turnOffAll();
		sprintf(send_buffer, "y");
		echoMsg();
		close(fullsd);
	exit(0);

}
void flushBuffers()
{
	for(int i = 0; i< BUF_SIZE; i++)
	{
		recv_buffer[i] = '\0';
		send_buffer[i] = '\0';
	}
}
bool isBtnPressed()
{
	if(digitalRead(GPIO_26) == HIGH)
	{
		printf("GPIO_26 is High!\n");
		return true;
	}
	else if(digitalRead(GPIO_19) == HIGH)
	{
		printf("GPIO_19 is HIGH!\n");
		return true;
	}
	else if(digitalRead(GPIO_13) == HIGH)
	{
		printf("GPIO_13 is HIGH!\n");
		return true;
	}
	else return false;
}
void *inputHandler(void *arg)
{
	bool was_pressed;
	
	is_pressed = isBtnPressed();
	was_pressed = is_pressed;
	while(1)
	{
		is_pressed = isBtnPressed();
		if(is_pressed != was_pressed)
		{
			if(is_connected)
			{
				flushBuffers();

				if(is_pressed)
					sprintf(send_buffer, "y");
				else
					sprintf(send_buffer, "n");

				echoMsg();
				usleep(100*1000);
			}
			was_pressed = is_pressed;
		}
	}
}

void *recvHandler(void *arg)
{
	int bytecnt;
	int len;
	while(1)
	{
		bytecnt = recv(fullsd, recv_buffer, BUF_SIZE, MSG_PEEK);
		if(bytecnt == -1)
		{
			fprintf(stderr, "Error receiving data%d\n", errno);
			close(fullsd);
			exit(0);
		}
		else if(bytecnt == 0)
		{
			printf("received close()\n");
			syslog(LOG_ERR,"received close()\n");
			close(fullsd);
			is_connected = false;
			turnOffAll();
    			len = sizeof(sockaddr);

			fullsd = accept(halfsd, (struct sockaddr *)&sockaddr, (socklen_t *)&len);
    			if(fullsd<0)
    			{
	    			printf("error : accept() : %s\n", strerror(errno));
	    			return 0;
    			}
    			printf("reconnected\n");
    			syslog(LOG_ERR, "reconnected\n");
			is_connected = true;
		}
	}
}

int main()
{
    char *ipaddr;
    int portno;
    struct in_addr server_ip;

    pthread_t p_id[2];
    if(wiringPiSetupGpio() == -1)
    {
	    printf("wiringPiSetup error\n");
	    syslog(LOG_ERR, "wiringPiSetup error\n");
	    return 0;
    }
    setPinMode();
    signal(SIGINT, intHandler);
	
    ipaddr = "192.168.1.32";
    portno = 9000;
    
    printf("server address = %s:%d\n", ipaddr, portno);
    syslog(LOG_ERR,"server address = %s:%d\n", ipaddr, portno);

    if ((halfsd = startupServer(ipaddr, portno)) < 0)
    {
	    printf("cannot start up sever\n");
	    syslog(LOG_ERR, "cannot start up sever\n");
	    exit(1);
    }

    int len = sizeof(sockaddr);
    fullsd = accept(halfsd, (struct sockaddr *)&sockaddr, (socklen_t *)&len);
    if(fullsd<0)
    {
	    printf("error : accept() : %s\n", strerror(errno));
	    return 0;
    }
    printf("Connected\n");
    syslog(LOG_ERR, "Connected\n");

    is_connected = true;

    pthread_create(&p_id[0], NULL, inputHandler, (void *)NULL);
    pthread_detach(p_id[0]);
    pthread_create(&p_id[1], NULL, recvHandler, (void *)NULL);
    pthread_detach(p_id[1]);
    while(1)
    {
	if(is_connected)
	{
	    	if(is_pressed)
		{
			turnOffAll();
			delay(500);
			turnOnAll();
			delay(500);
		}
		else
		{
			turnOnAll();
		}
	}
	else
	{
		turnOffAll();
	}
    }
    close(fullsd);
}

