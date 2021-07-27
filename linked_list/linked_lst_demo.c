#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct node 
{
	int data;
	struct node *next;
};

struct node *head = NULL;

void insertFirst(int data) {
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	
	temp->next = head;

	head = temp;
}

void insertAfter(struct node* prev_node, int data) {
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;

	temp->next = prev_node->next;
	prev_node->next = temp;
}

struct node* getNode(int data) {
	struct node* temp = head;
	while(temp != NULL) {
		if(temp->data == data)
			return temp;
		temp = temp->next;
	}

	return NULL;
}

void append(int data) {
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	struct node *tail = head;
	temp->data = data;
	temp->next = NULL;

	if(head == NULL) {
		head = temp;
		return;
	}

	while(tail->next != NULL)
		tail = tail->next;

	tail->next = temp;
	tail = temp;
	return;
}

struct node *deleteFirst() {
	struct node *temp = head;

	head = temp->next;

	return temp;
}

void delete(int data) {
	struct node* prev = NULL;
	struct node* temp = head;

	if(head->data == data) {
		head = temp->next;

		free(temp);
		return;
	}

	while(temp != NULL && temp->data != data) {
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL) {
		return;
	}

	prev->next = temp->next;

	free(temp);
}

void deleteAll(int val){
    struct node* temp = head;
    struct node* prev = NULL;
    
    if(head == NULL)
        return;
    
    while(temp->next != NULL) {
        if(temp->next->data == val) {
            temp->next = temp->next->next;
        
        } else {
            temp= temp->next;
        }

    }	
    
    temp = head;
    if(temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        
    }
}

bool contains(int data) {
	struct node *temp = head;

	while(temp != NULL) {
		if(temp->data == data)
			return true;
		temp = temp->next;
	}
	return false;
}
void printList() {
	struct node *temp = head;

	printf("[");
	while(temp != NULL) {
		if(temp->next == NULL) {
			printf("%d", temp->data);
			break;
		}
		printf("%d, ", temp->data);
		temp = temp->next;
	}
	printf("]\n");
}

int main(int argc, char const *argv[])
{
	append(11);
	append(11);
	append(11);
	append(12);
	append(13);

	struct node* temp = getNode(12);

	insertAfter(temp, 37);
	
	printList();	
	deleteAll(11);
	printList();

	//if(contains(44))
	//	printf("Yes contains 45\n");
	//else
	//	printf("No sorry\n");
	return 0;
}