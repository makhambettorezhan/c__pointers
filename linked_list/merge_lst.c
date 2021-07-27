/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* head = NULL;

void append(struct ListNode** head_ref, int val) {
    struct ListNode* tail = *head_ref;
    struct ListNode* temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next = NULL;
    
    if(*head_ref == NULL) {
        *head_ref = temp;
        return;
    }
    
    while(tail->next != NULL) {
        tail = tail->next;
    }
    
    tail->next = temp;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode* temp;
    
    if(l1 == NULL) 
        return l2;
    
    if(l2 == NULL) 
        return l1;
    
    while(l1 != NULL && l2 != NULL) {
        
        if(l1->val < l2->val) {
            append(&head, l1->val);
            l1=l1->next;
        } else if(l1->val > l2->val) {
            append(&head, l2->val);
            l2=l2->next;
        } else {
            
            append(&head, l1->val);
            append(&head, l2->val);
            l1=l1->next;
            l2=l2->next;
        }
    }
    
    if(l1 != NULL) {
        while(l1 != NULL) {
            append(&head, l1->val);
            l1=l1->next;
        }
    }
    
    if(l2 != NULL) {
        while(l2 != NULL) {
            append(&head, l2->val);
            l2=l2->next;
        }
    }
    return head;
}

void printList(struct ListNode* head) {
    struct ListNode *temp = head;

    printf("[");
    while(temp != NULL) {
        if(temp->next == NULL) {
            printf("%d", temp->val);
            break;
        }
        printf("%d, ", temp->val);
        temp = temp->next;
    }
    printf("]\n");
}

int main(int argc, char const *argv[])
{
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;


    /*for(int i = 0; i < 4; i++) {
        append(&l1, i+1);
        append(&l2, i+4);
    }*/

    append(&l1, 2);
    append(&l2, 1);

    printf("Before insertion:\n");
    printList(l1);
    printList(l2);

    printf("After insertion:\n");
    
    struct ListNode* merged = mergeTwoLists(l1, l2);

    printList(merged);    
    return 0;
}