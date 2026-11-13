#include <vector>
#include <unordered_map>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:    
    std::unordered_map<int, int> idMap;
    int preId = 0;
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        
        std::size_t n = inorder.size();
        for(std::size_t i = 0; i < n; ++i){
            idMap[inorder[i]] = static_cast<int> (i);
        }
        preId = 0;
        return build(preorder, 0, static_cast<int>(n) - 1);
    }

    TreeNode* build(std::vector<int>& preorder, int inLow, int inHi){
        if(inLow > inHi)return nullptr;
        TreeNode* node = new TreeNode(preorder[preId++]);
        int rootPosinInorder = idMap.at(node->val);
        node->left = build(preorder, inLow, rootPosinInorder-1);
        node->right = build(preorder, rootPosinInorder+1, inHi);
        return node;
    }
};