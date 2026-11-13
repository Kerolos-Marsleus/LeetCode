#include <vector>
#include <stack>
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
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        if(preorder.empty()){
        return nullptr;
    }
    TreeNode* root = new TreeNode{preorder[0]};
    std::stack<TreeNode*> st;
    st.push(root);
    for(std::size_t i  = 1; i < preorder.size(); i++){
        if(preorder[i] < st.top()->val){
            st.top()->left = new TreeNode{preorder[i]};
            st.push(st.top()->left);
        }else{
            TreeNode* parent = nullptr;
            while(!st.empty() && st.top()->val < preorder[i]){
                parent = st.top();
                st.pop();
            }
            parent->right = new TreeNode{preorder[i]};
            st.push(parent->right);
        }
    }
    return root;
    }
};



