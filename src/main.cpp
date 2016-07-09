#include <newt.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <time.h>


void print_time();

void print_lower_right(std::string test)
{
	char TEXT [120];
	sprintf(TEXT,"%s",test.c_str());
	newtDrawRootText(-1*test.size(), -2, TEXT);
	print_time();
	newtRefresh();
	newtWaitForKey();
}

void print_time()

{
	clock_t t;
	t = clock();
	time(&t);
	char TEXT [120];
	sprintf(TEXT,"%s",asctime(localtime(&t)));
	newtDrawRootText(-20, 1, TEXT);
	newtRefresh();
	newtWaitForKey();
}
int main(void) {

	newtInit();
	newtCls();
	newtDrawRootText(0, 0, "Temprature Coefficient Test System");
	print_lower_right("TEST STRING");
	newtPushHelpLine("I AM NO HELP AT ALL");
	newtRefresh();
	newtWaitForKey();
	print_lower_right("second string");
	newtPopHelpLine();
	newtRefresh();
	sleep(1);
	newtFinished();
}
