#include <newt.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>

//function list
int main (void);
void print_time();
void print_lower_right();
void print_screen(); 
void print_table_header();

std::string lower_right;
std::string HelpTest;
bool running;
std::vector <float> Temprature;

void print_table_header()
{
	char TEXT [120];
	sprintf(TEXT,"position number\t previous reading\t current reading\t delta\t std");
	newtDrawRootText(1, 2, TEXT);

}
void print_screen()
{
 	char help [120];
	newtDrawRootText(0, 0, "Temprature Coefficient Test System");
	sprintf(help,"%s",HelpTest.c_str());
	newtPushHelpLine(help);
	print_time();
	print_table_header();
	print_lower_right();
	newtRefresh();
}
void print_lower_right()
{
	char TEXT [120];
	sprintf(TEXT,"%s",lower_right.c_str());
	newtDrawRootText(-1*lower_right.size(), -2, TEXT);
	newtRefresh();
	newtWaitForKey();
}

void print_time()

{
	clock_t t;
	t = clock();
	time(&t);
	char TEXT [120];
	sprintf(TEXT,"Temprature is %f",Temprature.back());
	newtDrawRootText(1, 1, TEXT);

	sprintf(TEXT,"%s",asctime(localtime(&t)));
	newtDrawRootText(-20, 1, TEXT);
	newtRefresh();
	newtWaitForKey();
}
int main(void) {
	Temprature.push_back(999999);
	newtInit();
	newtCls();
	lower_right= "TEST STRING";
	HelpTest = "I AM NO HELP AT ALL";
	print_screen();
	newtWaitForKey();
	lower_right = "second string";
	print_screen();
	sleep(1);
	newtFinished();
}
