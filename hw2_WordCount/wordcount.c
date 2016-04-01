#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

int getword(char s[],int lim)
{
		int c,i;
		i=0;
		while(--lim>0 && (c=getchar())!=EOF)
		{
				if(c==' ' || c=='\n'|| c=='\t')
						break;
				else
						s[i++]=c;
		}
		if(i>0)
		{
				s[i]='\0';
				return i;
		}
		else if(i==0 && c!=EOF)//���ť�
		{
				return 0;
		}
		else if(c==EOF)
		{
				return -1;
		}

}
int compare(const void *a,const void *b)
{
		return(strcmp(*(char**)a,*(char**)b));
}
int main()
{
		int i,n,count;
		n=0;
		count=1;//�I��@�Ӧr�N�O1��
		char word[MAX];
		char *wordarray[MAX];
		int t;
		while((t=getword(word,MAX))>=0) 
		{
				if(t>0)
						wordarray[n++]=strdup(word);//strdup:�۰������Ш̷ӫŧi���r�����t�O����Ŷ��A�åB�^�ǩҤ��t����m������
		}
		if(n>1)//�W�L�@�Ӧr
		{
				qsort(wordarray,n,sizeof(char *),compare);//�ϥ�qsort()�ƦC�A��@�˪��r�Ʀb�@�_
		}
		else if(n==1)//�u���@�Ӧr
		{
				printf("%d\t%s\n",n,wordarray[0]);
		}

		for(i = 0;i < n - 1;i++)
		{
				if(strcmp(wordarray[i],wordarray[i + 1]) == 0 && i == n - 2)//�̫��Ӧr�@�˪���
				{
						printf("%d\t%s\n",count + 1,wordarray[i]);//�L�X�˼ƲĤG�Ӧr��2
						count = 1;
				}
				else if(strcmp(wordarray[i],wordarray[i + 1]) != 0 && i == n - 2)//�̫��Ӧr���@�˪���
				{
						printf("%d\t%s\n",count ,wordarray[i]);//�L�X�ثecount��(�]�N�O�˼ƲĤG�Ӧr���Ӽ�)
						printf("1\t%s\n",wordarray[i + 1]);//�L�X�̫�@�Ӧr��1
						count =1;
				}
				else if(strcmp(wordarray[i],wordarray[i + 1]) == 0)
						count++;
				else
				{
						printf("%d\t%s\n",count,wordarray[i]);
						count = 1;
				}
		}
		return 0;
}



						
