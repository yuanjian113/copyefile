#include<stdio.h>

int main(int argc,char*argv[])
{
	FILE *srcFile=0,*desFile=0;
	int ch = 0;
	if(argc!=3)
	{
		printf("usage:%s srcfilename destfilename\n",argv[0]);
	}
	else
	{
		if((srcFile = fopen(argv[1],"r+"))==0)
		{
			printf("Can not open source file\"%s\"!",argv[1]);
		}
		else if((desFile=fopen(argv[2],"a+"))==0)
		{
			printf("Can not open destination file\"%s\"!",argv[2]);
			fclose(srcFile);
		}
		else
		{
			while((ch = fgetc(srcFile))!=EOF)
				fputc(ch,desFile);
			printf("Successful to copy a file!\n");
			fclose(srcFile);
			fclose(desFile);
			return 1;		
		}
	}
	return 0;
}