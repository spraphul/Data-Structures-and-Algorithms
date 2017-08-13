#include <iostream>
using namespace std;

struct node
{
	char data;
	struct node* next;
};
typedef struct node node;

void push(node** head,char new_data)
{
	node* new_node =(node*)malloc(sizeof(node));
	//new_node* = new node;
	new_node->data=new_data;
	new_node->next=(*head);
	(*head)=new_node;
}

void delete_node(node* p)
{
	node* temp;
	temp=p->next;
	p->data = temp->data;
	p->next=temp->next;
	free(temp);
}

void print(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}



int main() {
	// your code goes here
	node* head = NULL;
	push(&head,'*');
	push(&head,'*');
	push(&head,'*');
	push(&head,'*');
	print(head);
	delete_node(head);
	print(head);
	delete_node(head);
	print(head);
	delete_node(head);
	print(head);
	return 0;
}



//output of code:
// * * * *
// * * *
// * *
// *
