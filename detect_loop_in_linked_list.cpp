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
	(*head) = new_node;
}

bool detect(node* head)
{
	node* slow = head;
	node* fast = head;
	while(slow && fast && fast->next)
	{
		slow= slow->next;
		fast= fast->next->next;
		if(slow==fast)
		{
			return true;
		}
		
	}
	
	return false;
}

int main() {
	
	node* head = NULL;
	push(&head,4);
	push(&head,10);
	push(&head,15);
	push(&head,20);
	
	//head->next->next=head;
	if(detect(head))
	{
		cout<<"found";
	}
	else
	{
		cout<<"not found";
	}
	
	return 0;
}
