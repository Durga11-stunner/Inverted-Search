
#include "inverted.h"
int search_DB(Slist_mnode *word[27],char *str)
{
    int key=toupper(str[0])%65;
    if(key < 0 || key > 25)
	key = 26;
    Slist_mnode *temp=word[key];
    int flag=0;
    if(word[key]!=NULL)
    {
	while(temp)
	{
	    if(strcmp(str,temp->word)==0)
	    {
		flag=1;
		printf("Word : %s Filecount : %d ",temp->word,temp->f_count);
		Slist_snode *temp2=temp->sub_link;
		while(temp2)
		{
		    printf("Wordcount : %d Filename : %s ",temp2->w_count,temp2->f_name);
		    temp2=temp2->link;
		}
	    }
	    temp=temp->link;
	    putchar('\n');
	   
	}
    }
    if(flag==0)
    {
	return FAILURE;
    }
    else
    {
	return SUCCESS;
    }
}



