#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define COUNT 10 

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

//struct TreeNode* root = NULL;

struct TreeNode* createNote(int val) {
	struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
	newNode->val = val;
	newNode->left = newNode->right = NULL;

	return newNode;
}

struct TreeNode* findMin(struct TreeNode* root) {
	if(root == NULL) return root;
	while(root->left != NULL) {
		root=root->left;
	}
	return root;
}
struct TreeNode* delete(struct TreeNode* root, int val) {
	if(root == NULL) return root;
	else if(val < root->val) root->left = delete(root->left, val);
	else if(val > root->val) root->right = delete(root->right, val);
	else {
		if(root->left == NULL && root->right == NULL) { // Leaf case: No Child
			free(root);
			root = NULL;
			return root;
		} else if(root->right == NULL) { // delete root with left child
			struct TreeNode* temp = root;
			root = root->left;
			free(temp);
			return root;
		} else if(root->left == NULL) { // delete root with right child
			struct TreeNode* temp = root;
			root = root->right;
			free(temp);
			return root;
		} 
		// case 3: 2 children
		else {
			struct TreeNode* temp = findMin(root->right);
			root->val = temp->val;
			root->right = delete(root->right, temp->val);
		}
	}
}
int search(struct TreeNode* root, int val) {
	if(root == NULL) return 0;
	if(root->val == val) return 1;
	else if(val <= root->val) return search(root->left, val);
	else return search(root->right, val);
}

void inorder(struct TreeNode* root) {
	
	if(root->left != NULL)
		inorder(root->left);
	printf("%d ", root->val);

	if(root->right != NULL)
		inorder(root->right);

}

void print2DUtil(struct TreeNode *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->val); 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 

struct TreeNode* insert(struct TreeNode* root, int val) {
	if(root == NULL) {
		root = createNote(val);
	} else if(val <= root->val) {
		root->left = insert(root->left, val);
	} else {
		root->right = insert(root->right, val);
	}
	
	return root;

}

int getSum(struct TreeNode* root) {
	if(root == NULL)
		return 0;
	else
		return root->val + getSum(root->left) + getSum(root->right);
}

int height(struct TreeNode* root) {
	if(root == NULL)
		return 0;
	int h1 = height(root->left);
	int h2 = height(root->right);

	return h1 > h2 ? 1 + h1 : 1+ h2;
}

int main(int argc, char const *argv[])
{
	
	struct TreeNode* root = NULL;
	root = insert(root, 7);
	root = insert(root, 3);
	root = insert(root, 9);
	root = insert(root, 1);
	root = insert(root, 4);
	root = insert(root, 6);
	root = insert(root, 11);



	//print2DUtil(root, 0);
	delete(root, 3);

	printf("Sum = %d", height(root));

	printf("\n");
	//print2DUtil(root, 0);


	return 0;
}