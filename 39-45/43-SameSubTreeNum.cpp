// 对某一个头节点，如果它的左子树和右子树完全相同，则认为是一个相等树
// 求某一棵树所有相等子树的数量
class SameSubTree {
public:
    int sameNumber(TreeNode* root) {
        return process(root);
    }
    int process(TreeNode* head) {
        if (!head) {
            return 0;
        }
        int leftNum = process(head->left);
        int rightNum = process(head->right);
        return leftNum + rightNum + (same(head->left, head->right) ? 1 : 0);
    }
    bool same(TreeNode* h1, TreeNode* h2) {
        if ((h1 == nullptr) ^ (h2 == nullptr)) { // 一个空 一个不空
            return false;
        }
        if (!h1 && !h2) {
            return true;
        }
        return h1->val == h2->val && same(h1->left, h2->left) && same(h1->right, h2->right);
    }
};
