#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
typedef struct address_record //address_record是結構名
{
		char name[MAX];
		char phone[MAX];
		int age;
} addr_rec;//typedef給的新名字 →typedef struct address_record addr_rec

addr_rec addr_array[MAX];//array of structure
int name_compare(const void *a,const void *b)
{
		return (strcmp((*(addr_rec*)a).name,(*(addr_rec*)b).name));
}
int phone_compare(const void *a,const void *b)
{
		return (strcmp((*(addr_rec*)a).phone,(*(addr_rec*)b).phone));
}
int age_compare(const void *a,const void *b)
{
		return ((*(addr_rec*)a).age-(*(addr_rec*)b).age);
}
		
int main(int argc,char *argv[])
{
		int n=0,r=0,K=0;// 看r、K的值去決定要做什麼動作
		int i;
		char input[100];
		if(argc==2)
		{
				if(strcmp(argv[1],"-r")==0)
						r=1;
				else if(strcmp(argv[1],"-K")==0)
				{
						printf("輸入錯誤,-K後面必須有東西(ex:name|age|phone)\n");
						return 0;
				}
		}
		else if(argc==3)
		{
				if(strcmp(argv[1],"-K")==0)//出現-K
				{
						if(strcmp(argv[2],"name")==0)//如果是對name欄位作排序
								K=1;
						if(strcmp(argv[2],"phone")==0)//如果是對phone欄位作排序
								K=2;
						if(strcmp(argv[2],"age")==0)//如果是對age欄位作排序
								K=3;
				}
				else if(strcmp(argv[1],"-r")==0)
						r=1;
				if(strcmp(argv[2],"-K")==0)
				{
						printf("輸入錯誤,-K後面必須有東西(ex:name|age|phone)\n");
						return 0;
				}
				else if(strcmp(argv[2],"-r")==0)
				{
						r=1;
						printf("-K後面沒有東西哦,印的是-r唷\n");
				}
		}
		else if(argc==4)
		{
				if(strcmp(argv[1],"-r")==0||strcmp(argv[2],"-r")==0||strcmp(argv[3],"-r")==0)
						r=1;
				if(strcmp(argv[1],"-K")==0||strcmp(argv[2],"-K")==0)
				{
						
								if(strcmp(argv[3],"name")==0||strcmp(argv[2],"name")==0)
										K=1;
								if(strcmp(argv[3],"phone")==0||strcmp(argv[2],"phone")==0)
										K=2;
								if(strcmp(argv[3],"age")==0||strcmp(argv[2],"age")==0)
										K=3;
								
								
				}
						
				
		}

		char *ptr;
		//char *delim="\t:\n";
		char *store[100];
		int N=0,A=0,P=0;

		while(fgets(input,100,stdin)!=NULL)
		{
				ptr=strtok(input,"\t\n:");
				while(ptr != NULL)
				{
						store[n]=(char *)malloc(100);

						strcpy(store[n],ptr);
						n++;
						ptr=strtok(NULL,"\t\n:");
				}
				 
				for(i=0;i<n;i++)
				{
						if(strcmp(store[i],"name")==0)
						{
								if(strcmp(store[i+1],"age")==0)
								{
										strcpy(addr_array[N].name,"noname");
								}
								else
								{
										strcpy(addr_array[N].name,store[i+1]);
								}
								//printf("%s\n",addr_array[N].name);
								N++;
								
						}
						if(strcmp(store[i],"age")==0)
						{
								//printf("%d#\n",store[i+1]);
								addr_array[A].age=atoi(store[i+1]);
								//printf("%d\n",addr_array[A].age);
								
								A++;
						}
						if(strcmp(store[i],"phone")==0)
						{
								strcpy(addr_array[P].phone,store[i+1]);
								//printf("%s\n",addr_array[P].phone);
								P++;
						}
				}
				n=0;								
		}
		
		if(K==1|K==0)
		{
				qsort(addr_array,N,sizeof(addr_array[0]),name_compare);
		}
		else if(K==2)
		{
				qsort(addr_array,P,sizeof(addr_array[0]),phone_compare);
		}
		else if(K==3)
		{
				qsort(addr_array,A,sizeof(addr_array[0]),age_compare);
		}

		if(r==0)
		{
				for(i=0;i<N;i++)
				{
						printf("name:%s\tage:%d\tphone:%s\n",addr_array[i].name,addr_array[i].age,addr_array[i].phone);
				}
		}
		else if(r==1)
		{
				for(i=N-1;i>=0;i--)
				{
						printf("name:%s\tage:%d\tphone:%s\n",addr_array[i].name,addr_array[i].age,addr_array[i].phone);
				}
		}
				
				
		return 0;
}



