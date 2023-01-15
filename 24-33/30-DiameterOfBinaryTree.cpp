// 二叉树任意两节点之间距离的最大值
class MaxDistance {
public:
    class Info {
    public:
        int maxDistance;
        int height;
        Info(int d, int h) {
            maxDistance = d;
            height = h;
        }
    };
    int maxDistance(TreeNode* root) {
        return process(root).maxDistance;
    }
    Info process(TreeNode* head) {
        if (!head) {
            return Info(0, 0);
        }
        Info leftInfo = process(head->left);
        Info rightInfo = process(head->right);
        int height = 1 + max(leftInfo.height, rightInfo.height);
        int p1 = max(leftInfo.maxDistance, rightInfo.maxDistance);
        int p2 = leftInfo.height + 1 + rightInfo.height;
        int maxDistance = max(p1, p2);
        return Info(maxDistance, height);
    }
};
