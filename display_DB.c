
#include "inverted.h"
int display_DB(Slist_mnode *word[27])
{
    int i,flag=1;
    //run loop 26 timwes
    for(i=0;i<27;i++)
    {
	//checking weather word of 
	if(word[i]!=NULL)
	{
	    flag=0;
	    Slist_mnode *m_temp=word[i];
	    Slist_snode *s_temp=m_temp->sub_link;
	    while(m_temp)
	    {
		printf("Word : %s   Present in  %d Files ",m_temp->word,m_temp->f_count);
		//Slist_snode *s_temp=m_temp->sub_link;
		s_temp=m_temp->sub_link;
		while(s_temp)
		{
		    printf(" Word Present  %d Times in file  %s ",s_temp->w_count,s_temp->f_name);
		    s_temp=s_temp->link;
		}
		putchar('\n');
		m_temp=m_temp->link;
	    }
	}
    }
    if(flag==1)
    {
	return FAILURE;
    }
    else
       return SUCCESS;	
}

