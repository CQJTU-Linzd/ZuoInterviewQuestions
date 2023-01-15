// 返回数组里所有值的最低公共祖先
class Info {
public:
    // 最低公共祖先 
    // 没找到 find = null
    // 找到了，find就是最低公共祖先
    TreeNode* find;
    // 这棵子树上删了几个节点
    int removes;
    Info(TreeNode* f, int r) {
        find = f;
        removes = r;
    }
};
class Lowest {
public:
    unordered_set<int>st;
    TreeNode* LowestAnces(TreeNode* root, vector<int>& nodes) {
        for (int val : nodes) {
            st.insert(val);
        }
        return process(root, nodes.size()).find;
    }
    Info process(TreeNode* head, int all) {
        if (!head) return Info(nullptr, 0);
        Info Left = process(head->left, all);
        Info Right = process(head->right, all);
        if (Left.find) { // 左树找到了最低公共祖先
            return Left;
        }
        if (Right.find) {
            return Right;
        }
        int cur = st.count(head->val) ? 1 : 0;
        if (cur == 1) {
            st.erase(head->val);
        }
        if (Left.removes + Right.removes + cur == all) {
            return Info(head, all);
        } else {
            return Info(nullptr, Left.removes + Right.removes + cur);
        }
    }
};
