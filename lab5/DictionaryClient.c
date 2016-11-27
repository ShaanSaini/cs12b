/* DictionaryClient.c
 * Shaan Saini
 * shksaini
 * lab5
 * Test client for the Dictionary ADT
 */

#include<stdio.h>
#include<stdlib.h>
#include"Dictionary.h"

int main(int argc, char* argv[]){
  int v;
  DictionaryRef A = newDictionary();

  insert(A, 1, 111);
  insert(A, 2, 222);
  insert(A, 3, 333);
  insert(A, 4, 444);
  insert(A, 5, 555);
  insert(A, 6, 666);
  insert(A, 7, 777);
  printDictionary(A, stdout);
  v = lookup(A, 1);
  printf("key=1 "); v==UNDEF?printf("not found\n"):printf("value=%d\n", v);
  v = lookup(A, 3);
  printf("key=3 "); v==UNDEF?printf("not found\n"):printf("value=%d\n", v);
  v = lookup(A, 7);
  printf("key=7 "); v==UNDEF?printf("not found\n"):printf("value=%d\n", v);
  v = lookup(A, 8);
  printf("key=8 "); v==UNDEF?printf("not found\n"):printf("value=%d\n", v);
  printf("\n"); 
    
  delete(A, 1);
  delete(A, 3);
  delete(A, 7);
  printDictionary(A, stdout);
    
  printf("%s\n", isEmpty(A)?"true":"false");
  printf("%d\n", size(A));
  makeEmpty(A);
  printf("%s\n", isEmpty(A)?"true":"false");
  printDictionary(A, stdout);
    
  freeDictionary(&A);
  return(EXIT_SUCCESS);
}
