#include <stdio.h>


int main (void)
{
    int *p;
    int *q;


    int orden [] = {9,3,2,4,1,2};

    p = &orden[0];
    q = &orden[1];

    for(*p; *p < *q; *(q+1))
    {
        swap2(p,q);
    }
    return 0;
}



void swap2(int *pa, int *pb) 
{ 
    int t; 
    t = *pa; 
    *pa = *pb; 
    *pb = t;
}