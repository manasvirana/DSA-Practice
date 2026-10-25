#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class Codec {
public:
    void preorder(TreeNode* root, string& s) {
        if(root == NULL) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        preorder(root, s);
        return s;
    }

    TreeNode* build(queue<string>& q) {
        string curr = q.front();
        q.pop();

        if(curr == "N") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(curr));
        root->left = build(q);
        root->right = build(q);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string curr;
        queue<string> q;

        while(getline(ss, curr, ',')) {
            if(!curr.empty()) {
                q.push(curr);
            }
        }

        return build(q);
    }
};

void inorder(TreeNode* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Codec c;

    string data = c.serialize(root);
    cout << "Serialized: " << data << endl;

    TreeNode* newRoot = c.deserialize(data);

    cout << "Reconstructed tree (inorder): ";
    inorder(newRoot);
    cout << endl;

    return 0;
}
