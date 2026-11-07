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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> out;
        preorder(root, out);
        return out;
    }

private:
    void preorder(TreeNode* n, vector<int>& out) {
        if (n == nullptr) return;
        out.push_back(n->val);      // your cout line, now push_back
        preorder(n->left, out);
        preorder(n->right, out);
    }
};