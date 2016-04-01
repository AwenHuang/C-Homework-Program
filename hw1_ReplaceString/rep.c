#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
int main(int argc,char *argv[])
{
		int k;
		int c=0;
		char input[MAX];
		char *ptr;
		char *str;
		char *store;
		int find_len,replace_len,len;

	
		while(fgets(input,MAX,stdin))
		{
				store=(char *)malloc(sizeof(input));
				strcpy(store,input);//把字串存到陣列裡面
				if(argc==3)
				{
						ptr=strstr(store,argv[1]);//找尋要被取代的字出現的起始位址
						find_len=strlen(argv[1]);
						replace_len=strlen(argv[2]);
						k=0;
				}
				else if(argc==4)
				{
						if(strcmp(argv[1],"-i")==0)
						{
								ptr=strcasestr(store,argv[2]);
								find_len=strlen(argv[2]);
								replace_len=strlen(argv[3]);
								k=1;
						}
				}
				str=store;//還沒被取代的字串的位址
				len=strlen(store)+1;//原始字串長度
				printf("%d\n",strlen(store));
				char *result=(char *)malloc(sizeof(char) * len);//建立結果文字
				strcpy(result,store);//並複製原字串過去

				while(ptr != NULL)
				{

						c=c+(ptr-str);//目標字串前的長度(包括空白)
						result[c]='\0';//將空白變成字串結尾

						len=len+(find_len-replace_len);//更新字串長度
						result=(char *)realloc(result,sizeof(char) * len);//重新分配記憶體空間
                        
                        if(k==0)
								strcat(result,argv[2]);//把取代文字接在目前結果文字的後面
						else if(k==1)
						        strcat(result,argv[3]);
						

						c=c+replace_len;//更新偏移量
						store=ptr+find_len;//更新還沒被取代的字串的位址

						strcat(result,store);//把還沒被取代的字串接在結果後面
						if(k==0)
								ptr=strstr(store,argv[1]);//繼續往下找下一個字出現的位址
						else if(k==1)
								ptr=strcasestr(store,argv[2]);
				}
				printf("%s\n",result);
		}
		return 0;
}
	
								
			        	

								 		           		       
								 		           		          
								 		           		          


						


