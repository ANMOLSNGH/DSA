#include<bits/stdc++.h>
using namespace std;
  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class BSTIterator {
    void pushstack(TreeNode* root, stack<TreeNode*>&s){
        while(root != nullptr){
            s.push(root);
            root = root->left;
        }
    }
public:
    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
        pushstack(root,s);
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        pushstack(temp->right, s);
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};