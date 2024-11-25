#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void main()
{
    int i, key, a[100], newloc, loc, n, m;
    printf("enter the no of elements: \n");
    scanf("%d", &n);
    printf("enter the m value for k mod m: \n");
    scanf("%d", &m);
    for(i=0; i<=10; i++)
    {
        a[i]=-999;
    }

    for(i=1; i<=n; i++)
    {
        printf("enter key value: \n");
        scanf("%d", &key);
        loc= key%m;
        if(a[loc]==-999)
        {
            a[loc]=key;
        }
        else
        {
            newloc=loc+1;
            while(a[newloc]!=-999 && newloc<=10)
            
                newloc=newloc+1;
                a[newloc]=key;
            
        }
    }
    printf("the keys for the hashed location are: " );
    for(i=0; i<=10; i++)
    {
        printf("a[%d] === >> %d\n", i, a[i]);
    }
}
