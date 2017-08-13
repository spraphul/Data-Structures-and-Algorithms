#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
typedef struct node node;

void push(node** head, int new_data)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = new_data;
	new_node->next = (*head);
	(*head)=new_node;
	
}

node* reverse(node* head)
{
	node* current = head;
	node* prev = NULL;
	node* next = NULL;
	while(current!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		
	}
	return prev;
}

void print(node* head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->"<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}

int main() {
	
	node* head = NULL;
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	print(head);
	node* new_head=reverse(head);
	print(new_head);
	// your code goes here
	return 0;
}
