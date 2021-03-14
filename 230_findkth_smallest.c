/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeInfo{
    int numNodesVisited;
    int lastVisitedValue;
} ;


void inOrderTraverse(struct TreeNode* root, int k , struct TreeInfo* treeInfo){
    
    if (root == NULL || treeInfo->numNodesVisited >= k ){
        return;
    }
    
    //process the left subtree
    inOrderTraverse(root->left, k, treeInfo);
    
    if (treeInfo -> numNodesVisited < k){
        treeInfo -> numNodesVisited += 1;
        treeInfo -> lastVisitedValue = root->val;
        inOrderTraverse(root->right, k, treeInfo);
    }
    
    
    
}

int kthSmallest(struct TreeNode* root, int k){

        struct TreeInfo* treeInfo =   (struct TreeInfo *)malloc(sizeof(struct TreeInfo));
        treeInfo-> numNodesVisited = 0 ;
        treeInfo-> lastVisitedValue = -1;
    
        inOrderTraverse(root, k, treeInfo);
    
        return treeInfo -> lastVisitedValue;
    
    
}












