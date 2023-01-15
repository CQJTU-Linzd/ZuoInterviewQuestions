// 树的节点有黑有白 删除白节点 保留黑节点及其路径

// 二叉树形式
class DeleteAndSaveNode {
public:
    TreeNode* deleteAndSaveNode(TreeNode* root) {
        return process(root);
    }
    TreeNode* process(TreeNode* head) {
        if (!head) return nullptr;
        if (!head->left && !head->right) {
            return head->save ? head : nullptr;
        }
        head->left = process(head->left);
        head->right = process(head->right);
        if (!head->left && !head->right) {
            return head->save ? head : nullptr;
        } else {
            head->save = true;
            return head;
        }
    }
};

// 多叉树形式
class Node {
public:
    int val;
    bool retain;
    vector<Node*>nexts;
    Node(int v, bool r) {
        val = v;
        retain = r;
    }
};
class DeleteAndSaveNode2 {
public:
    Node* deleteAndSaveNode2(Node* root) {
        return process(root);
    }
    Node* process(Node* head) {
        if (head->nexts.empty()) {
            return head->retain ? head : nullptr;
        }
        vector<Node*>newNexts;
        for (Node* next : head->nexts) {
            Node* newNext = process(next);
            if (newNext) {
                newNexts.push_back(newNext);
            }
        }
        if (!newNexts.empty() || head->retain) {
            head->nexts = newNexts;
            return head;
        }
        return nullptr;
    }
};
