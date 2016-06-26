
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
	struct nlist *next;
	char * name;
	char * defn;
};

#define HASHSIZE 101
struct nlist *lookup(char *);
char *strdup1(char *);
unsigned hash (char * s); 

static struct nlist *hashtab[HASHSIZE];
void undef(char * name);

unsigned hash (char * s) 
{
	unsigned hashval;
	
	for(hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;
	
	for(np = hashtab[hash(s)]; np != NULL; np = np->next)
		if(strcmp(s, np->name) == 0)
			return np;
		return NULL;
}

struct nlist *install(char * name, char * defn)
{
	struct nlist *np;
	unsigned hashval;
	
	if((np = lookup(name)) == NULL)
	{
		np = (struct nlist *)malloc(sizeof(*np));
		if(np == NULL || (np->name = strdup1(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}else
		free((void *)np->defn);
	
	if((np->defn = strdup1(defn)) == NULL)
		return NULL;
	return np;
}

void undef(char * name)
{ 
	if ((lookup(name)) != NULL)
	{
		struct nlist *head = hashtab[hash(name)];
		struct nlist *prev;
		
		if(head != NULL && strcmp(head->name, name) == 0)
		{
			hashtab[hash(name)] = head->next;
			free((void *)head);
			return;
		}
		
		while (head != NULL && strcmp(head->name, name) != 0)
		{
			prev = head;
			head = head->next;
		}
  
		// Unlink the node from linked list
		prev->next = head->next; 
		
		free((void *)head->defn);
		free((void *)head->name); 
		free((void *)head);
	}
}

char *strdup1(char *s) /*make a duplicate of s*/
{
	char *p;
	
	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}