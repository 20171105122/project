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
    int i=0,l=0,m=0,n; 
    int max=0,min=101;
    
    fp=fopen("/Users/hp/Desktop/project/studentdata.txt","r");
    
    if(fp==NULL)
    {
        printf("??????");
    }
    else
    {
        ch=fgetc(fp);
		while(ch!=EOF)
		{
			if(i==0)
			{
				if(ch=='\n')
				    ++i;
			}
		    if(i!=0)
			{
			    if(l==0)
				{
			        if(ch==',')
					{
					   l++;
					   numbers[i-1][m+1]='\0';
					   m=0;
					   ch=fgetc(fp);
					   continue;
					}
					numbers[i-1][m]=ch;
					m++; 
				}
				else if(l==1)
				{
				    if(ch==',')
					{
					    l++;
						name[i-1][m+1]='\0';
						m=0;
						ch=fgetc(fp);
						continue;
					}
				    name[i-1][m]=ch;
				    m++;
				}
		        else if(l==2)
				{
				    if(ch==',')
					{
					    l++;
						sex[i-1][m+1]='\0';
						m=0;
						ch=fgetc(fp);
						continue;
					}
					sex[i-1][m]=ch;
					m++;
				}
				else if(l==3)
				{
				    if(ch==',')
					{
					    l++;
						birthofdate[i-1][m+1]='\0';
						m=0;
						ch=fgetc(fp);
						continue;
					}
				    birthofdate[i-1][m]=ch;
				    m++;
			    }
				else if(l==4)
				{
				    if(ch==',')
				    {
					    l++;
						cla[i-1][m]='\0';
						m=0;
						ch=fgetc(fp);
						continue;
				    }
				    cla[i-1][m]=ch;
				    m++;
				}
				else if(l==5)
				{
				    if(ch==',')
				    {
					    l++;
						phNO[i-1][m+1]='\0';
						m=0;
						ch=fgetc(fp);
						continue;
				    }
					phNO[i-1][m]=ch;
					m++;
				}
	
				else{
				    if(ch==',')
					{
						num[i-1][l-6][m+1]='\0';
						average[i-1]+=atof(num[i-1][l-6]);
						if(max<atoi(num[i-1][l-6]))
					    	max=atoi(num[i-1][l-6]);
					    
					    if(min>atoi(num[i-1][l-6]))
							min=atoi(num[i-1][l-6]);
							
						l++;
						m=0;
						ch=fgetc(fp);
						continue;
			        }
		            num[i-1][l-6][m]=ch;
					m++;
					
					if(ch=='\n')
					{
						num[i-1][l-6][m+1]='\0';
						average[i-1]+=atof(num[i-1][l-6]);
						
						if(max<atoi(num[i-1][l-6]))
						    max=atoi(num[i-1][l-6]);
						    
						if(min>atoi(num[i-1][l-6]))
							min=atoi(num[i-1][l-6]);
							
						average[i-1]=(average[i-1]-max-min)/(l-7);
						max=0;min=101;
						i++;l=0;m=0;
					}
			    }
		    }
    		ch=fgetc(fp);
		}
		num[i-1][l-6][m+1]='\0';
	    average[i-1]+=atof(num[i-1][l-6]);
	
	    if(max<atoi(num[i-1][l-6]))
	        max=atoi(num[i-1][l-6]);
	
	    if(min>atoi(num[i-1][l-6]))
	        min=atoi(num[i-1][l-6]);
	
	    average[i-1]=(average[i-1]-max-min)/(l-7);
	    fclose(fp);
	    for(n=0;n<i;n++)
	    { 
			printf("%s,%s,%s,%s,%s,%s,%.2lf\n",numbers[n],name[n],sex[n],birthofdate[n],cla[n],phNO[n],average[n]);
	    }
		fp=fopen("Users\hp\Desktop\project/biao.csv","w+");
		fprintf(fp,"%s,%s,%s,%s,%s,%s,%s\n","nummbers","name","sex","dateofbirth","class","phoneNo","average");
		 
		for(n=0;n<i;n++)
		{ 
			fprintf(fp,"%s,%s,%s,%s,%s,%s,%.2lf\n",numbers[n],name[n],sex[n],birthofdate[n],cla[n],phNO[n],average[n]);	
		} 
	    fclose(fp);
    }
    return 0;
}
	    
 
