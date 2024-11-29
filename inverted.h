//#ifndef INVERTED_INDEX_H
//#define INVERTED_INDEX_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define NOELEMENT -2
#define EMPTYLIST -3
#define REPEATED -4
#define FILE_EMPTY -5
#define NOT_PRESENT -6

#define SIZE 26
#define BUFF_SIZE 255
#define NAMELENGTH 50

//inverted table

typedef struct sub_node
{
	char f_name[NAMELENGTH];
	int w_count;
	struct sub_node *link;
}Slist_snode;

typedef struct node
{
	char word[NAMELENGTH];
	struct node *link;
	Slist_snode *sub_link;
	int f_count;
}Slist_mnode;
typedef struct file_node
{
    char f_name[NAMELENGTH];
    struct file_node *link;
}Slist;

/* File validation */
int read_validate(Slist **head,int argc,char *argv[]); 

/*Create DB*/
int create_DB(Slist_mnode *word[27],Slist *head);

/*Display*/
int display_DB(Slist_mnode *word[27]);
//int display_DB(Slist *head);

/*search */
int search_DB(Slist_mnode *word[27],char *str);

/*Save*/
int save_DB(Slist_mnode *word[27],char *str);

/*Update */
int update_DB(Slist **head1,Slist_mnode *word[27],char *str1);

//#endif



