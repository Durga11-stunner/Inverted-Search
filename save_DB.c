
#include <stdio.h>
#include "inverted.h"
int save_DB(Slist_mnode *word[27],char *str)
{
    int flag=1;
    FILE *fptr=(fopen(str,"w"));
    if(fptr!=NULL)
    {
	int i;
	for(i=0;i<27;i++)
	{
	    Slist_mnode *m_temp=word[i];
	    while(m_temp)
	    {
	        fprintf(fptr,"#");
		fprintf(fptr,"%d",i);
		fprintf(fptr,";"); 
		fprintf(fptr,"%s",m_temp->word);
		fprintf(fptr,";"); 
		fprintf(fptr,"%d",m_temp->f_count);
		fprintf(fptr,";"); 
		Slist_snode *n_temp=m_temp->sub_link;
		while(n_temp)
		{
		    fprintf(fptr,"%s",n_temp->f_name);
		    fprintf(fptr,";"); 
                    fprintf(fptr,"%d",n_temp->w_count);
                    fprintf(fptr,";"); 
		    n_temp=n_temp->link;
		}
	            fprintf(fptr,"#");
	            fprintf(fptr,"\n");
		m_temp=m_temp->link;
	    flag=0;
	    }
	}
    }
    else
    {
	printf("Failure : Enter valid file name\n");
	return FAILURE;
    }
    if(flag==0)
    {
        return SUCCESS;
    }
    else
    {
	return FAILURE;
    }
}


