#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

int getword(char *, int);
int isVariable(char * variable);
char *strdup1(char *s, int size); /*make a duplicate of s*/

/* Node for a Tree */
struct tnode {
	char *word;
	struct tnode *left;
	struct tnode *right;
};
void treeprint(struct tnode *p);
struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);

/* Node for a linked list
 containing a tree */
struct lnode {
	struct tnode *root;
	char *variable;
	struct lnode *next;
};
struct lnode * listContains(char *variable, struct lnode *ptr, int num);
void printList();
void addList(char *variable, int num);

/*make a duplicate of s to specific size*/
char *strdup1(char *s, int size) 
{
	char *p;
	
	p = (char *) malloc(size + 1);
	if (p != NULL)
	{
		strncpy(p, s, size);
		p[size] = '\0';
	}
	return p;
}

/* Head of link list */
struct lnode *root = NULL;        

int main(int argc, char *argv[])
{
	
	if(argc < 2)
	{
		printf("Please enter a number.\n");
		exit(0);
	}
	char word[MAXWORD]; 

	int num = atoi(argv[1]);
	
	while(getword(word, MAXWORD) != '1')
		if(isVariable(word)) 
		{
			char variable[MAXWORD];
			getword(variable, MAXWORD);
			if(strlen(variable) > num)
			{
				struct lnode *ptr = root;        
				ptr = listContains(variable, ptr, num);
				if(ptr != NULL)
					ptr->root = addtree(ptr->root, variable);
				else
					addList(variable, num);
			}
			printf("Variable is %s\n", variable);
		}
		
		printList(root);
		
	return 0;
}

/* Add variable to list */
void addList(char *variable, int num) 
{
	struct lnode *conductor;   

	conductor = malloc( sizeof(struct lnode) );  

	conductor->variable = strdup1(variable, num);
	conductor->root = NULL;
	conductor->root = addtree(conductor->root, variable);

	conductor->next = root;
	root = conductor;
}

/* Print list of variables */
void printList()
{
	struct lnode *ptr = root;
	while(ptr != NULL) 
	{
		printf("Root word is %s\n", ptr->variable);
		treeprint(ptr->root);
		ptr = ptr->next;
	}
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s\n", p->word);
		treeprint(p->right);
	}
}

/* A very simple function to check if a string is a variable */
int isVariable(char * variable)
{
	if(strcmp(variable, "int") == 0 || strcmp(variable, "char") == 0 || strcmp(variable, "float") == 0
		|| strcmp(variable, "double") == 0 || strcmp(variable, "long") == 0 || strcmp(variable, "short") == 0)
		return 1;
	
	return 0;
}
/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if(p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->left = p->right = NULL;
	}
	else if (cond = strcmp(w, p->word) < 0)
		p->left = addtree(p->left , w);
	else
		p->right = addtree(p->right, w);
	return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while(isspace(c = getch()))
		;

	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}

	for( ; --lim > 0; w++)
		if(!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}


/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

struct lnode * listContains(char *variable, struct lnode *ptr, int num)
{
	char temp[num + 1];
	strncpy(temp, variable, num);
	temp[num] = '\0';

	while(ptr != NULL) 
	{
		if(strcmp(ptr->variable, temp) == 0)
				return ptr;
		ptr = ptr->next;
	}
	return NULL;
}
