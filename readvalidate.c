
#include <stdlib.h>
#include <string.h>
#include"inverted.h"
int read_validate(Slist **head,int argc,char *argv[])
{

    int i;
    for(i=1;i<argc;i++)
    {
	if(strstr(argv[i],".txt"))
	{
	    FILE *fptr=fopen(argv[i],"r");
	    if(fptr!=NULL)
	    {
		fseek(fptr,0,SEEK_END);
		if(ftell(fptr))
		{

		    Slist *new=malloc(sizeof(Slist));
		    strcpy(new->f_name,argv[i]);
		    new->link=NULL;
		    Slist *temp=*head;
		    Slist *prev=*head;
		    if(*head==NULL)
		    {
			*head=new;
			printf("%s File is inserted Successfully\n",argv[i]);  
		    }
		    else
		    {
			int flag=1;
			while(temp)
			{
			    if(strcmp(temp->f_name,argv[i])==0)
			    {
				flag=0;
				break;
			    }
			    else
			    {
				prev=temp;
				temp=temp->link;
			    }
			}
			if(flag==1)
			{
			    printf("%s File is inserted successfully\n",argv[i]);
			    prev->link=new;
			}
			else
			{
			    flag=1;
			}
		    }
		}
		else
		{

		    printf("%s File is Empty\n",argv[i]);
		}
	    }
	    else
	    {
		printf("%s File is not created\n",argv[i]);
	    }
	}
	else
	{

	    printf("%s is not txt file\n",argv[i]);
	}
    }
    return SUCCESS;
}



