#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char push(int s[20], int *top, int item)
{
    *top=*top+1;
    s[*top]=item;
}

char pop(int s[20], int *top)
{
    int item = s[*top];
    *top=*top-1;
    return item;
}

int main()
{
    char ch, post[50];
    int s[20], top=-1, a, b, res, i;

    printf("enter valid postfix exp: \n");
    scanf("%s", post);

    for(i=0; i<strlen(post); i++)
    {
        ch=post[i];
        if(isdigit(ch))
        {
            push(s, &top, ch-'0');
        }
        else
        {
            b=pop(s, &top);
            a=pop(s, &top);
        }

        if(ch=='+') res=a+b;
        if(ch=='-') res=a-b;
        if(ch=='*') res=a*b;
        if(ch=='/') res=a/b;
        if(ch=='^') res=pow(a,b);
        if(ch=='%') res=a%b;
    }

    printf("the resultant exp is : %d\n", res);

    return 0;
}
