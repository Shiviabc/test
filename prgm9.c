#include<stdio.h>
#include<stdlib.h>

void dfs(int n, int a[10][10], int source, int s[10])
{
    int i;
    printf("%d\t", source);
    s[source]=1;//source node visited
    for(i=1; i<=n; i++) //recursion
    {
        if(s[i]=0 && a[source][i]==1)
        dfs(n, a, i ,s);
    }
}

void main()
{
    int n, source, a[10][10], i, j, s[10];
    printf("enter num of nodes: \n");
    scanf("%d", &n);
    printf("enter elements of adj matrix: \n");
    for(i=1; i<=n; i++)//filling the matrix
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("enter source node: \n");
    scanf("%d", &source);

    for(i=1; i<=n; i++) //check on nodes visited
    {
        s[i]=0;
    }
    printf("the dfs order is: \n");
    dfs(n,a, source, s);
}
