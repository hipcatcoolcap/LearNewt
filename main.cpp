#include <newt.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
//#include <MAIN.H>


void print_lower_right(std::string test)
{
	char TEXT [120];
	sprintf(TEXT,"%s",test.c_str());
	newtDrawRootText(-1*test.size(), -2, TEXT);
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
