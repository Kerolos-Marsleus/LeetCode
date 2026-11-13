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
    void inorder_helper(const TreeNode *ptr, std::vector<int> &vec)const{
        if(ptr == nullptr){
            return;
        }
        inorder_helper(ptr->left, vec);
        vec.push_back(ptr->val);
        inorder_helper(ptr->right, vec);
    }
    TreeNode* build(const std::vector<int>& vec, int low, int high){
        if(low > high)return nullptr;
        int mid = low + (high-low)/ 2;
        TreeNode* node =new TreeNode{vec[mid]};
        node->left = build(vec,low,mid-1);
        node->right = build(vec,mid+1, high);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> ans;
        inorder_helper(root, ans);
        return build(ans,0,ans.size()-1);
    }
};