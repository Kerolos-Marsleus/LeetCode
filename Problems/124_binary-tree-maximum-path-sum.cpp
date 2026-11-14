#include <algorithm>

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

    int maxHelper(TreeNode *root, int& max_){
        if(root == nullptr)return 0;
        int left = std::max(maxHelper(root->left, max_),0);
        int right = std::max(maxHelper(root->right,max_),0);
        int bent = left + right + root->val;
        max_ = std::max(max_, bent);
        return  (root->val) + std::max(left, right);
    
    }
    int maxPathSum(TreeNode* root) {
        int best = root->val;
        (void)maxHelper(root,best);
        return best;
    }
};