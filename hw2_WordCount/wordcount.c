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
		else if(i==0 && c!=EOF)//找到空白
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
		count=1;//碰到一個字就是1個
		char word[MAX];
		char *wordarray[MAX];
		int t;
		while((t=getword(word,MAX))>=0) 
		{
				if(t>0)
						wordarray[n++]=strdup(word);//strdup:自動幫指標依照宣告的字元分配記憶體空間，並且回傳所分配的位置的指標
		}
		if(n>1)//超過一個字
		{
				qsort(wordarray,n,sizeof(char *),compare);//使用qsort()排列，把一樣的字排在一起
		}
		else if(n==1)//只有一個字
		{
				printf("%d\t%s\n",n,wordarray[0]);
		}

		for(i = 0;i < n - 1;i++)
		{
				if(strcmp(wordarray[i],wordarray[i + 1]) == 0 && i == n - 2)//最後兩個字一樣的話
				{
						printf("%d\t%s\n",count + 1,wordarray[i]);//印出倒數第二個字為2
						count = 1;
				}
				else if(strcmp(wordarray[i],wordarray[i + 1]) != 0 && i == n - 2)//最後兩個字不一樣的話
				{
						printf("%d\t%s\n",count ,wordarray[i]);//印出目前count數(也就是倒數第二個字的個數)
						printf("1\t%s\n",wordarray[i + 1]);//印出最後一個字為1
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



						
