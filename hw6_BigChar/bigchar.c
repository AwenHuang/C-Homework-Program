#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

void printA(int one[]);

int main(int argc,char *argv[])
{
		int c,i,j;
		int n=0,N=0,k=0,a=0;
		FILE *fp;
		
		int temp[8],one[576],store[4][12][12];
		
		fp = fopen(argv[1],"rb");

		while((c=fgetc(fp))!= EOF)
		{
				//printf("%x\n",c);
				n++;
				if(n<5)
						continue;
				else
				{
						for(i=0;i<8;i++)
						{
								if( (c & 1) == 0)
										temp[7-i]=' ';
								else 
										temp[7-i]='*';
								c >>=1;
						}
						for(i=0;i<8;i++)
						{
								one[N] = temp[i];
								N++;
						}
				}
		}
		N=0;
		for(k=0;k<4;k++)
		{
				for(i=0;i<12;i++)
				{
						for(j=0;j<12;j++)
						{
								store[k][i][j] = one[N++];
								printf("%c",store[k][i][j]);
				
						}
						printf("\n");
				}
		}
		char input[10];
		int memory[6];
		int len;
		printf("please input english character(<=6)\n");
		scanf("%s",input);
		len=strlen(input);
		if(len > 6)
		{
				printf("too much words!\n");
				return 0;
		}
				
		for(i=0;i<len;i++)
		{
				if(isdigit(input[i]) != 0 || input[i] > 'D')
				{
						printf("please input english character between A~D\n");
						return 0;
				}
						
				if(input[i] == 'A')
						memory[i] = 0;

			    else if(input[i] == 'B')
						memory[i] = 1;

				else if(input[i] == 'C')
						memory[i] = 2;

				else if(input[i] == 'D')
						memory[i] = 3;
		}

				for(i=0;i<12;i++)
				{
						if(len <= 6)
						{
								k = memory[0];
								for(j=0;j<12;j++)
										printf("%c",store[k][i][j]);
						}
						if(len >= 2 && len <= 6)
						{
								k = memory[1];
								for(j=0;j<12;j++)
										printf("%c",store[k][i][j]);
						}
						if(len >= 3 && len <= 6)
						{
								k = memory[2];
								for(j=0;j<12;j++)
										printf("%c",store[k][i][j]);
						}
						if(len >= 4 && len <= 6)
						{
								k = memory[3];
								for(j=0;j<12;j++)
										printf("%c",store[k][i][j]);
						}
						if(len >= 5 && len <= 6)
						{
								k = memory[4];
								for(j=0;j<12;j++)
										printf("%c",store[k][i][j]);
						}
						if(len == 6)
						{
								k = memory[5];
								for(j=0;j<12;j++)
										printf("%c",store[k][i][j]);
						}
						
				printf("\n");
						
						
				}
		return 0;
}

		


