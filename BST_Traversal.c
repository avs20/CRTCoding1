#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *left, *right; 
};

//Creating a node 
struct node * newNode(int value){
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp -> value = value;
  temp-> left = NULL;
  temp->right = NULL;
  return temp;
}


//Inorder traversal
void inorder(struct node *root){
  if (root != NULL){
    inorder(root->left);
    printf("%d-->", root->value);
    inorder(root->right);
   }
  
}

//Preporder traversal
void preorder(struct node *root){
  if (root != NULL){
        printf("%d-->", root->value);

    inorder(root->left);
    inorder(root->right);
   }
  
}

//Postorder traversal
void postorder(struct node *root){
  if (root != NULL){
    inorder(root->left);
    inorder(root->right);
        printf("%d-->", root->value);

   }
  
}


//Insertion function
//returns the node 
struct node * insert( struct node *node, int value){
  //if tree is empty return a new node 
  if (node == NULL) {
    return newNode(value);
  }

  //find the correct place to insert the node 
  if (value < node->value) 
      node->left = insert(node->left, value);
  else 
      node->right = insert(node->right, value);

  return node;

}

//Searching in a BST 
int contains(struct node *root, int target){

  if (root == NULL) return 0;

  if (root->value == target){
    return 1;
  }else if (target < root->value){
    return contains(root->left, target);
  }else{
    return contains(root->right, target);
  }

  return 0 ;// value not found 
}

//function to find minimum value
struct node* findMinValue(struct node* root){
  struct node *currentNode = root;

  // Go to left until you have no left child left
  while (currentNode && currentNode -> left != NULL){
    currentNode = currentNode->left;
  }

  return currentNode;
}

//Deletion in binary search tree
struct node *deleteNode(struct node *root, int target){

  //if the tree is empty
  if (root == NULL) return root;

  if (target < root->value) 
      root->left = deleteNode(root->left, target);
  else if (target > root->value)
      root->right = deleteNode(root->right, target);
  else {
    //we are at the current node to delete 
    if (root->left == NULL){
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root ->right == NULL){
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    //If the node has two children 

    struct node *temp = findMinValue(root->right);

    //replace the current node value with the min value 
    root->value = temp->value;

    //delete the min value from the right sub tree
    root->right = deleteNode(root->right, temp->value);


  }
  return root;
}


int main(void) {
  printf("Hello World\n");

  struct node *root = insert(NULL,10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 23);
  insert(root, 24);
  insert(root, 12);
  inorder(root);
  printf("Searching 12 %d \n", contains(root, 12) );
  printf("Searching 23 %d \n", contains(root, 23) );
  printf("Searching 89 %d \n", contains(root, 89) );
  printf("\n=================");
  root = deleteNode(root, 5);
  inorder(root);
    printf("\n=================");

  root = deleteNode(root, 23);
  inorder(root);
    printf("\n=================");

  root = deleteNode(root, 15);
  inorder(root);

  printf("Order traversal\n");
  root = insert(NULL, 10 );
  insert(root, 5);
  insert(root, 15);
  insert(root, 22);
  insert(root, 2);
  insert(root, 5);
  insert(root, 1);
  printf("\n=====================");

  inorder(root);
  printf("\n=====================");
  preorder(root);
  printf("\n=====================");
  postorder(root);
















  return 0;
}
