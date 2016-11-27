// charType.c
// Shaan Saini
// shksaini
// lab4
// read the input from a file and classifies the what type of character is in 
//the file printing the characters in specific catagory

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

#define MAX_STRING_LENGTH 100

void extract_chars(char* s , char* a, char* d, char* p, char* w);

int main(int argc, char* argv[]){
  FILE* in; 
  FILE* out;
  char* line;
  char* word;
  char* num;
  char* punc;
  char* whitespace;
  int n=1;

  if(argc!=3){
    printf("Usage: %s input-file outputfile \n", argv[0]);
    exit(EXIT_FAILURE);

  }

  in = fopen(argv[1], "r");
  if(in ==  NULL){
    printf("Unable to read input file \n ");
    exit(EXIT_FAILURE);
  }

  out = fopen(argv[2],"w");
  if(out == NULL){
    printf("Unable to write to output file \n");
    exit(EXIT_FAILURE);
  }

  line = calloc(MAX_STRING_LENGTH+1, sizeof(char));
  word = calloc(MAX_STRING_LENGTH+1, sizeof(char));
  num = calloc(MAX_STRING_LENGTH+1, sizeof(char));
  punc = calloc(MAX_STRING_LENGTH+1, sizeof(char));
  whitespace = calloc(MAX_STRING_LENGTH+1, sizeof(char));
  assert(line!=NULL && word!=NULL && num!=NULL && punc!=NULL && whitespace!=NULL);
  

  while( fgets(line, MAX_STRING_LENGTH, in) != NULL){
    extract_chars(line,word,num,punc,whitespace);
    fprintf(out,"line %d contains: \n",n);
    if(strlen(word)>1){
      fprintf(out,"%d alphabetic characters: %s\n",(int)strlen(word),word);
    }
    else{
      fprintf(out,"%d alphabetic character: %s\n",(int)strlen(word),word);
    }
    if(strlen(num)>1){
      fprintf(out,"%d numeric characters: %s\n",(int)strlen(num),num);
    }
    else{
      fprintf(out,"%d numeric character: %s\n",(int)strlen(num),num);
    }
    if(strlen(punc)>1){
      fprintf(out,"%d punctuation characters: %s\n",(int)strlen(punc),punc);
    }
    else{
      fprintf(out,"%d punctuation character: %s\n",(int)strlen(punc),punc);
    }
    if(strlen(whitespace)>1){
      fprintf(out,"%d whitespace characters: %s\n",(int)strlen(whitespace),whitespace);
    }
    else{
      fprintf(out,"%d whitespace character: %s\n",(int)strlen(whitespace),whitespace);
    } 
    n++;
  }

  free(line);
  free(word);
  free(num);
  free(punc);
  free(whitespace);

  fclose(in);
  fclose(out);

  return EXIT_SUCCESS;

}

void extract_chars(char* s, char* a, char* d, char* p, char* w){
  int i=0, j=0, k=0, l=0, m=0;
  while(s[i] != '\0' && i<MAX_STRING_LENGTH){
    if( isupper((int)s[i])){
      a[j]=s[i];
      j++;
    }
    else if( isalpha((int)s[i])){
      a[j] =s[i];
      j++;
    }
    else if( isdigit((int)s[i])){
      d[k] = s[i];
      k++;
    }
    else if(ispunct((int)s[i])){
      p[l]=s[i];
      l++;
    }
    else{
      w[m]=s[i];
      m++;
    }
    i++;
  }

  a[j]='\0';
  d[k]='\0';
  p[l]='\0';
  w[m]='\0';
}
