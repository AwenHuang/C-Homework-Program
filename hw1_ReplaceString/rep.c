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
				strcpy(store,input);//��r��s��}�C�̭�
				if(argc==3)
				{
						ptr=strstr(store,argv[1]);//��M�n�Q���N���r�X�{���_�l��}
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
				str=store;//�٨S�Q���N���r�ꪺ��}
				len=strlen(store)+1;//��l�r�����
				printf("%d\n",strlen(store));
				char *result=(char *)malloc(sizeof(char) * len);//�إߵ��G��r
				strcpy(result,store);//�ýƻs��r��L�h

				while(ptr != NULL)
				{

						c=c+(ptr-str);//�ؼЦr��e������(�]�A�ť�)
						result[c]='\0';//�N�ť��ܦ��r�굲��

						len=len+(find_len-replace_len);//��s�r�����
						result=(char *)realloc(result,sizeof(char) * len);//���s���t�O����Ŷ�
                        
                        if(k==0)
								strcat(result,argv[2]);//����N��r���b�ثe���G��r���᭱
						else if(k==1)
						        strcat(result,argv[3]);
						

						c=c+replace_len;//��s�����q
						store=ptr+find_len;//��s�٨S�Q���N���r�ꪺ��}

						strcat(result,store);//���٨S�Q���N���r�걵�b���G�᭱
						if(k==0)
								ptr=strstr(store,argv[1]);//�~�򩹤U��U�@�Ӧr�X�{����}
						else if(k==1)
								ptr=strcasestr(store,argv[2]);
				}
				printf("%s\n",result);
		}
		return 0;
}
	
								
			        	

								 		           		       
								 		           		          
								 		           		          


						


