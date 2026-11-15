#include <limits>
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
    struct Info {
    bool isBst;
    int  min;
    int  max;
    int  sum;
    };
    int maxSumBST(TreeNode* root) {
        int best = 0;
        (void)max_helper(root, best);
        return best;
    }

    Info max_helper(TreeNode* node, int&best){
        if(node == nullptr){
            return {true,std::numeric_limits<int>::max(), std::numeric_limits<int>::min(), 0};
        }
        Info left = max_helper(node->left, best);
        Info right = max_helper(node->right,best);
        
        if(left.isBst && right.isBst){
            if((node->val <= left.max) || (node->val >= right.min)){
                return {false,0,0,0};
            }

            const int _min = std::min(node->val, left.min);
            const int _max = std::max(node->val, right.max);
            const int sum = node->val + left.sum + right.sum;
            best = std::max(best, sum);
            return {true, _min, _max, sum};
        }
        return {false,0,0,0};
    }
        
    
};