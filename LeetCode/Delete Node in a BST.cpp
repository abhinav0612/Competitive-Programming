/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        TreeNode *temp = root;
        TreeNode *prev = NULL;
        while(temp != NULL){
            if(temp->val == key){
                break;
            }
            prev = temp;
            if(temp->val > key)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if(temp == NULL)
            return root;
        if(temp->right == NULL && temp->left == NULL)
        {
            if(prev!=NULL){
                if(prev->right == temp){
                   //cout<<"right = temp";
                   prev->right=NULL; 
                } 
                else{
                    //cout<<"left = temp";
                    cout<<prev->left->val;
                    prev->left = NULL; 
                    //cout<<prev->left->val;
                }
                
                //cout<<prev->right->val;
            }
            
            else
                return NULL;
        }
        else if(temp->right == NULL){
            if(prev){
                if(prev->right == temp)
                    prev->right=temp->left;
                else
                    prev->left = temp->left;  
            }
            else
                return temp->left;
          
        } 
        else if(temp->left == NULL){
           // cout<<prev->val;
            if(prev){
                if(prev->right == temp)
                    prev->right=temp->right;
                else
                    prev->left = temp->right;  
                //cout<<prev->left->val;
            }
            else
                return temp->right;
        }
        else{
            TreeNode *successor = inorderSuccessor(temp->right);
           // cout<<successor->val;
            temp->val = successor->val;
            temp->right = deleteNode(temp->right,temp->val);
        }
        return root;
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root){
        TreeNode *temp = root;
        while(temp->left != NULL)
            temp = temp->left;
        return temp;
    }
};