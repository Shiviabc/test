#include<stdio.h>
#include<stdlib.h>
#define sz 5

void qins(int q[sz], int *r, int *count, int item)
{
    if(*count==sz)
    {
        printf("overflow\n");
    }
    else
    {
        *r=*(r+1)%sz;
        q[*r]=item;
        *count = *count +1;
    }
}

void qdel(int q[sz], int *f, int *count)
{
    if(*count == 0)
    {
        printf("underflow\n");
    }
    else
    {
        printf("the deleted item is: %d\n", q[*f]);
        *f=*(f+1)%sz;
        *count=*count-1;
    }
}

void qdis(int q[sz], int f, int count)
{
    if(count==0)
    {
        printf("the stack is empty\n");
    }
    else
    {
        printf("the contents are: ");
        int i, j;
        j=f;
        for(i=1; i<=count; i++)
        {
            printf("s[%d]===>%d", j, q[j]);
            j=(j+1)%sz;
        }
    }
}

void main()
{
    int ch, f=0, r=-1, item, count=0, q[sz];
    for(;;)
    {
        printf("1: insert  2: delete  3:display\n ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("enter items: ");
            scanf("%d", &item);
            qins(q,&r, &count, item);
            break;

            case 2: qdel(q, &f, &count);
            break;

            case 3: qdis(q, f, count);
            break;

            default: exit(0);
        }

    }
}
