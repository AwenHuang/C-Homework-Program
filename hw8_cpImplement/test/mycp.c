#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#define MAX 1000
int main(int argc,char *argv[])
{
		int i;

		int comd_o=0,comd_s=0,n=0;
		char choose;
		char *ptr;
		char *file[MAX];
		char temp[MAX],line[MAX];
		FILE *targetfp,*fp;
		DIR *targetdir,*test;

		for(i=1;i<argc;i++)
		{
				if(argv[i][0] == '-')
				{
						switch(argv[i][1])
						{
								case 'o':comd_o++;break;
								case 's':comd_s++;break;
						}
				}
				if(argv[i][0] != '-')
				{
						file[n] = (char *)malloc(100);
						strcpy(file[n],argv[i]);
						n++;
				}
		}

		for(i=0;i<n-1;i++)
		{
				test = opendir(file[i]);
				if(test != NULL)
				{
						printf("%s is a directory!\n",file[i]);
						return 0;
				}
		}
		
		strncpy(temp,file[n-1],strlen(file[n-1]));
		
		/*if(temp[strlen(file[n-1])-1] != '/')
				temp[strlen(file[n-1])] = '/';*/

		targetdir = opendir(temp);

		if(targetdir == NULL)//最後一個不是資料夾
		{
				if(n == 2)
				{
						fp = fopen(file[0],"r");
						if(fp == NULL)
						{
								printf("No file:%s\n",file[0]);
								return 0;
						}
						
						targetfp = fopen(file[1],"r");
						if(targetfp != NULL)// 檔案已存在
						{
								fclose(targetfp);
								if(comd_o == 0 && comd_s == 0)//判斷是否直接覆蓋或者直接跳過
								{
										printf("file %s is already exist\n",file[1]);
										printf("overwrite or not?(y/n)");
										scanf("%c",&choose);
										if(choose == 'n')
												return 0;
								}

								choose = 0;
								// 跳出if 表示選擇y 
								targetfp = fopen(file[1],"w");
								
								if(targetfp == NULL)
								{
										printf("Error\n");
										return 0;
								}
						}
						else // 檔案不存在，用新建+寫入的模式開啟檔案
						{
								targetfp = fopen(file[1],"w");
								if(targetfp == NULL)
								{
										printf("error!\n");
										return 0;
								}
						}
						while(fgets(line,MAX,fp))
								fprintf(targetfp,"%s",line);// 把file[0]的內容印到file[1]
				}
				else
				{
						printf("too many files,and the %s is not a directory\n",file[n-1]);
						return 0;
				}
		}
		else // 最後一個是資料夾
		{
				/*if(file[n-1][strlen(file[n-1])-1] != '/')
						file[n-1][strlen(file[n-1])] = '/';*/

				for(i=0;i<n-1;i++)
				{
						//ptr = strstr(file[i],"/");
						/*while(ptr != NULL)
						{
								ptr = strstr(file[i],"/");
						}
						
						
						ptr = ptr+1;*/
						
						//printf("%d\n",ptr);
						char path[MAX];
						sprintf(path,"%s%s",file[n-1],file[i]);

						fp = fopen(file[i],"r");
						if(fp == NULL)
						{
								printf("No file:%s\n",file[i]);
								return 0;
						}
						test = opendir(path);
						if(test != NULL)
						{
								printf("%s is already in the directory %s\n",file[n-1],file[i]);
								return 0;
						}
						targetfp = fopen(path,"r");
						if(targetfp != NULL)
						{
								fclose(targetfp);
								if(comd_o == 0 && comd_s == 0)
								{
										printf("file %s is already exist\n",file[i]);
										printf("overwrite or not?(y/n)\n");
										scanf("%c",&choose);
										getchar();
										if(choose == 'y')
												targetfp = fopen(path,"w");
								}
								else
								{
										if(comd_s == 1)
												return 0;
										targetfp = fopen(path,"w");
								}
								choose = 0;
						}
						else//資料夾內的檔案不存在，直接用新增寫入的模式
								targetfp = fopen(path,"w");
						
						if(targetfp != NULL)
						{
								while(fgets(line,MAX,fp))
										fprintf(targetfp,"%s",line);
						}
				}
		}
		return 0;
}
				
			





