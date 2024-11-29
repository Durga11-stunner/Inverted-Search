
#include "inverted.h"
int create_DB(Slist_mnode *word[27],Slist *head)
{
    Slist *temp=head;
    int flag2=1;
    while(temp)
    {
	FILE *fptr=(fopen(temp->f_name,"r"));
	char buffer[BUFF_SIZE];
	while(fscanf(fptr,"%s",buffer)!=EOF)
	{
	    int key=(toupper(buffer[0]))%65;
	    if(key<0||key>26)
	    {
		key=26;
	    }
	    Slist_mnode *m_node=malloc(sizeof(Slist_mnode));
	    Slist_snode *s_node=malloc(sizeof(Slist_snode));
	    if(m_node==NULL)
	    {
		return FAILURE;
	    }
	    else
	    {
		strcpy(m_node->word,buffer);
		m_node->f_count=1;
		m_node->link=NULL;
		m_node->sub_link=s_node;
	    }
	    if(s_node==NULL)
	    {
		return FAILURE;
	    }
	    else
	    {
		s_node->w_count=1;
		strcpy(s_node->f_name,temp->f_name);
		s_node->link=NULL;
	    }
	    if(word[key]==NULL)
	    {
		word[key]=m_node;
	    }
	    else if(word[key]!=NULL)
	    {
		Slist_mnode *m_temp=word[key];
		int flag=1;
		Slist_mnode *prev=word[key];
		while(m_temp)
		{
		    if(strcmp(m_temp->word,buffer)==0)
		    {
			flag=0;
			break;
		    }
		    else
		    {
			prev=m_temp;
			m_temp=m_temp->link;
		    }
		}
		if(flag==1)
		{
		    prev->link=m_node;
		}
		else
		{
		    Slist_snode *n_temp=m_temp->sub_link;
		    Slist_snode *pretemp=m_temp->sub_link;
		    int flag1=1;
		    while(n_temp)
		    {
			if(strcmp(n_temp->f_name,temp->f_name)==0)
			{
			    flag1=0;
			    break;
			}
			else
			{
			    pretemp=n_temp;
			    n_temp=n_temp->link;
			}
		    }
		    if(flag1==0)
		    {
			n_temp->w_count++;
		    }
		    else
		    {
			pretemp->link=s_node;
			m_temp->f_count++;
		    }
		}
	    }
	}
	flag2=0;
	temp=temp->link;
    }
    temp=head;
    if(flag2==1)
    {
	return FAILURE;
    }
    else
    {
	return SUCCESS;
    }
}

