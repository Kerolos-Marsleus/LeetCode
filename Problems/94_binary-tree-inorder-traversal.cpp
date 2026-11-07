#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        inorder(root, out);
        return out;
    }

private:
    void inorder(TreeNode* n, vector<int>& out) {
        if (n == nullptr) return;
        inorder(n->left, out);
        out.push_back(n->val);      // moved to the middle: left, node, right
        inorder(n->right, out);
    }
};