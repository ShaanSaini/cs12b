// FileReverse.c
// Shaan Saini
// shksaini
// lab3
// Reads words from a text file and outputs them in reverse order

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringReverse(char* s){
  int i;
  int j=strlen(s)-1;
  char temp;
  for(i=0; i<=j; i++){
    temp = s[j];
    s[j] = s[i];
    s[i]=temp;
    j--;
  }
}


int main ( int argc, char* argv[]){
  FILE* in;
  FILE* out;
  char word[256];

  if( argc != 3){
    printf("Usage: %s inputFile outputFile\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  in = fopen(argv[1], "r");
  if( in==NULL){
    printf("Unable to read from file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  out = fopen(argv[2], "w");
  if( out==NULL){
    printf("Unable to write to file %s\n",argv[2]);
    exit(EXIT_FAILURE);
  }

  while( fscanf(in, " %s",word) != EOF){
    stringReverse(word);
    fprintf(out,"%s\n",word );
    
  }

  fclose(in);
  fclose(out);


  return(EXIT_SUCCESS);

}
