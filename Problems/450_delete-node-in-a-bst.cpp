
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
    TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;

    if (key > root->val) {
        root->right = deleteNode(root->right, key);
        return root;
    }
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
        return root;
    }

    // no or one child
    if (root->left == nullptr) {
        TreeNode* child = root->right;
        delete root;
        return child;
    }
    if (root->right == nullptr) {
        TreeNode* child = root->left;
        delete root;
        return child;
    }

    // two children
    TreeNode* succ = root->right;
    while (succ->left != nullptr) succ = succ->left;
    root->val = succ->val;
    root->right = deleteNode(root->right, succ->val);
    return root;
}
};
