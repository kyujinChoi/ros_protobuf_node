#include <stdio.h>
#include <wiringPi.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
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

/*	pinMode(GPIO_26, OUTPUT);
	pinMode(GPIO_19, OUTPUT);
	pinMode(GPIO_13, OUTPUT);
	digitalWrite(GPIO_26, LOW);
	digitalWrite(GPIO_19, LOW);
	digitalWrite(GPIO_13, LOW);
*/	pinMode(GPIO_26, INPUT);
	pinMode(GPIO_19, INPUT);
	pinMode(GPIO_13, INPUT);
}

void intHandler(int sig)
{
	printf("TURN OFF\n");
	digitalWrite(GPIO_12, HIGH);
		digitalWrite(GPIO_16, HIGH);
		digitalWrite(GPIO_18, HIGH);
		digitalWrite(GPIO_20, HIGH);
		digitalWrite(GPIO_21, HIGH);
		digitalWrite(GPIO_23, HIGH);
		digitalWrite(GPIO_24, HIGH);
		digitalWrite(GPIO_25, HIGH);
	exit(0);

}
void *inputHandler(void *arg)
{

	while(1)
	{
		if(digitalRead(GPIO_26) == HIGH)
			printf("GPIO_26 is High!\n");
		else if(digitalRead(GPIO_19) == HIGH)
			printf("GPIO_19 is High!\n");

		else if(digitalRead(GPIO_13) == HIGH)
			printf("GPIO_13 is High!\n");
	}
}
int main(void)
{
	pthread_t p_id;
	if(wiringPiSetupGpio() == -1)
	{
		printf("wiringPiSetup error\n");
		return 0;
	}
	setPinMode();
	signal(SIGINT, intHandler);
	pthread_create(&p_id, NULL, inputHandler, (void *)NULL);
	pthread_detach(p_id);
	while(1)
	{
		digitalWrite(GPIO_12, HIGH);
		digitalWrite(GPIO_16, HIGH);
		digitalWrite(GPIO_18, HIGH);
		digitalWrite(GPIO_20, HIGH);
		digitalWrite(GPIO_21, HIGH);
		digitalWrite(GPIO_23, HIGH);
		digitalWrite(GPIO_24, HIGH);
		digitalWrite(GPIO_25, HIGH);
		delay(500);
		digitalWrite(GPIO_12, LOW);
		digitalWrite(GPIO_16, LOW);
		digitalWrite(GPIO_18, LOW);
		digitalWrite(GPIO_20, LOW);
		digitalWrite(GPIO_21, LOW);
		digitalWrite(GPIO_23, LOW);
		digitalWrite(GPIO_24, LOW);
		digitalWrite(GPIO_25, LOW);
		delay(500);
	}
	return 0;

}
