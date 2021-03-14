/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    
    //if both null
    if (p == NULL && q == NULL){
        return  true;
    }
    
    //if one of them is null
    if (p == NULL || q == NULL){
        return false;
    }
    
    //this line execution means both nodes have value
    if (p->val != q->val)
        return false;
    
    //both have values and are same. 
    
    return isSameTree(p->left, q->left) &&
        isSameTree(p->right, q->right);

}
