/************************************************************************************************
 *                                      dataStructures.c
 *
 * Copyright(C) 2006.MindTree Pvt. Ltd. All rights reserved.
 *
 * Revision : V1.0
 *
 * Last Modified Date    Author         Description
 *
 * 14-Aug-2015           Deepak Birla       Initial version
 *
 ***********************************************************************************************/

/***********************************************************************************************

		USING THIS PROGRAM WE CAN PERFORM BASIC LINK LIST OPERATIONS, 
	        STACK OPERATION, QUEUE OPERATIONS AND BINARY TREE OPERATIONS
	* ENTER N LISTS	
	* CREATE NODE 
	* CREATE LIST
	* INSERT NODE
	* DELETE NODE
	* REVERSE LIST
	* SEARCH NODE IN LIST
	* SORT LIST
	* DELETE K NODES FROM LIST
	* DISPLAY LIST
	* DETECT LOOP IN LIST (FLOYD ALGORITHM)
	* MAKE LIST CIRCULAR
	* DISPLAY CIRCULAR LIST
	* INSERT NODE IN CIRCULAR LIST
	* DELETE NODE IN CIRCULAR LIST
	* CONCATENATE TWO LISTS
	* COMPARE TWO LISTS
	* DISPLAY LIST AS STACK
	* PUSH ELEMENT IN STACK
	* POP ELEMENT FROM STACK 
	* DISPLAY LINK LIST AS QUEUE
	* INSERT IN QUEUE
	* DELETE FROM QUEUE
	* STACK SIZE
	* QUEUE SIZE
	* CREATE TREE
	* PREORDER TRAVERSAL OF TREE
	* INORDER TRAVERSAL OF TREE
	* POSTORDER TRAVERSAL OF TREE
	* SEARCH NODE IN TREE
	* DEPTH OF TREE
	* DELETE COMPLETE TREE
	* DELETE A NODE FROM TREE

************************************************************************************************/

/**************************  HEADER FILES INCLUDED IN THE PROGRAM  *****************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/************************************  GLOBAL VARIABLES  ***************************************/

int numberOfNodes=0,treeNodes=0;

/************************************************************************************************

	   STRUCTURE DEFINITION.THIS STRUCTURE DEFINES A NODE WHICH HAS TWO VALUES 
	
	* DATA
	* ADDRESS OF ANOTHER NODE

************************************************************************************************/

struct _node
{
	int data;
	struct _node *next;
}*start=NULL,*current,**start_node=&start,*end=NULL;

/************************************************************************************************

          STRUCTURE DEFINITION.THIS STRUCTURE DEFINES A NODE WHICH HAS THREE VALUES 
        
        * VALUE
        * ADDRESS OF RIGHT NODE IN TREE
	* ADDRESS OF LEFT NODE IN TREE

************************************************************************************************/

struct _tree_node
{
        int value;
        struct _tree_node *left;
	struct _tree_node *right;
}*root=NULL,**root_node=&root;

/********************************************************************   LINKED LISTS, STACKS AND QUEUES FUNCTIONS   **************************************************************************/

/************************************************************************************************

           THIS METHOD DYNAMICALLY CREATES A NODE AND RETURNS ADDRESS OF TEHT NODE

************************************************************************************************/

struct _node* create_node(int value)
{
	struct _node *new_node;
	new_node=(struct _node *)malloc(sizeof(struct _node));
	new_node->data=value;
	new_node->next=NULL;
	return new_node;
}

/************************************************************************************************

                                 THIS METHOD REVERSE THE LIST

************************************************************************************************/

void reverse_list()
{
	struct _node *temp,*temp1,*var;
	temp=start;
	var=NULL;
	while(temp!=NULL)
	{
		temp1=var;
		var=temp;
		temp=temp->next;
		var->next=temp1;
	}
	start=var;
}

/************************************************************************************************

                           THIS METHOD DELETES K NODE FROM THE LIST

************************************************************************************************/

void delete_knodes_from_list( int k)
{
	int i;
	struct _node *new_node,*n;
	while(k!=0)
	{
		new_node=start;
		while(new_node!=NULL)
		{
			if(new_node->next->next==NULL)
			{
				n=new_node->next;
				new_node->next=NULL;
				free(n);
			}
			new_node=new_node->next;
		}
		k--;
	}
}

/************************************************************************************************

                                THIS METHOD SORTS THE LINK LIST

************************************************************************************************/

void sort_list()
{
	int d;
	struct _node *temp,*temp1;
	temp=start;
	temp1=start;
	while(temp!=NULL)
	{
		temp1=start;
		while(temp1!=NULL)
		{

			if(temp1->next!=NULL)
			{       if(temp1->data > temp1->next->data)
				{
					d=temp1->data;
					temp1->data=temp1->next->data;
					temp1->next->data=d;
				}
			}

			temp1=temp1->next;
		}
		temp=temp->next;
	}
}

/************************************************************************************************

                THIS METHOD SEARCH A VALUE IN THE LIST AND RETURNS NODE POSITION

************************************************************************************************/

int search_in_list(int s)
{
	int count=0,flag=0;
	struct _node *temp;
	temp=start;
	count++;
	while(temp!=NULL)
	{
		if(temp->data==s)
		{
			flag=1;
			break;
		}
		else
			flag=0;
		temp=temp->next;
		count++;
	}
	if(flag==1)
		return count;
	else
		return-1;
}

/************************************************************************************************

                             THIS METHOD MAKES THE LINK LIST CIRCULAR

************************************************************************************************/

void make_circular_list()
{
	struct _node *new_node;
	new_node=start;

	if(start->next !=NULL)
	{
		while(new_node->next != NULL)
		{
			new_node=new_node->next;
		}
		new_node->next=start;
	}
	else
		printf("\nNot Enough nodes to create Circular Link List");
}

/************************************************************************************************

            THIS METHOD COUNTS THE NUMBER OF NODES PRESENT IN LIST AND RETURN COUNT

************************************************************************************************/

int count_nodes_in_list()
{
	int count=0;
	struct _node *new_node;
	new_node=start;

	while(new_node != NULL)
	{
		new_node=new_node->next;
		count++;
	}
	return count;
}

/************************************************************************************************

                            THIS METHOD COMPARE TWO SINGLY LINK LISTS

************************************************************************************************/

void compare_list(num1,num2)
{
	struct _node *new_node,*new_node1;
	int count1=0,count2=0,max,flag=0;
	new_node=*(start_node + num1 - 1);
	new_node1=*(start_node + num2 - 1);
	while(new_node->next !=NULL)
	{
		count1++;
		new_node=new_node->next;
	}
	while(new_node1->next !=NULL)
	{
		count2++;
		new_node1=new_node1->next;
	}
	if(count1>count2)
		printf("\nList 1 is greater then List 2");
	else if(count2>count1)
		printf("\nList 2 is greater then List 1");
	else
	{
		new_node=*(start_node + num1 - 1);
		new_node1=*(start_node + num2 - 1);
		while(new_node !=NULL)
		{
			if(new_node->data == new_node1->data)
				flag=1;
			else if(new_node->data > new_node1->data)
			{
				printf("\nList 1 is greater then List 2");
				break;
			}
			else if(new_node->data < new_node1->data)
			{
				printf("\nList 1 is greater then List 2");
				break;
			}
			new_node=new_node->next;
			new_node1=new_node1->next;
		}
		if(flag==1)
			printf("\nList one and List two are not equal");
	}
}

/************************************************************************************************

                        THIS METHOD CONCATENATES TWO SINGLY LINK LISTS

************************************************************************************************/

void concatenate_list(num1 , num2)
{
	struct _node *new_node;
	start=*(start_node + num1 -1);
	new_node=*(start_node + num1 -1);
	while(new_node->next !=NULL)
	{
		new_node=new_node->next;
	}
	new_node->next=*(start_node + num2 -1);
	*(start_node + num1 -1)=start;
	*(start_node + num2 -1)=start;
}

/************************************************************************************************

           THIS METHOD ALLOW USER TO ENTER LIST NUMBER ON WHICH USER WANTS TO WORK. 
	   AND RETURNS THE LIST NUMBER

************************************************************************************************/

int choose_list(int number_of_lists)
{
	int ch;
	char term;
	do
	{
		system("clear");
		__fpurge(stdin);
		printf("\nEnter List Number (1 to %d):",number_of_lists);
	}while(scanf("%d%c", &ch, &term) != 2 || term != '\n' || ch > number_of_lists || ch < 1);
	return ch;
}

/************************************************************************************************

                 THIS METHOD DETECTS IF THERE IS ANY LOOP PRESENT IN THE LIST
		 AND RETURNS 1 IF LOOP IS PRESENT ELSE IT RETURNS 0

************************************************************************************************/

int detect_loop_in_list()
{
	struct _node *new_node,*f,*s;
	int flag=0;
	new_node=start;
	f= new_node;
	s= new_node;
	while(f && s && f->next)
	{
		s=s->next;
		f=f->next->next;
		if(s==f)
		{
			flag=1;
			break;
		}
		else
			flag=0;
	}
	return flag;
}

/************************************************************************************************

                               THIS METHOD POPS ELEMENT FROM STACK

************************************************************************************************/

int delete_from_stack()
{
        struct _node *new_node;
	int temp;
        new_node=start;
	if(start == NULL)
		return -99;
	else
	{
		temp=new_node->data;
		start=start->next;
		free(new_node);
	}
        return temp;
}

/************************************************************************************************

                               THIS METHOD POPS ELEMENT FROM Queue

************************************************************************************************/

int delete_from_queue()
{
        struct _node *new_node;
        int temp;
        new_node=start;
        if(start == NULL)
                return -99;
        else
        {
                temp=new_node->data;
                start=start->next;
                free(new_node);
        }
        return temp;
}

/************************************************************************************************

                               THIS METHOD PUSH ELEMENT IN STACK

************************************************************************************************/

int insert_in_stack(int value)
{
        struct _node *new_node,*temp;
        new_node=start;
	temp=create_node(value);
	start=temp;
	temp->next=new_node;		
	return temp->data;
}

/************************************************************************************************

                               THIS METHOD PUSH ELEMENT IN QUEUE

************************************************************************************************/

int insert_in_queue(int value)
{
        struct _node *new_node,*temp;
	if(end == NULL)
		return -99;
	else
	{
	temp=create_node(value);
	end->next=temp;
	end=temp;	
        return temp->data;
	}
}

/************************************************************************************************

                           THIS METHOD DISPLAYS THE LINK LIST AS STACK

************************************************************************************************/

void display_stack()
{
        struct _node *new_node;
                new_node=start;
		if(start==NULL)
			printf("\nThe STACK is empty");
		else
		{
			printf("\nThe STACK :");
                        while(new_node!=NULL)
                        {
                                printf("\n\t   %d",new_node->data);
				printf("\n\t--------");
                                new_node=new_node->next;
                        }
		}
}

/************************************************************************************************

                           THIS METHOD DELETES A NODE FROM THE LINK LIST

************************************************************************************************/

void delete_node_from_list( int p)
{
	int i;
	struct _node *new_node;
	new_node=start;
	if(p==1)
	{
		start=start->next;
		free(new_node);
	}
	else
	{
		for(i=1;i<p-1;i++)
		new_node=new_node->next;
		new_node->next=new_node->next->next;
	}
}

/************************************************************************************************

                       THIS METHOD REMOVES DUPLICATE ELEMENTS FROM THE LIST

************************************************************************************************/

void remove_duplicate_elements_from_list()
{
	int i;
	struct _node *new_node,*temp;
	new_node=start;
	while(new_node->next !=NULL)
	{
		if(new_node->data == new_node->next->data)
		{
			temp=new_node->next;
			new_node->next = new_node->next->next;
			free(temp);
		}
		new_node=new_node->next;
	}
}

/************************************************************************************************

                        THIS METHOD DELETES A NODE FROM A CIRCULAR LINK LIST

************************************************************************************************/

void delete_node_from_circular_list( int p)
{
	int i;
	struct _node *new_node;
	new_node=start;
	for(i=1;i<p-1;i++)
		new_node=new_node->next;
	new_node->next=new_node->next->next;
	numberOfNodes--;
}

/************************************************************************************************

                     THIS METHOD INSERTS A NODE AT THE GIVE POSITION IN THE LIST

************************************************************************************************/

void insert_node_in_list( int pos,int value)
{
	int i;
	struct _node *new_node,*f;
	struct _node *current;
	current=create_node(value);
	new_node=start;
	if(pos==1)
	{
		f=start;
		start=current;
		current->next=f;
	}
	else
	{
		for(i=1;i<pos-1;i++)
			new_node=new_node->next;
		f=new_node->next;
		new_node->next=current;
		current->next=f;
	}
}

/************************************************************************************************

             THIS METHOD INSERTS A NODE IN THE CIRCULAR LINK LIST AT GIVEN POSITION

************************************************************************************************/

void insert_node_in_circular_list( int pos,int value)
{
	int i;
	struct _node *new_node,*f;
	struct _node *current;
	current=create_node(value);
	new_node=start;
	for(i=1;i<pos-1;i++)
		new_node=new_node->next;
	f=new_node->next;
	new_node->next=current;
	current->next=f;
	numberOfNodes++;
}

/************************************************************************************************

                                THIS METHOD CREATES A LINK LIST

************************************************************************************************/

void add_node_to_list(struct _node *new_node)
{
	__fpurge(stdin);
	if(start==NULL)
	{
		start=new_node;
		current=new_node;
	}
	else
	{
		current->next=new_node;
		current=new_node;
	}
}

/************************************************************************************************

                                   THIS METHOD DISPLAYS THE LINK LIST

************************************************************************************************/

void display_list()
{
	struct _node *new_node;
	int flag=0;
	flag=detect_loop_in_list();
	if(flag==1)
		printf("\nLoop Detected :Can't Display Link List. Try option 12 to Display circular Link List");
	else
	{
		printf("\nThe Linked List : ");
		new_node=start;
		if(flag!=1)
		{
			while(new_node!=NULL)
			{
				printf("%d--->",new_node->data);
				new_node=new_node->next;
			}
			printf("NULL\n");
		} 
	}
}

/************************************************************************************************

                                   THIS METHOD DISPLAYS THE QUEUE

************************************************************************************************/

void display_queue()
{
        struct _node *new_node;
        int flag=0;
        flag=detect_loop_in_list();
        if(flag==1)
                printf("\nLoop Detected :Can't Display Queue");
        else
        {
                printf("\nThe Queue is : ");
                new_node=start;
                if(flag!=1)
                {
                        while(new_node!=NULL)
                        {
                                printf("%d<---",new_node->data);
                                new_node=new_node->next;
                        }
                }
        }
}

/************************************************************************************************

                               THIS METHOD WILL CONVERT LIST TO QUEUE

************************************************************************************************/

void convert_list_to_queue()
{
        struct _node *new_node;
                new_node=start;
                        while(new_node->next != NULL)
                        {
                                new_node=new_node->next;
                        }
		end=new_node;
}

/************************************************************************************************

                               THIS METHOD DISPLAYS THE CIRCULAR LINK LIST

************************************************************************************************/

void display_circular_list()
{
	struct _node *new_node;
	int n=numberOfNodes;
	printf("\nThe Linked List : ");
	new_node=start;
	while(n!=0)
	{
		printf("%d--->",new_node->data);
		new_node=new_node->next;
		n--;
	}
}

/*****************************************************************   LINKED LISTS, STACKS AND QUEUES FUNCTIONS OVER   ************************************************************************/

/*****************************************************************************   BINARY SEARCH TREE   ****************************************************************************************/

/************************************************************************************************

                 METHOD TO CREATE A NODE FOR A TREE AND RETURNS THE NODE ADDRESS

************************************************************************************************/

struct _tree_node* create_tree_node(int data)
{
        char term;
        struct _tree_node *new_node;
        new_node=(struct _tree_node *)malloc(sizeof(struct _tree_node));
        new_node->value=data;
        new_node->right=NULL;
	new_node->left=NULL;
        return new_node;
}

/************************************************************************************************

                                INORDER TRAVERSAL OF THE TREE

************************************************************************************************/

void inorder(struct _tree_node *toor)
{       
	if(toor == NULL)
		return;
	inorder(toor->left);	 
	printf("%d ",toor->value);
	inorder(toor->right);
}

/************************************************************************************************

                            METHOD COUNTS NUMBER OF NODES IN THE TREE

************************************************************************************************/

int count_tree_depth(struct _tree_node *toor)
{       
	if (toor==NULL) 
       return 0;
   	else
   	{
       /* compute the depth of each subtree */
       int lDepth = count_tree_depth(toor->left);
       int rDepth = count_tree_depth(toor->right);
 
       /* use the larger one */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else 
	   return(rDepth+1);
   	}
}


/************************************************************************************************

                                PREORDER TRAVERSAL OF THE TREE

************************************************************************************************/

void preorder(struct _tree_node *toor)
{
        if(toor == NULL)
                return;
        printf("%d ",toor->value);
        preorder(toor->left);
        preorder(toor->right);
}

/************************************************************************************************

                                POSTORDER TRAVERSAL OF THE TREE

************************************************************************************************/

void postorder(struct _tree_node *toor)
{
        if(toor == NULL)
                return;
        postorder(toor->left);
        postorder(toor->right);
        printf("%d ",toor->value);
}

/************************************************************************************************

                            METHOD DELETES THE COMPLETE BINARY TREE

************************************************************************************************/

void delete_complete_tree(struct _tree_node *toor)
{
        if(toor == NULL)
                return;
        delete_complete_tree(toor->left);
        delete_complete_tree(toor->right);
	printf("\nNode Deleted :%d",toor->value);
	toor->left=NULL;
	toor->right=NULL;
        free(toor);
}

/************************************************************************************************

                           FUNCTION RETURNS MAXIMUM FROM INORDER TRAVERSAL

************************************************************************************************/

struct _tree_node * inorder_max(struct _tree_node *toor)
{       
	int max=toor->value;
	struct _tree_node *temp=NULL;	
	if(toor == NULL)
		return;
	inorder_max(toor->left);
		if(max < toor->value)
		{
			max=toor->value;
			temp=toor;
		}	
	inorder_max(toor->right);
	return temp;
}

/************************************************************************************************

                            METHOD FOR DELETING VALUE OR NODE FROM TREE

************************************************************************************************/

void delete_from_tree(struct _tree_node *toor,int data)
{
	int flag=0;
	struct _tree_node *temp,*prev,*temp1,*temp2;
        __fpurge(stdin);
        
		temp=toor;
		while(temp != NULL)
		{	
                	if(temp->value < data)
			{
				prev=temp;
				temp=temp->right;
				flag=0;
			}
			else if(temp->value > data)
			{
				prev=temp;
				temp=temp->left;
				flag=0;
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(flag == 1)
		{
			if((temp->right == NULL) && (temp->left == NULL))
			{
				if(prev->left == temp)
					prev->left=NULL;
				else
					prev->right=NULL;
				free(temp);
			}	
			else if((temp->right == NULL) && (temp->left != NULL))
			{
				if(prev->left == temp)
					prev->left=temp->left;
				else
					prev->right=temp->left;
				free(temp);
			}
			else if((temp->right != NULL) && (temp->left == NULL))
			{
				if(prev->left == temp)
					prev->left=temp->right;
				else
					prev->right=temp->right;
				free(temp);
			}
			else
			{
				temp2=temp;				
				temp1=inorder_max(temp2);
				temp->value=temp1->value;
				delete_from_tree(temp1,temp1->value);
			}
		}
}

/************************************************************************************************

                              THIS METHOD CREATES A BINARY TREE

************************************************************************************************/

void create_tree(struct _tree_node *new_node)
{
	struct _tree_node *temp,*prev;
        __fpurge(stdin);
        if(root==NULL)
        {
                root=new_node;
        }
        else
        {
		temp=root;
		while(temp != NULL)
		{	prev=temp;
                	if(temp->value < new_node->value)
				temp=temp->right;
			else
				temp=temp->left;
		}
		if(prev->value < new_node->value)
			prev->right=new_node;
		else
			prev->left=new_node;
        }
}

/************************************************************************************************

                             THIS METHOD SEARCHES A VALUE IN THE TREE

************************************************************************************************/

int search_in_tree(int data)
{
	int count=0,flag=0;
	struct _tree_node *temp;
       		temp=root;
		while(temp != NULL)
		{
			count++;
			if(temp->value == data)
			{
				flag=1;
				break;
			}
                	else if(temp->value < data)
			{
				temp=temp->right;
				flag=0;
			}
			else
			{
				temp=temp->left;
				flag=0;
			}
		}
		if(flag == 1)
			return count;
		else
			return 0;
}

/*****************************************************************   BINARY SEARCH TREE FUNTIONS ENDS   **************************************************************************/

/************************************************************************************************

                      MAIN FUNCTION. IT IS THE STARTING POINT OF THE PROGRAM

************************************************************************************************/

int main()
{
	struct _node *ptr;
	struct _tree_node *tree_ptr;
	int choiceNode,number_of_lists,num1,num2,number_of_trees,tree_choiceNode,data,value;
	int choice,pos,s,flag=0,element,operation_choice,total_nodes;
	char ch='y',chc='y',term,choice_list='y',program_continue='y',tree_choice='y',tree_ch='y',tree_choice_list='y';
	do
	{
	do
        {
                system("clear");
                __fpurge(stdin);
                printf("\n\t\tMENU\n\t1. Linked List, Stacks and Queues\n\t2. Binary Search Trees\n\nEnter your choice :");
        }while(scanf("%d%c", &operation_choice, &term) != 2 || term != '\n' || operation_choice > 2 || operation_choice < 0);
	switch(operation_choice)
	{
	case 1:
	do
	{
		system("clear");
		__fpurge(stdin);
		printf("\nEnter number of lists you want :");
	}while(scanf("%d%c", &number_of_lists, &term) != 2 || term != '\n');
	start_node=malloc(number_of_lists*sizeof(struct _node *));
	do
	{
		choiceNode=choose_list(number_of_lists);
		start=*(start_node+choiceNode-1);
		__fpurge(stdin);
		do
		{
			do
			{
				__fpurge(stdin);
				system("clear");
				printf("\t\tLIST %d",choiceNode);
				printf("\n\t\tMenu\n\t1.  Create List\n\t2.  Display List\n\t3.  Insert Node\n\t4.  Delete Node\n\t5.  Reverse list\n\t6.  Search in list\n\t7.  Sorting\n\t8.  Dekete k nodes\n\t9.  Make Link List circular\n\t10. Delete From Circular Link List\n\t11. Insert in Circular Link List\n\t12. Display Circular Link List\n\t13. Remove Duplicate elements from list\n\t14. Concatenate 2 lists\n\t15. Compare two lists\n\t16. Display Link List as stack\n\t17. Push element in stack\n\t18. Pop element from stack\n\t19. Convert List to Queue\n\t20. Insert in Queue\n\t21. Delete from Queue\n\t22. Display Queue\n\t23. Size of Stack\n\t24. Size of Queue\n\n\tEnter your choice : ");
			}while(scanf("%d%c", &choice , &term) !=2 || term != '\n');
			switch(choice)
			{
				case 1:
					do
					{
						system("clear");
						printf("\t\tLIST %d",choiceNode);
						do
						{
							__fpurge(stdin);
							printf("\nEnter data : ");
						}while(scanf("%d%c", &data, &term) != 2 || term != '\n');
						ptr=create_node(data);
						add_node_to_list(ptr);
						printf("\nEnter y to enter more nodes :");
						scanf(" %c",&chc);
					}while(chc=='y' || chc=='Y');
					break;
				case 2:
					system("clear");
					printf("\t\tLIST %d",choiceNode);
					display_list();
					break;
				case 3:
					do
					{
						system("clear");
						printf("\t\tLIST %d",choiceNode);
						__fpurge(stdin);
						printf("\nEnter position from which you want to Insert node :");
					}while(scanf("%d%c", &pos, &term) != 2 || term != '\n');
					do
						{
							__fpurge(stdin);
							printf("\nEnter data you want to insert: ");
						}while(scanf("%d%c", &data, &term) != 2 || term != '\n');
					insert_node_in_list(pos,data);
					break;
				case 4:
					do
					{
						system("clear");
						printf("\t\tLIST %d",choiceNode);
						__fpurge(stdin);
						printf("\nEnter position from which you want to Delete node :");
					}while(scanf("%d%c", &pos, &term) != 2 || term != '\n');
					delete_node_from_list(pos);
					break;
				case 5:
					system("clear");
					printf("\t\tLIST %d",choiceNode);
					reverse_list();
					break;
				case 6:
					do
					{
						system("clear");
						printf("\t\tLIST %d",choiceNode);
						__fpurge(stdin);
						printf("\nEnter Element you want to search for :");
					}while(scanf("%d%c", &s, &term) != 2 || term != '\n');
					pos=search_in_list(s);
					if(pos==-1)
						printf("\n%d not found",s);
					else

						printf("%d found at %d",s,pos);
					break;
				case 7:
					system("clear");
					printf("\t\tLIST %d",choiceNode);
					sort_list();
					break;
				case 8:
					do
					{
						system("clear");
						printf("\t\tLIST %d",choiceNode);
						__fpurge(stdin);
						printf("\nEnter Number of nodes you want to Delete from end :");
					}while(scanf("%d%c", &pos, &term) != 2 || term != '\n');
					delete_knodes_from_list(pos);
					break;
				case 9:
					system("clear");
					printf("\t\tLIST %d",choiceNode);
					numberOfNodes=count_nodes_in_list();
					make_circular_list();
					break;
				case 10:
					do
					{
						system("clear");
						printf("\t\tLIST %d",choiceNode);
						__fpurge(stdin);
						printf("\nEnter position that you want to delete from circular linked list :");
					}while(scanf("%d%c", &pos, &term) != 2 || term != '\n');
					delete_node_from_circular_list(pos%numberOfNodes);
					break;
				case 11:
					do
					{
						system("clear");
						printf("\t\tLIST %d",choiceNode);
						__fpurge(stdin);
						printf("\nEnter position on which you want to insert Element in circular linked list :");
					}while(scanf("%d%c", &pos, &term) != 2 || term != '\n');
					do
						{
							__fpurge(stdin);
							printf("\nEnter data you want to insert: ");
						}while(scanf("%d%c", &data, &term) != 2 || term != '\n');
					insert_node_in_circular_list(pos%numberOfNodes,data);
					break;
				case 12:
					system("clear");
					printf("\t\tLIST %d",choiceNode);
					display_circular_list();
					break;
				case 13:
					system("clear");
					printf("\t\tLIST %d",choiceNode);
					remove_duplicate_elements_from_list();
					break;
				case 14:
					system("clear");
					printf("\t\tLIST %d",choiceNode);
					do
					{
						__fpurge(stdin);
						printf("\nEnter which lists you want to concatenate \n(After Concatenate the resultant List will be Stored in both the Lists) \nList 1: ");
					}while(scanf("%d%c", &num1, &term) != 2 || term != '\n');
					do
					{
						__fpurge(stdin);
						printf("\nList 2: ");
					}while(scanf("%d%c", &num2, &term) != 2 || term != '\n');
					concatenate_list(num1,num2);
					break;
				case 15:
					system("clear");
					printf("\t\tLIST %d",choiceNode);
					do
					{
						__fpurge(stdin);
						printf("\nEnter which lists you want to compare \nList 1: ");
					}while(scanf("%d%c", &num1, &term) != 2 || term != '\n');
					do
					{
						__fpurge(stdin);
						printf("\nList 2: ");
					}while(scanf("%d%c", &num2, &term) != 2 || term != '\n');
					compare_list(num1,num2);
					break;
				case 16:
                                        system("clear");
                                        printf("\t\tSTACK %d",choiceNode);
					flag=detect_loop_in_list();
					if(flag==1)
						printf("\nList can't be displayed as stack");    
					else
						display_stack();     
                                        break;
				case 17:
                                        system("clear");
                                        printf("\t\tSTACK %d",choiceNode);
                                        flag=detect_loop_in_list();
                                        if(flag==1)
                                                printf("\nOperation can't be performed");
                                        else
					{
						do
						{
							__fpurge(stdin);
							printf("\nEnter data you want to Push in Stack: ");
						}while(scanf("%d%c", &data, &term) != 2 || term != '\n');
						element=insert_in_stack(data);
						printf("\nElement %d succesfully Pushed in STACK ",element);
					}
                                        break;
				case 18:
                                        system("clear");
                                        printf("\t\tSTACK %d",choiceNode);
                                        flag=detect_loop_in_list();
                                        if(flag==1)
                                                printf("\nOperation can't be performed");
                                        else
                                        {
                                                element=delete_from_stack();
						if(element == -99)
							printf("\nUnderflow. Can't perform this operation");
						else
                                                	printf("\nElement %d succesfully Poped from STACK ",element);
                                        }
                                        break;
				case 19:
                                        system("clear");
                                        printf("\t\tQUEUE %d",choiceNode);
                                        flag=detect_loop_in_list();
                                        if(flag==1)
                                                printf("\nList can't be converted to Queue");
                                        else
                                                convert_list_to_queue();
                                        break;
				case 20:
                                        system("clear");
                                        printf("\t\tQUEUE %d",choiceNode);
                                        flag=detect_loop_in_list();
                                        if(flag==1)
                                                printf("\nCan't Insert in Queue");
                                        else
					{
						do
						{
							__fpurge(stdin);
							printf("\nEnter data you want to insert: ");
						}while(scanf("%d%c", &data, &term) != 2 || term != '\n');
                                                element=insert_in_queue(data);
						if(element == -99)
                                                        printf("\nCan't perform this operation. First covert List to Queue");
                                                else
                                                        printf("\nElement %d succesfully Inserted in Queue",element);
					}	
                                        break;
				case 21:
                                        system("clear");
                                        printf("\t\tQUEUE %d",choiceNode);
                                        flag=detect_loop_in_list();
                                        if(flag==1)
                                                printf("\nCan't Delete from Queue");
                                        else
                                                element=delete_from_queue();
						if(element == -99)
                                                        printf("\nUnderflow. Can't perform this operation");
                                                else
                                                        printf("\nElement %d succesfully Deleted from Queue",element);
                                        break;
				case 22:
					system("clear");
                                        printf("\t\tQUEUE %d",choiceNode);
                                        display_queue();
                                        break;
				case 23:
                                        system("clear");
                                        printf("\t\tSTACK %d",choiceNode);
					total_nodes=count_nodes_in_list();
					printf("\nTotal elements in Stack are :%d",total_nodes);        
                                        break;
				case 24:
                                        system("clear");
                                        printf("\t\tQUEUE %d",choiceNode);
					total_nodes=count_nodes_in_list();
					printf("\nTotal elements in Queue are :%d",total_nodes);        
                                        break;
				default :
					system("clear");
					printf("\t\tLIST %d",choiceNode);
					printf("\nWrong Choice !!!!");
					break;
			}
			__fpurge(stdin);
			*(start_node+choiceNode-1)=start;
			printf("\nEnter y to continue operation with List %d : ",choiceNode);
			scanf(" %c",&choice_list);
		}while(choice_list=='y' || choice_list=='Y');
		__fpurge(stdin);
		system("clear");
		printf("\nEnter y to continue Operations with Linked Lists, Stacks and Queues :");
		scanf(" %c",&ch);
		}while(ch=='y' || ch=='Y');
		break;
	case 2:
		do
        	{
                	system("clear");
                	__fpurge(stdin);
                	printf("\nEnter number of Trees :");
        	}while(scanf("%d%c", &number_of_trees, &term) != 2 || term != '\n');
        	start_node=malloc(number_of_trees*sizeof(struct _tree_node *));
        	do
        	{
                	tree_choiceNode=choose_list(number_of_trees);
                	root=*(root_node+tree_choiceNode-1);
                	__fpurge(stdin);
                	do
                	{
                        	do
                        	{
                                __fpurge(stdin);
                                system("clear");
                                printf("\t\tTREE %d",tree_choiceNode);
                                printf("\n\t\tMenu\n\t1. Create Tree\n\t2. Preorder Traversal\n\t3. Inorder Traversal\n\t4. Postorder Traversal\n\t5. Search Value in tree\n\t6. Delete a Node from tree or Delete a value from Tree\n\t7. Calculate Depth of Tree\n\t8. Delete complete Binary Search Tree\n\n\tEnter your choice : ");
                        }while(scanf("%d%c", &choice , &term) !=2 || term != '\n');
                        switch(choice)
			{
				case 1:
					do
                                        {
                                                system("clear");
                                                printf("\t\tTREE %d",tree_choiceNode);
						do
       						{
                					__fpurge(stdin);
                					printf("\nEnter value : ");
        					}while(scanf("%d%c", &value, &term) != 2 || term != '\n');
                                                tree_ptr=create_tree_node(value);
                                                create_tree(tree_ptr);
                                                printf("\nEnter y to enter more nodes :");
                                                scanf(" %c",&chc);
                                        }while(chc=='y' || chc=='Y');					
					break;
				case 2:
					system("clear");
                                        printf("\t\tTREE %d\nPreorder Traversal is :",tree_choiceNode);
					preorder(root);
					break;
				case 3:
                                        system("clear");
                                        printf("\t\tTREE %d\nInorder Traversal is:",tree_choiceNode);
                                        inorder(root);
                                        break;
				case 4:
                                        system("clear");
                                        printf("\t\tTREE %d\nPostorder Traversal is:",tree_choiceNode);
                                        postorder(root);
                                        break;
				case 5:
                                        system("clear");
                                        printf("\t\tTREE %d:",tree_choiceNode);
					do
       					{
                					__fpurge(stdin);
                					printf("\nEnter value you want to search in Tree : ");
        				}while(scanf("%d%c", &value, &term) != 2 || term != '\n');
                                        data=search_in_tree(value);
					if(data == 0)
						printf("\nValue not found in Tree");
					else
						printf("\nValue found at level: %d",data);
                                        break;
				case 6:
                                        system("clear");
                                        printf("\t\tTREE %d",tree_choiceNode);
					do
       					{
                					__fpurge(stdin);
                					printf("\nEnter value you want to remove from Tree : ");
        				}while(scanf("%d%c", &value, &term) != 2 || term != '\n');
                                        data=search_in_tree(value);
					if(data == 0)
						printf("\nValue not found in Tree");
					else
					{
						printf("\nValue found at level %d and deleted successfully",data);
						delete_from_tree(root,value);
					}
                                        break;
				case 7:
                                        system("clear");
                                        printf("\t\tTREE %d",tree_choiceNode);
                                        data=count_tree_depth(root);
					printf("\nDepth of tree is :%d",data);
                                        break;
				case 8:
                                        system("clear");
                                        printf("\t\tTREE %d",tree_choiceNode);
                                        delete_complete_tree(root);
					root=NULL;
					printf("\nBinary Search Tree Deleted");
					break;
				default:
					printf("\nWrong choice!!!");
					break;
			}
			__fpurge(stdin);
                        *(root_node+tree_choiceNode-1)=root;
                        printf("\nEnter y to continue operation with Tree %d : ",tree_choiceNode);
                        scanf(" %c",&tree_choice_list);
         	       }while(tree_choice_list=='y' || tree_choice_list=='Y');
                __fpurge(stdin);
                system("clear");
                printf("\nEnter y to continue operations with trees :");
                scanf(" %c",&tree_ch);
        	}while(tree_ch=='y' || tree_ch=='Y');
		break;
	default :
		printf("\nWrong Choice!!!");
	}
	printf("\nEnter y to continue with program :");
        scanf(" %c",&program_continue);
        }while(program_continue == 'y' || program_continue == 'Y');	
}
