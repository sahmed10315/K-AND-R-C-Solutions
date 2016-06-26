#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

int size(struct tnode* node); 
struct tnode *addtree(struct tnode *, char *);
void savetree(struct tnode *, struct tnode *);
int getword(char *, int);
int compare (const void *, const void *);

/* Word frequency count in decreasing order of occurence */
int main()
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while(getword(word, MAXWORD) != '1')
		if(isalpha(word[0]))
			root = addtree(root, word);
	int s = size(root);
	
	struct tnode keys[s];

	savetree(root, keys);
	
	qsort (keys, s, sizeof(struct tnode), compare);

	for (int n=0; n<s; n++)
		printf ("word = %s count = %d \n",keys[n].word, keys[n].count);          
   
	return 0;
}

int compare (const void * a, const void * b)
{

  struct tnode *nodeA = (struct tnode *)a;
  struct tnode *nodeB = (struct tnode *)b;

  return ( nodeB->count - nodeA->count );
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup1(char *s) /*make a duplicate of s*/
{
	char *p;
	
	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if(p == NULL) {
		p = talloc();
		p->word = strdup1(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left , w);
	else
		p->right = addtree(p->right, w);
	return p;
}

/* Computes the number of nodes in a tree. */
int size(struct tnode* node) 
{  
  if (node==NULL) 
    return 0;
  else    
    return(size(node->left) + 1 + size(node->right));  
}

/* savetree: in-order save tree in array of structs */
void savetree(struct tnode *p, struct tnode keys[])
{
	static int i = 0;
	if (p != NULL) {
		savetree(p->left, keys);
		keys[i].count = p->count;
		keys[i++].word = strdup1(p->word);
		savetree(p->right, keys);
	}
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
	printf("\n%s\n", word);
	return word[0];
}


