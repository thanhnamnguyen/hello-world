#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
int n, g, k;
FILE *fp;

struct node
{
  int value;
  struct node* next;
};
typedef struct node node;
node ** table;
int *guess; 
void in_maze(int a, int b)
{
  if(table[a]== NULL)
    {
      table[a]= malloc(sizeof(node));
      table[a]->value=b;
      table[a]->next= NULL;
    }
  else
    {
      node* temp;
      temp= table[a];
      while(temp->next != NULL)
	{
	  temp= temp->next;
	}
      temp->next= malloc(sizeof(node));
      temp->next->value= b;
      temp->next->next= NULL;
    }
}

void input()
{
  int a,  b;
  fscanf(fp, "%d", &n);
  table= malloc(n*sizeof(node*));
  for(int i=0; i<n-1; i++)
    {
      fscanf(fp, "%i %i",&a, &b);
      in_maze(a, b);
      in_maze(b, a);
    }
  fscanf(fp, "%d %d", &g, &k);
  guess= malloc(n*sizeof(int));
  for(int i=0; i<g; i++)
    {
      fscanf(fp, "%i %i",&a, &b);      
      guess[a]=b; 
    }
}

void print()
{
  node* temp= table[1];
  while(temp != NULL)
    {
      printf("1: %i\n", temp->value);
      temp=temp->next;
    }
  printf("\n");
  for(int i=0; i<n; i++)
    {
      printf("%i - %i\n",i, guess[i]);
    }
  printf("\n\n");
}

int main()
{
  fp = fopen( "Downloads/input00.txt" , "r");
  int q;
  fscanf(fp, "%d", &q);

  for(int i=0;i<q; i++)
    {
      input();
      print();
      free(guess);
    }
   
  fclose(fp);
}
