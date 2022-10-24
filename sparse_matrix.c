#include<stdio.h>

//prototype
void sparsematrix(int [][10],int ,int);

void main()
{
    int mat[10][10],m,n,i,j;
    printf("Enter the size of rows and columns: ");
    scanf("%d%d",&m,&n);
    printf("Enter the elements for rows and columns: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    }
    sparsematrix(mat,m,n);
}

void sparsematrix(int mat[][10],int m, int n)
{
    int i,j,zero=0;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(mat[i][j]==0)
                zero++;
    if(zero>=((m*n)/2))
        printf("It is a sparse matrix");
    else  
        printf("It is not a sparse matrix");
}
