#include<stdio.h>
#include<stdlib.h>
struct StuData{
	char name[20];
	char numbers[20];
	char sex[20];
	char birthofdate[20];
    char cla[20];
    char phNO[20];
    char judge[5][5];
    double average;
}ST[100],sd;    //�����ṹ��Ķ��� 
int main()
{
	FILE *fp,*fs;    //д���� 
	int i=0,j,l;
	if((fs=fopen("c:/Users/hp/Desktop/project/studentdata.csv","r"))==NULL)			// ���ļ�������fpָ�� �ļ� 
	{
		printf("Can not open file\n");
		exit(1);
	}
	while(!feof(fs))                     //��ȡһ�����ݺ�ָ��ָ����һ�����ݣ������ж��Ƿ�ָ�����һ��
 	{ 	
 		double min=101,max=0,sum=0; 
		fscanf(fs,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",&ST[i].name,&ST[i].numbers,&ST[i].sex,&ST[i].birthofdate,&ST[i].cla,&ST[i].phNO,&ST[i].judge[0],&ST[i].judge[1],&ST[i].judge[2],&ST[i].judge[3],&ST[i].judge[4]);
		for(l=0;l<5;++l){
			sum+=atof(ST[i].judge[l]);   //atof���ַ���ת��Ϊ˫���ȸ��� 
			if(min>atof(ST[i].judge[l])) min=atof(ST[i].judge[l]);
			if(max<atof(ST[i].judge[l])) max=atof(ST[i].judge[l]);
		}
		ST[i].average=(sum-min-max)/3;
 		i++;
	}  
	j=i;
	for(i=0;i<j;++i){
		for(l=1;l<j-i;++l){
			if(ST[l-1].average<ST[l].average){
				sd=ST[l-1];
				ST[l-1]=ST[l];
				ST[l]=sd;
			}
		}
	}
	for(i=0;i<j;++i)
		printf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%.2lf\n",ST[i].name,ST[i].numbers,ST[i].sex,ST[i].birthofdate,ST[i].cla,ST[i].phNO,ST[i].judge[0],ST[i].judge[1],ST[i].judge[2],ST[i].judge[3],ST[i].judge[4],ST[i].average);
	fclose(fs);
	fp=fopen("c:/Users/hp/Desktop/project/studentdataOut.csv","w+");
	fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n","name","numbers","sex","dateofbirth","class","phoneNo","judge1","judge2","judge3","judge4","judge5","average");
	for(i=0;i<j;++i) 
		fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%.2lf\n",ST[i].name,ST[i].numbers,ST[i].sex,ST[i].birthofdate,ST[i].cla,ST[i].phNO,ST[i].judge[0],ST[i].judge[1],ST[i].judge[2],ST[i].judge[3],ST[i].judge[4],ST[i].average);
    fclose(fp);
	return 0;
}
