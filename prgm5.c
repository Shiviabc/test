#include<stdio.h>
#include<malloc.h>

	struct node
	{
	int usn;
	char name[10];
	char prog[10];
	int sem;
	long int mno;

	struct node *link;
	}; typedef struct node * NODE;

//*********** Function to Insert at begining *********

	NODE insfront(NODE first)
	{
	NODE newnode;
	newnode = (NODE)malloc(sizeof(struct node));
	printf(" Enter the USN Name Program Semester Mobile No of student \n");
	scanf("%d%s%s%d%ld", &newnode->usn, newnode->name, newnode->prog, 
                                       &newnode->sem, &newnode->mno);
	newnode->link = first;
	first = newnode;
	return first;
	}
//*********** Function to Insert at the End of List *********
	NODE insend(NODE first)
	{
	NODE newnode,temp;
	newnode = (NODE) malloc(sizeof(struct node));
	printf(" Enter the USN Name Program Semester Mobile No of student \n");
	scanf("%d%s%s%d%ld", &newnode->usn, newnode->name, newnode->prog, 
                                       &newnode->sem, &newnode->mno);
	newnode->link = NULL;

	temp = first;
	while(temp->link != NULL)
	temp = temp->link;

	temp->link = newnode;
	return first;
	}

//*********** Function to Delete Node from begining *********
	NODE delfront(NODE first)
	{
	NODE temp;

	if( first == NULL)
	printf(" The List is Empty, deletion cannot be possible\n");
	else
	{
	temp =  first;
	first = first ->link;
	free(temp);
	}
	return first;
	}

//*********** Function to Delete Node at End of List *********
	NODE delend(NODE first)
	{
	NODE prev,pres;

	if( first == NULL)
	{
	printf(" The List is Empty, deletion cannot be possible\n");
	return first;
	}

	if(first->link == NULL)
	{
	pres = first;
	first = NULL;
	free (pres);
	return first;
	}

	printf("The USN Name Program Semester Mobile No of student \n");
	pres =  first;

	while(pres->link != NULL)
	{
	prev = pres;
	pres = pres->link;
	}

	prev->link = NULL;
	free(pres);
	return first;
	}



//*********** Function to Delete Node from begining *********

	void display(NODE first)
	{
	NODE temp;

	if( first == NULL)
	printf(" The List is Empty\n");
	else
	{
	temp =  first;
	printf("The USN Name Program Semester Mobile No of student \n");
	while(temp != NULL )
	{
	printf("%d\t%s\t%s\t%d\t%ld\n", temp->usn, temp->name, temp->prog, temp->sem,  
                                                                                                                  temp->mno);
	temp  = temp->link;
	}
	}
	}

// Main Program
void main()
		{

		NODE first = NULL;
		int ch;


     for(;;)
     {
     printf(" 1:Ins Front 2:Ins End 3:Del Front 4:Del end 5: Display\n");
     scanf("%d",&ch);

	switch(ch)
	{
	case 1: first = insfront(first);
		     break;
	case 2: first = insend(first);
		     break;
	case 3: first = delfront(first);
		     break;
	case 4: first = delend(first);
		     break;
	case 5: display(first);
		     break;
	default: exit(0);
	}
	}
	}




