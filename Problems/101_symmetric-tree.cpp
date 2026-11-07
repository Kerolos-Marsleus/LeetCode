
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
    bool isSymmetric(TreeNode* root) {
        return mirror(root, root);
    }
    
    bool mirror(TreeNode* lef, TreeNode* rig){
        if(lef == nullptr && rig == nullptr) return true;
        if(lef == nullptr || rig == nullptr) return false;
        
        return (lef->val == rig->val) && mirror(lef->left, rig->right) && mirror(lef->right, rig->left);
    }
};