#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char buffer[])
{
char keywords [32][10]={"auto","break","case","char","const","continue","default",
                        "do","double","else","enum","extern","float","for","goto",
                        "if","int","long","register","return","short","signed",
                         "sizeof","static","struct","switch","typedef","union",
                         "unsigned","void","volatile","while"};
int i,flag=0;
for(i=0;i<32;i++)
{
	if(strcmp(keywords[i],buffer)==0)
{
flag=1;
break;
}
}
return flag;
}

int main()
{
			char ch,buffer[15],operators[]="+-*/%=";
			FILE*fp;
			int i,j=0;
				fp=fopen("program.txt","r");
				if(fp==NULL)
			{
				printf("error while opening the file\n");
				exit(0);
			}

			while((ch=fgetc(fp))!=EOF)
			{
		//	printf("%c\n",ch );
				int flag1 = 0;
			for(i=0;i<6;i++)
			{
			if(ch==operators[i]){
				printf("%c is operator\n",ch);
				flag1=1;
			}
			
			}
			if(ch==';')
				flag1=1;

			if(isalnum(ch)&&flag1!=1)
			{
			//printf("*%c*\n",ch );
			buffer[j]=ch;
			j=j+1;
		//	printf("%s\n",buffer);
			}
			else if((ch==' ' ||ch=='\n'||flag1==1)&&(j!=0))
			{
		//	printf("elif");
				buffer[j]='\0';
				j=0;
				if(isKeyword(buffer)==1)
				printf("%s is keyword\n",buffer);
				else
				printf("%s is identifier\n",buffer);
			}

			}
			fclose(fp); 
			return 0;
}















