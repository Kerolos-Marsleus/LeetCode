#include <vector>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void collectLevels(const TreeNode* node,std::size_t depth,std::vector<std::vector<int>>& levels);
std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
    std::vector<std::vector<int>> ans;
    collectLevels(root,0,ans);
    std::reverse(ans.begin(),ans.end());
    return ans;
}
void collectLevels(const TreeNode* node,std::size_t depth,std::vector<std::vector<int>>& levels){
    if(node == nullptr){
        return;
    }
    if(levels.size() == depth){
        levels.emplace_back();
    }
    levels[depth].push_back(node->val);
    collectLevels(node->left, depth+1, levels);
    collectLevels(node->right, depth+1, levels);
}
