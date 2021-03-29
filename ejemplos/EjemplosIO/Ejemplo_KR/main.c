   #include <stdio.h>


   #define IN   1  /* inside a word */
   #define OUT  0  /* outside a word */

   /* count lines, words, and characters in input */
   int main(void)
   {
	   int c, nl, nw, nc, state;


	   state = OUT;
	   nl = nw = nc = 0;
	   while ((c = getchar()) != EOF) {

		   //printf ("%c",c);
		   ++nc;
           if (c == '\n')
               ++nl;
           if (c == ' ' || c == '\n' || c == '\t')

           {
               state = OUT;
               if (c!='\n')          // '/n' was already printed
                printf("\n");        // one word per line
           }
           else if (state == OUT) {

               state = IN;
               ++nw;
           }
       }
	   printf("Lineas:%d, Palabras:%d, Caracteres:%d \n", nl, nw, nc);
	   return 0;
   }

