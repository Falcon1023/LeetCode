#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char words[50000][201];

int compare ( const void *a, const void *b ) {
  char* _a = (char*) a;
  char* _b = (char*) b;
  return strcmp( _a, _b );
}

int main() {
  char c,tmp[201];
  int i = 0, j = 0;
  while ( ( c = getchar() ) != EOF ) {
    if ( !isalpha(c) ) {
      if( j > 0 ) {
        tmp[j] = '\0';
        strcpy( words[i], tmp );
        i++;
      }
      j = 0;
    } else {
      tmp[j] = tolower(c);
      j++;
    }
  }
  qsort( words, i, 201, compare);
  for (j = 0; j < i; j++) {
    if ( strcmp(words[j], words[j+1]) == 0 )
      continue;
    printf("%s\n", words[j]);
  }
  return 0;
}
