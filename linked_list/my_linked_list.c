#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int val;
	struct Node* next;
};

void append(struct Node** head_ref, int val) {
	struct Node* curr = *head_ref;
	struct Node* temp =(struct Node*) malloc(sizeof(struct Node));
	temp->val = val;

	if(*head_ref == NULL) {
		*head_ref = temp;
		return;
	}

	while(curr->next != NULL) {
		curr=curr->next;
	}

	curr->next = temp;
}

void insertFirst(struct Node** head_ref, int val) {
	struct Node* temp =(struct Node*) malloc(sizeof(struct Node));
	temp->val = val;

	temp->next = *head_ref;
	*head_ref = temp;


}

struct Node* pop(struct Node** head_ref) {
	struct Node* temp = *head_ref;

	*head_ref = (*head_ref)->next;
	return temp;

}

void deleteNode(struct Node** head_ref, int val) {
	struct Node* temp = *head_ref;
	struct Node* prev = *head_ref;
	
	if((*head_ref)->val == val) {
		*head_ref = (*head_ref)->next;
	}

	while(temp != NULL && temp->val != val) {
		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;
}


void delete(struct Node** head_ref, int val) {
	struct Node* temp = *head_ref;
	struct Node* prev = *head_ref;
	
	while(temp != NULL) {
		if((*head_ref)->val == val) {
			*head_ref = temp->next;
		}

		while(temp != NULL && temp->val != val) {
			prev = temp;
			temp = temp->next;
		}	
		
		if(temp == NULL) {
			return;
		}

		prev->next = temp->next;
		temp = temp->next;
	}
	
}

void clear(struct Node** head_ref) {
	*head_ref = NULL;
	free(*head_ref);
}

void print(struct Node* head) {
	struct Node* temp = head;
	printf("[ ");
	while(temp != NULL) {
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("]\n");
}

int main(int argc, char const *argv[])
{
	struct Node* lst = NULL; // (struct Node*) malloc(sizeof(struct Node*));

	//insertFirst(&lst, 1);
	//insertFirst(&lst, 2);
	//insertFirst(&lst, 3);

	for(int i = 0; i < 5; i++)
		append(&lst, i+1);	
	
	append(&lst, 2);
	append(&lst, 2);
	append(&lst, 2);
	append(&lst, 2);
	append(&lst, 2);

	append(&lst, 1);
	append(&lst, 1);
	append(&lst, 1);

	insertFirst(&lst, 1);
	insertFirst(&lst, 1);

	print(lst);
	pop(&lst);
	print(lst);

	delete(&lst, 2);
	delete(&lst, 1);

	print(lst);
	return 0;
}