#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:

    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->value= data;
        this->left= NULL;
        this->right= NULL;
        
    }
};


class Solution{

    public:

    void inOrder(TreeNode* root, vector<int>& v){
        if(root==NULL) return;
        inOrder(root->left,v);
        v.push_back(root->value);
        inOrder(root->right,v);
    }

    int kthSmallestInBst(TreeNode* root, int k){
        vector<int> v;
        inOrder(root,v);
        if(k>=v.size() || k<=0) return -1;
        return v[k-1];

    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    Solution s;
    cout << s.kthSmallestInBst(root, 3) << endl;

    return 0;
}


//T.C= O(N)
//S.C= O(H)+O(N)=> Recursion stack+ vector