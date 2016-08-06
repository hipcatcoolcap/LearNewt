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
int position=30;
std::string HelpTest;
std::vector <float> Temprature;
//std::vector <float>  reading;
float reading [30][30];
bool running;
int j;

void take_measurement()
{
for (int i=0;i<position;i++)
{
reading[i][j]=rand();
}

}

void print_table_header()
{
	char TEXT [120];
	sprintf(TEXT,"position number\t previous reading\t current reading\t delta\t std");
	newtDrawRootText(1, 2, TEXT);

}

void print_table() 
{
char text [120];

		take_measurement();
	print_table_header();
for (int i=0;i<position;i++)
	
	{
		sprintf(text,"%2i\t %11.1f\t %11.1f\t %11.1f",i,reading[i][j-1],reading[i][j],reading[i][j-1]- reading[i][j]);

		newtDrawRootText(1,3+i,text);
	}
}

void print_screen()
{
 	char help [120];
	newtDrawRootText(0, 0, "measurement output screen");
	sprintf(help,"%s",HelpTest.c_str());
	newtPushHelpLine(help);
	print_time();
	print_table();
	print_lower_right();
	newtRefresh();
}
void print_lower_right()
{
	char TEXT [120];
	sprintf(TEXT,"%s",lower_right.c_str());
	newtDrawRootText(-1*lower_right.size(), -2, TEXT);
	newtRefresh();
	//newtWaitForKey();
}

void print_time()

{
	clock_t t;
	t = clock();
	time(&t);
	srand(time(NULL));
	char TEXT [120];
	sprintf(TEXT,"Temprature is %f",Temprature.back());
	newtDrawRootText(1, 1, TEXT);

	sprintf(TEXT,"%s",asctime(localtime(&t)));
	newtDrawRootText(-20, 1, TEXT);
	newtRefresh();
	//newtWaitForKey();
}


int main(void) {

	
	char text[20];
	Temprature.push_back(999999);
	newtInit();
	newtCls();
	lower_right= "TEST STRING";
	HelpTest = "I AM NO HELP AT ALL";

	for (j=0;j<30;j++)
{
	sprintf(text, "Percent finished %2.1f",(float)j/30*100);
	lower_right = text;
	print_screen();
	sleep(1);
}
	sprintf(text, "TEST COMPLETE");
	newtWaitForKey();
	lower_right = text;
	print_screen();
	newtWaitForKey();
	newtFinished();
}
