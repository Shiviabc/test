#define Sz 5

#include <stdio.h> 
#include <stdlib.h>

void push(int S[Sz], int *top, int item){
	if(*top==Sz-1){
		printf ("Stack Overflow \n"); 
		return;
	}
	*top= *top+1;
	S[*top]=item;
	printf("%d inserted into the stack\n", item);
}

void pop (int S[Sz], int *top)
{
    if(*top==-1)
    {
		printf("Stack underflow \n"); 
		return;
	}
	printf("%d is deleted \n", S[*top]);
    *top=*top-1;
}

void display (int S[Sz], int top){
	int i;
	if (top==-1){
		printf ("Empty Stack In");
		return;
	}
	printf("Content of Stack \n");
	for(i=0; i<=top; i++){
		printf("%d \n",S[i]);
	}
}

int main(){
	
    int S[Sz], top=-1, item, ch;
    for(;;){
		printf("1:Insert 2: Delete 3: Display 4:Exit \n");
		scanf("%d", &ch);
		switch (ch){
			case 1: printf("Enter the item \n");
			        scanf("%d", & item);
			        push (S, &top, item);
			        break;
            
            case 2: pop(S, &top); 
                    break;
                    
            case 3: display (S, top);
                    break;
            
            case 4: exit (0);
            
            default: printf("Invalid Choice, Please try again");
		}
	}
	return 0;
}
