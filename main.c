
#include "inverted.h"
int main(int argc,char *argv[])
{
    int flag=1;
    int flag2=1;
    //array of pointers 
    Slist_mnode *word[27];
    //assigning null to array of pointer
    for(int i=0;i<27;i++)
    {
	word[i]=NULL;
    }
    //initialize head for creating for ingle list 
    Slist *head=NULL;
    Slist *head1=NULL;
    int opt;
    int res;
    //super loop
    while(1)
    {
	printf("1.Create Database\n""2.Display Database\n""3.Search Database\n""4.Update Database\n""5.Save Database\n""6.Exit\n");
	printf("Enter the option\n");
	scanf("%d",&opt);
	switch(opt)
	{
	    //for create data base
	    case 1:
		{
		    if(argc==1)
		    {
			printf("Info : Please pass arguments through command line\n");
			printf("Info : please pass 2 arguments through command line\n");
		    }
		    else
		    {
			res=read_validate(&head,argc,argv);
			if(res==SUCCESS)
			{
			    if(head==NULL)
			    {
				printf("Error : Head is NULL file is not added\n");
			    }
			    else
			    {

				printf("Success : Read and validation is success\n");
			    }
			}
		    }
		    if(flag2==0)
		    {
			Slist *temp2=head1;
			Slist *prev=head1;
			while(temp2)
			{
			Slist *temp1=head;
			    while(temp1)
			    {
				if(strcmp(temp1->f_name,temp2->f_name)==0)
				{
				    if(strcmp(temp1->f_name,head->f_name)==0)
				    {
					head=temp1->link;
					free(temp1);
					temp1=head->link;
				    }
				    else
				    {
					prev->link=temp1->link;
					free(temp1);
					temp1=prev->link;
				    }


				}
				else
				{
				    prev=temp1;
				    temp1=temp1->link;
				}
			    }
			    temp2 = temp2 -> link;
			}
			Slist *temp3=head;
			while(temp3)
			{
			    printf("%s\n",temp3->f_name);
			    temp3=temp3->link;
			}

		    }
		    if(flag2==1)
		    {		    
			res=create_DB(word,head);
		    }
		    else
		    {
			res=create_DB(word,head);
		    }
		    if(res==SUCCESS)
		    {
			printf("Success : data base is created\n");
			flag=0;
		    }
		    else
		    {
			printf("Failure : data base is not created\n");
		    }
		    break;
		}
	//for display data base
	case 2:
	res=display_DB(word);
	if(res==SUCCESS)
	    printf("Success : data base display is successfull\n");
	else
	    printf("Failure : data base display is failure\n");
	break;
        //for search data base
	case 3:
	{
	    char str[100];
	    scanf("%s",str);
	    printf("Enter data to search\n");
	    res=search_DB(word,str);
	    if(res==SUCCESS)
	    {
		printf("%s is found in database\n",str);
	    }
	    else
	    {
		printf("%s is not found in database\n",str);
	    }
	    word[26]=NULL;
	    break;
	}
	//for save data base
	case 5:
	{
	    char str[100];
	    printf("Enter file name\n");
	    scanf("%s",str);
	    res=save_DB(word,str);
	    if(res==SUCCESS)
	    {
		printf("Data base is save\n");
	    }
	    else
	    {
		printf("Data base is not save\n");
	    }
	    word[26]=NULL;
	    break;
	}
	//for  update data base
	case 4:

	if(flag==1||argc==1)
	{
	    char str1[50];
	    printf("Enter file name\n");
	    scanf("%s",str1);
	    res=update_DB(&head1,word,str1);
	    if(res==SUCCESS)
	    {
		printf("Info : updated data base successfully\n");
	    }
	    else
	    {
		printf("Failure : updated data base failure\n");
	    }
	    flag2=0;
	}
	else
	{
	    printf("Info : you can not update data base after create data base\n");
	}
	//	word[26]=NULL;
	break;
        //for exit
	case 6:
	exit(1);
	break;
    }
}
}

