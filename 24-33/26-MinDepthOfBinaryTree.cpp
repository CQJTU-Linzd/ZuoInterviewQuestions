// 二叉树最小深度
class minDepth {
public:
    int ans = INT_MAX;
    int getMinDepth(TreeNode* root) {
        process(root, 1);
        return ans;
    }
    void process(TreeNode* head, int curlevel) {
        if (!head->left && !head->right) {
            ans = min(ans, curlevel);
            return;
        }
        if (head->left) {
            process(head->left, curlevel + 1);
        }
        if (head->right) {
            process(head->right, curlevel + 1);
        }
    }
};
