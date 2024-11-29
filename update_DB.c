#include"inverted.h"
int update_DB(Slist **head1, Slist_mnode *word[27],char *str1)
{
    FILE *fptr=(fopen(str1,"r"));
    char buffer[500];
    char fname[100];
    int key,i;
    Slist *temp = *head1, *prev = NULL;
    if(fptr!=NULL)
    {
	while( fscanf(fptr,"%[^\n] ",buffer) != EOF )
	{  
	    //printf("%s\n",buffer);
	    char *token=strtok(buffer,"#;");
	    key=atoi(token);
	    // printf("%d ",key);
	    Slist_mnode *m_node=malloc(sizeof(Slist_mnode));
	    {
		strcpy(m_node->word,strtok(NULL,"#;"));
		m_node->f_count=atoi(strtok(NULL,"#;"));
		m_node->sub_link=NULL;
		m_node->link=NULL;
		for(i=0;i<m_node->f_count;i++)
		{
		    Slist_snode *n_node=malloc(sizeof(Slist_snode));
		    strcpy(fname,strtok(NULL,"#;"));
		    //printf("filename --- %s\n", fname);
		    strcpy(n_node->f_name,fname);
		    n_node->w_count=atoi(strtok(NULL,"#;"));
		    n_node->link=NULL;
		    Slist *new=malloc(sizeof(Slist));
		    strcpy(new->f_name,fname);
		    new->link=NULL;
		    if(*head1==NULL)
		    {
			*head1=new;
		    }
		    else
		    {
			int flag=1;
			temp = *head1;
			while(temp)
			{
			    if(strcmp(temp->f_name,fname)==0)
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
			    prev->link=new;
			}
			else
			{
			    flag=1;
			}
		    }
		    /*else
		      {
		      Slist *temp=*head1;
		      while(temp->link)
		      {
		      temp=temp->link;
		      }
		      temp->link=new;
		      }*/
		    if(m_node->sub_link==NULL)
		    {
			m_node->sub_link=n_node;
		    }
		    else
		    {
			Slist_snode *stemp=m_node->sub_link;
			while(stemp->link!=NULL)
			{
			    stemp=stemp->link;
			}
			stemp->link=n_node;
		    }
		}
	    }
	    if(word[key]==NULL)
	    {
		word[key]=m_node;
	    }
	    else
	    {
		Slist_mnode *temp=word[key];
		while(temp->link!=NULL)
		{
		    temp=temp->link;
		}
		temp->link=m_node;
	    }

	}

    }
    else
    {
	printf("INFO : PLEASE ENTER VALID FILE\n");
	return FAILURE;
    }
    /*Slist *temp1=*head1;
    while(temp1)
    {
	printf("%s\n",temp1->f_name);
	temp1=temp1->link;
    }*/
    fclose(fptr);
    return SUCCESS;



}


