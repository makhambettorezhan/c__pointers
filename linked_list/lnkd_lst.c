#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct node 
{
   int data;
   struct node *next;
};

void insertFirst(node** head_ref, int data) {
   struct node *temp = (struct node*) malloc(sizeof(struct node));
   temp->data = data;
   
   temp->next = *head_ref;

   *head_ref = temp;
}

void insertLast(node** head_ref, int data) {
   struct node *temp = (struct node*) malloc(sizeof(struct node));
   struct node *tail = *head_ref;
   temp->data = data;
   temp->next = NULL;

   if (*head_ref == NULL) 
   { 
       *head_ref = new_node; 
       return; 
   } 
   while(tail->next != NULL)
      tail = tail->next;

   tail->next = temp;
   return;
}

struct node *deleteFirst() {
   struct node *temp = head;

   head = temp->next;

   return temp;
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
      printf("%d, ", temp->data);
      temp = temp->next;
   }
   printf("]\n"   );
}
int main(int argc, char const *argv[])
{
   //insertFirst(1);
   //deleteFirst();
   //insertFirst(22);
   //insertFirst(45);
   
// insertFirst(10);
   struct node *head = NULL;

   insertLast(&head, 11);
   insertLast(&head, 12);
   insertLast(&head, 13);

   printList();

   //if(contains(44))
   // printf("Yes contains 45\n");
   //else
   // printf("No sorry\n");
   return 0;
}