#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define K 2.303
struct input
{
float initialtemperature,finaltemperature;
struct time
{

int hours;

int minutes;

}time1,time2,differencetime,timeofdeath,tod;

}input1;

void display(input1,input1,input1,input1);

int main()

{

float a,b,c;

float roomtemp,normal=98.6;

int t1=0,t2,t3;

double c1,c2,e;


char ch;
 
FILE *fp;
	FILE *fi;

fp=fopen("Post.txt","w");
	fprintf(fp,"Final Report\n");

fi=fopen("C:\\Users\\piyus\\OneDrive\\Documents\\VirtualC\\1.txt", "r");
	if (fi == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fi);
    while (ch != EOF)
    {
        printf ("%c", ch);
        ch = fgetc(fi);
    }
 

puts("\nEnter temperature 1 in Farenheit");

scanf("%f",&input1.initialtemperature);

	if(input1.initialtemperature > 98.6)

	{

		exit(1);

	}

puts("Enter time of initial temperature");

scanf("%d%d",&input1.time1.hours,&input1.time1.minutes);

if(input1.time1.minutes>=60)

{

puts("Enter Minutes less than or Equal to 60(Exiting Program...)");

exit(0);



}

	fprintf(fp,"INITIAL TEMPERATURE:%f\n",input1.initialtemperature);

	fprintf(fp,"INITIAL TEMPERATURE TIME:%dhrs %d min\n",input1.time1.hours,input1.time1.minutes);

puts("Enter temperature 2 in Farenheit");

scanf("%f",&input1.finaltemperature);
	if(input1.finaltemperature>input1.initialtemperature)
	{
		puts("\nTemperature 2 should be less than Temperature 1");

		exit(0);
	}

	fprintf(fp,"FINAL TEMPERATURE:%f\n",input1.finaltemperature);

puts("Enter time of 2nd temperature recorded");

scanf("%d%d",&input1.time2.hours,&input1.time2.minutes);

if(input1.time1.minutes>=60)

{

puts("Enter Minutes less than or Equal to 60(Exiting Program...)");

exit(0);

}

	fprintf(fp,"FINAL TEMPERATURE TIME:%dhrs %d min\n",input1.time2.hours,input1.time2.minutes);

	

puts("Enter Room Temperature ");

scanf("%f",&roomtemp);

input1.differencetime.hours = input1.time2.hours - input1.time1.hours;

input1.differencetime.minutes = input1.time2.minutes - input1.time1.minutes;

if(input1.differencetime.minutes>60)

{

input1.differencetime.hours++;

}

t2=(input1.differencetime.hours*60);

t2=t2+input1.differencetime.minutes;

printf("%d  Minutes is The Time Difference  Between Initial and Final Recording",t2);

fprintf(fp,"%d is The Time Difference in Minutes Between Initial and Final Recording\n",t2);

a=input1.initialtemperature-roomtemp;

b=input1.finaltemperature-roomtemp;

c=(1/t2)*(log(b/a)*K);

t3=-t2*(log((normal-roomtemp)/(a)))*K/((log(a/b)*K));

input1.timeofdeath.hours=abs(t3/60);

input1.timeofdeath.minutes=abs(t3%60);

input1.tod.hours=input1.time1.hours-(input1.timeofdeath.hours);

input1.tod.minutes=60-(input1.timeofdeath.minutes);

        if(     input1.tod.minutes<60)

        {

                input1.tod.hours--;



        }

        if(     input1.tod.minutes>60 && input1.tod.minutes<0 )

        {

                input1.tod.hours++;

                input1.tod.minutes=(input1.timeofdeath.minutes)-60;

        }

	display(input1.tod.hours,input1.tod.minutes ,input1.timeofdeath.hours,input1.timeofdeath.minutes);

fprintf(fp,"Time of Death %d:%d",input1.tod.hours,input1.tod.minutes );

	fclose(fp);

	

return 0;

}
void display(input1 x,input1 y,input1 ab,input1 ba)

{

	printf("\nTime of Death %d : %d   ",x,y);

}