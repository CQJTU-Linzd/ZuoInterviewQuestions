// 67 n个有序数组选n个数，彼此相减的绝对值之和最小
class MinRange {
public:
    class Node {
    public:
        int val;
        int index; // 在自己数组中的下标
        int arrindex; // 这个数来自哪个数组
        Node(int v, int i, int ai) {
            val = v;
            index = i;
            arrindex = ai;
        }
    };
    class Cmp {
    public:
        bool operator()(Node& a, Node& b) {
            return a.val != b.val ? (a.val < b.val) : (&a.index < &b.index);
        }
    };

    int minRange(vector<vector<int>>& matrix) {
        for (vector<int> nums : matrix) {
            if (nums.empty()) {
                return -1;
            }
        }
        int n = matrix.size();
        set<Node, Cmp>st;
        for (int i = 0; i < matrix.size(); i++) {
            st.insert(Node(matrix[i][0], 0, i));
        }
        int minrange = INT_MAX;
        while (st.size() == n) {
            int cur = st.rbegin()->val - st.begin()->val;
            minrange = min(minrange, cur);
            Node pop = *st.begin();
            st.erase(st.begin());
            
            int arri = pop.arrindex;
            int owni = pop.index;

            if (owni < matrix[arri].size() - 1) { // 还有下一个数
                st.insert(Node(matrix[arri][owni + 1], owni + 1, arri));
            }
        }
        return minrange * 2;
    }
};
