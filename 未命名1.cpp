#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
	char ch;
	char name[20][100];
	char numbers[20][100];
	char sex[20][100];
	char birthofdate[20][100];
    char cla[20][100];
    char phNO[20][100];
    char num[100][100][20];
    
    double average[100];
    int i=0,l=0,m=0; 
    int max=0,min=101;
    
    if(fp==NULL)
    {
        printf("??????");
    }
    else
    {
        ch=fgetc(fp);
	} 
