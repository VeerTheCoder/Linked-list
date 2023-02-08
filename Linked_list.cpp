//Code implementation for Linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
}*root=NULL;
void append();	//Add Node at the end
void addBeginning();	//Add Node at the beginning
void addAfter();	//Add Node at somewhere in the middle
void del();			//To delete the Node
void reverse_list();	//To reverse the list
int length();	// To find the number of Nodes
void display();	//To display all the nodes
void search();	//To search the element
int main(){
	int c,l;
	printf("Press 1. for add node at the end\n");
	printf("Press 2. for add node at the beginning\n");
	printf("Press 3. for add node at the middle\n");
	printf("Press 4. to delete the node\n");
	printf("Press 5. to display the data\n");
	printf("Press 6. to find the length\n");
	printf("Press 7. to Reverse the List\n");
	printf("Press 8. to search element\n");
	printf("Press 9. to exit\n");
	while(1){
		printf("Enter your choice:");
		scanf("%d",&c);
		switch(c){
			case 1:
				append();
				break;
			case 2:
				addBeginning();
				break;
			case 3:
				addAfter();
				break;
			case 4:
				del();
				break;
			case 5:
				display();
				break;
			case 6:
				l=length();
				printf("Length=%d\n",l);
				break;
			case 7:
				reverse_list();
				break;
			case 8:
				search();
				break;
			case 9:
				exit(0);
			default:
				printf("Invalid Input\n");
		}
	}
	return 0;
}
void append(){
	struct node *temp;	//structure type pointer variable
	temp=(struct node *)malloc(sizeof(struct node));	//Node Creation and typecasted into structure
	printf("Enter Data:");
	scanf("%d",&temp->data);	//Adding data to the data field of Node
	temp->link=NULL;		//Assign NULL value to the link field of Node
	if(root==NULL)
		root=temp;
	else{
		struct node *ptr;
		ptr=root;
		while(ptr->link!=NULL){
			ptr=ptr->link;		//reaches to the last Node
		}
		ptr->link=temp;
	}
	printf("Inserted data is %d\n",temp->data);
}
void addBeginning(){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));	//Node Creation
	printf("Enter Data:");
	scanf("%d",&temp->data);	//Adding data to the data field of Node
	temp->link=NULL;			//Assign NULL value to the link field of Node
	if(root==NULL)
		root=temp;
	else{
		temp->link=root;	//NULL replace with root and hold the address of first Node
		root=temp;		//Become the first Node
	}
	printf("Inserted data is %d\n",temp->data);
}
void addAfter(){
	int pos,l=length(),i=1;	
	printf("Enter Position:");
	scanf("%d",&pos);	//Position, where user want to insert data
	if(pos>l)		//when position is larger than the number of nodes
		printf("No Such Position available...There are only %d nodes\n",l);
	else if(pos==1 || pos==l)
		printf("For this position the choice is already given\n");
	else{
		struct node *temp,*p;	//first variable for Node and second one is to reach position
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter Data:");
		scanf("%d",&temp->data);
		temp->link=NULL;
		p=root;
		while(i<pos-1){	
			i++;
			p=p->link;		//jump to just before Node
		}
		temp->link=p->link;
		p->link=temp;
		printf("Inserted Data is %d\n",temp->data);
	}
}
void del(){
	int pos,i=1;
	printf("Enter node's position to delete:");
	scanf("%d",&pos);
	if(pos>length())
		printf("This positon not available...only %d nodes are there\n",length());
	else{
		struct node *temp,*p;
		temp=root;
		if(pos==1){			//to delete the first node
			root=temp->link;	//root points to the 2nd node
			temp->link=NULL;
			free(temp);
			printf("Node is successfully deleted\n");
		}
		else{
			while(i<pos-1){
				i++;
				temp=temp->link;		//jump to behind the node that will be deleted
			}
			p=temp->link;		//p points to node that will be deleted
			temp->link=p->link;		//it points to next node of deleted node 
			p->link=NULL;
			free(p);
			printf("Node is successfully deleted\n");
		}
	}
}
void reverse_list(){
	int i,j,len=length();
	i=0;
	j=len-1;
	if(root==NULL){
		printf("List not exist\n");
	}
	else{
		struct node *p,*q;
		p=q=root;
		int temp,k;
		while(i<j){		//to reverse
			k=0;
			while(k<j){		//to jump to last node if it's not swapped
				k++;
				q=q->link;	
			}
			//Swapping the data
			temp=p->data;
			p->data=q->data;
			q->data=temp;
			i++;
			j--;
			p=p->link;		//jump to next node
			q=root;		//jump to first node
		}
		printf("List is Reversed\n");
	}
}
int length(){
	int len=0;
	struct node *t;		//structure type pointer varibale
	t=root;
	while(t!=NULL){
		len++;
		t=t->link;		//jump to the next Node
	}	
	return len;
}
void display(){
	struct node *p;
	p=root;
	if(root==NULL)
		printf("No node Available\n");
	else{
		while(p!=NULL){
			printf("%d ",p->data);
			p=p->link;		//Jump to the next Node
		}
		printf("\n");
	}
}
void search(){
	if(root==NULL)
		printf("List not available\n");
	else{
		int e,f=0,p=1;
		struct node *s;
		s=root;
		printf("Enter element to search:");
		scanf("%d",&e);
		while(s!=NULL){
			if(s->data==e){
				printf("Data is found at %d position\n",p);
				f=1;
				break;
			}
			p++;
			s=s->link;
		}
		if(f==0)
			printf("Data not found\n");
	}
	
}
