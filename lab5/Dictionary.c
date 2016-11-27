// Dictionary.c
// Shaan Saini
// shksaini
// lab5
// C Source file for testing the Dictionary ADTs


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "Dictionary.h"

typedef struct Node{
  int key;
  int value;
  struct Node* next;
} Node;

typedef Node* NodeRef;

struct Dictionary{
  NodeRef front;
  int numItems;
}Dictionary;

NodeRef newNode(int x, int y){
  NodeRef N = malloc(sizeof(Node));
  assert(N!=NULL);
  N->key = x;
  N->value = y;
  N->next = NULL;
  return(N);
}

void freeNode(NodeRef* pN){
  if(pN!=NULL && *pN!=NULL){
    free(*pN);
    *pN = NULL;
  }
}

DictionaryRef newDictionary(void){
  DictionaryRef D = malloc(sizeof(Dictionary));
  assert(D!=NULL);
  D->front = NULL;
  D->numItems = 0;
  return D;
}

void freeDictionary(DictionaryRef* pD){
  free(*pD);
  *pD = NULL;
}

int isEmpty(DictionaryRef D){
  if( D == NULL){
    fprintf(stderr,"Stack Error: calling isEmpty() on NULL StackRef\n");
    exit(EXIT_FAILURE);
  }
  return(D->numItems==0);
}

int size(DictionaryRef D){
  return(D->numItems);
}

int lookup(DictionaryRef D, int k){
  NodeRef N=D->front;
  while(N != NULL){
    if(N->key == k){
      return N->value;
    }
    N = N->next;
  }
  return UNDEF;
}

void insert(DictionaryRef D, int x, int y){
  NodeRef N=D->front;
  if(D==NULL){
    fprintf(stderr, "Stack Error: calling insert() on NULL StackRef\n");
    exit(EXIT_FAILURE);
  }
  else if(lookup(D,y)!=UNDEF){
    fprintf(stderr, "Stack Error: inserting dublicate key\n");
    exit(EXIT_FAILURE);
  }
  else{
    if(D->front == NULL){
      N = newNode(x,y);
      D->front = N;
      D->numItems++;
    }
    else{
      while(N!= NULL){
	if(N->next==NULL){
	  break;
	}
	N = N->next;
      }
      N->next = newNode(x,y);
      D->numItems++;
    }
  }
}

void delete(DictionaryRef D, int k){
  NodeRef N = D->front;
  if(D==NULL){
    fprintf(stderr, "Stack Error: calling delete() on NULL StackRef\n");
    exit(EXIT_FAILURE);
  }
  else if(lookup(D,k)==UNDEF){
    fprintf(stderr, "Stack Error: deleting non-existant key\n");
    exit(EXIT_FAILURE);
  }
  else{
    if(D->numItems<=1){;
      freeNode(&N);
    }
    else{
      if(N->key==k){
	NodeRef temp = D->front; 
	D->front = N->next;
	D->numItems--;
	freeNode(&temp);
      }
      else{
	while(N->next->key!=k){
	  N = N->next;
	}
	NodeRef temp =  N->next;
	N->next = N->next->next;
	freeNode(&temp);
	D->numItems--;
      }
    }
  }
}

void makeEmpty(DictionaryRef D){
  D->numItems=0;
  freeNode(&D->front);
}

void printDictionary(DictionaryRef D, FILE* out){
  NodeRef N = D->front;
  while( N != NULL){
    fprintf(out,"%d %d \n",N->key,N->value);
    N = N->next;
  }
}
