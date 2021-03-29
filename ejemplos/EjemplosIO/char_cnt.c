#include <stdlib.h>
#include <stdio.h>
int main(void)
{
   int c,charCnt=0; 
   
	while (( c = getchar()) != '\n')
		charCnt++;

	   printf("\n\nChar Count %d\n",charCnt);
	   

 
  return 0;

}

