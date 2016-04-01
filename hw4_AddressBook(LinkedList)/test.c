#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

typedef struct Tphonebook
{
		char name[MAX];
		char phone[MAX];
}phonebook;

phonebook book[MAX];



int main(int argc,char *argv[])
{
		int i,comd;
		int N=0,n=0;
		
		char *ptr;
		char *store[MAX];
		char buf[MAX];
		FILE *fp; 

		fp=fopen(argv[1],"r");//open file argv[1],and read-only mode("r")
		if(argc==2)
		{
				printf("1)list\n2)find\n3)insert\n4)delete\n5)exit\n");
				printf("Please enter command:\n");
				scanf("%d",&comd);
		}
		while(fgets(buf,MAX,fp)!=NULL)
		{
				ptr=strtok(buf,"\t\n");
				while(ptr!=NULL)
				{
						store[n]=(char *)malloc(100);
						strcpy(store[n],ptr);
						n++;
						ptr=strtok(NULL,"\t\n");
				}
				
				
						strcpy(book[N].name,store[1]);
						//printf("%s\n",book[N].name);
						strcpy(book[N].phone,store[3]);
						//printf("%s\n",book[N].phone);
						N++;				
				n=0;
		
		}
		switch(comd)
		{
				char search[20];
				char delet[20];
				case 1:
					printf("Name\tPhone\n");
					printf("--------------\n");
					for(i=0;i<N;i++)
					{
							printf("%s\t%s\n",book[i].name,book[i].phone);
					}
					break;
				case 2:
					
					printf("Please input the search name\n");
					scanf("%s",search);
					for(i=0;i<N;i++)
					{
							if(strcmp(book[i].name,search)==0)
							{
									printf("Name\tPhone\n");
									printf("--------------\n");
									printf("%s\t%s\n",book[i].name,book[i].phone);
							}
					}
				



				
		}
		return 0;
}



