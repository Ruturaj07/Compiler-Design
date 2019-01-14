#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char var1[100][100];
char var2[100][100];
char var3[100][100];


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
    int count=0,count1=0;
    char ch,buffer[15],operators[]="+-*/%+=";
    FILE*fp;
    int i,j=0;
	fp=fopen("inp.c","r");

	if(fp==NULL)
    {
        printf("error while opening the file\n");
        exit(0);
    }

	while((ch=fgetc(fp))!=EOF)
    {

        for(i=0;i<6;++i)
        {
            if(ch==operators[i]){}
           // printf("%c is operator\n",ch);
        }

        if(isalnum(ch)||ch=='('||ch==')')
        {
            buffer[j++]=ch;
        }

        else if((ch==' ' ||ch=='\n')&&(j!=0))
        {
            buffer[j]='\0';


            if(isKeyword(buffer)==1)
            {
                //printf("%s is keyword\n",buffer);

                strcpy(var1[count],buffer);
                strcpy(var2[count],"Keyword");
                strcpy(var3[count],"0");
                count++;

            }
            else
            {
		if(buffer[j-2]=='('&&buffer[j-1]==')'){

			strcpy(var2[count],"Procedure");
                    char temp[100];
                    strcpy(temp,buffer);
                    temp[j-2]='\0';
                    strcpy(var1[count],temp);
			strcpy(var3[count],(void*)&buffer);		
		}
		else{
            	strcpy(var2[count],"Identifier");
                strcpy(var1[count],buffer);
		strcpy(var3[count],(void*)&buffer);
                }
                count++;
            }

            j=0;
        }
    }
    fclose(fp);
    while(1){
	printf("Enter Choice:\n1.Display\n2.Lookup\n3.Delete\n4.Exit\n");
    int choice ;
    printf("Enter Choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        for(int i=0;i<count;i++){
        if(strcmp(var2[i],"Keyword")==0){
            printf("%s\t%s\t\t%s\n",var1[i],var2[i],var3[i]);
        }
        else{
            if(var1[i][0]!='\0')
            printf("%s\t%s\t%p\n",var1[i],var2[i],var3[i]);
        }
        }
        break;

        case 2:
        printf("Enter Identifier or Procedure name:");
        char tosearch[100];
        scanf("%s",tosearch);
        int found=-1;
        for(int i=0;i<100;i++){
            if(strcmp(var1[i],tosearch)==0){
                found=i;
            }
        }
        if(found==-1){
            printf("Not found" );
        }
        else{
            
            printf("%s\t%s\t\t%p\n",var1[found],var2[found],var3[found]);


        }
        break;

        case 3:
        printf("Enter Identifier or Procedure name:");
        char todel[100];
        scanf("%s",todel);
        int found1=-1;
        for(int i=0;i<100;i++){
            if(strcmp(var1[i],todel)==0){
                found1=i;
            }
        }
        if(found1==-1){
            printf("Not found" );
        }
        else{
            printf("deleted");
            var1[found1][0]='\0';
            var2[found1][0]='\0';
            memset(&var3[found1], 0, sizeof(var3[found1]));
        }
        break;

        case 4:
            exit(0);
        break;

    }
}
    
  /*  for(int i=0;i<count;i++){
	if(strcmp(var2[i],"Keyword")==0){
	        printf("%s\t%s\t\t%s\n",var1[i],var2[i],var3[i]);
	}
	else{
	        printf("%s\t%s\t%p\n",var1[i],var2[i],var3[i]);
	}

    }*/
    return 0;
}















