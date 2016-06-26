#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

/* Only works when sentences are end with a . */
/* Example : 
saad ahmed is a coder.
yes man this is example.
what the hell.
lol no worries.
worries is bad.
phantom pain.
metal gear.
yes phantom pain.
*/

/* Node for a linked list
 containing line numbers */
struct lnode {
	int lineno;
	struct lnode *next;
};

struct tnode {
	struct lnode *root;
	char *word;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);
char *strdup1(char *s); /*make a duplicate of s*/

void printlist(struct lnode *root);

int newline = 1;
/* Word frequency count */
int main()
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while(getword(word, MAXWORD) != '1')
		if(isalpha(word[0]))
			root = addtree(root, word, newline);
	treeprint(root);
	return 0;
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
struct tnode *addtree(struct tnode *p, char *w, int lineno)
{
	int cond;

	if(p == NULL) {
		p = talloc();
		p->word = strdup1(w);
		p->root = malloc(sizeof(struct lnode));
		p->root->lineno = lineno;
		p->root->next = NULL;
		p->left = p->right = NULL;
	} else if((cond = strcmp(w, p->word)) == 0)
	{
		struct lnode *ptr = p->root;
		
		while(ptr->next != NULL)
			ptr = ptr->next;
		
		struct lnode *conductor = malloc(sizeof(struct lnode));
		conductor->lineno = lineno;
		conductor->next = NULL;
		ptr->next = conductor;
	}
	else if (cond < 0)
		p->left = addtree(p->left , w, lineno);
	else
		p->right = addtree(p->right, w, lineno);
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("Word: %s\n", p->word);
		
		printf("On lines: ");
		printlist(p->root);
		treeprint(p->right);
	}
}

/* Print list of line nos */
void printlist(struct lnode *root)
{
	struct lnode *ptr = root;
	while(ptr != NULL) 
	{
		printf("%d ", ptr->lineno); 
		ptr = ptr->next;
	}
	printf("\n");
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	c = getch();
	if (c == '\n' || c == '\r')
	{
		newline++;
		printf("On line %d\n", newline);
	}else
		ungetch(c);
	while(isspace(c = getch()))
		;

	if (c != EOF)
		*w++ = c;
	
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}

	for( ; --lim > 0; w++)
		if(!isalnum(c = *w = getch())) {
			if(c != '.')
				ungetch(*w);
			break;
		}
	*w = '\0'; 
	
	return word[0];
}