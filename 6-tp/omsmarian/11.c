#include <stdio.h>

#define N 4

void transponer (double mat[N][N]);

int main(void)
{
    double mat[N][N]={{1,2,3,4},{5,6,7,8},{8,9,10,11},{12,13,14,15}};
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%.0f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    transponer(mat);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%.0f ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}


void transponer (double mat[N][N])
{
    double a;
    double d;
    double inter = 0;
    for(int i = 0; i < N; i++)
    {
        inter++;
        for(int j = inter; j < N; j++)
        {
            a = mat[i][j];
            d = mat[j][i];
            mat[j][i] = a;
            mat[i][j] = d;
        }
    }




}