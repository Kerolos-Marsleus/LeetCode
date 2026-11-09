#include <vector>


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
    std::vector<int> postorderTraversal(const TreeNode* root) {
        std::vector<int> out;
        postorder(root, out);
        return out;
    }

private:
    void postorder(const TreeNode* n, std::vector<int>& out) {
        if (n == nullptr) return;
        postorder(n->left, out);
        postorder(n->right, out);
        out.push_back(n->val);      
    }
};