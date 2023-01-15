// 左下角走到右下角的最短路径
class Node {
public:
    int cost;
    int x;
    int y;
    Node(int c, int xx, int yy) {
        cost = c;
        x = xx;
        y = yy;
    }
};
class Cmp1 {
public:
    bool operator()(const Node& a, const Node& b) {
        return a.cost < b.cost;
    }
};
class MinWay {
public:
    int ans = INT_MAX;
    vector<vector<bool>>vis;
    int minWay(vector<vector<int>>& map) {
        int n = map.size();
        int m = map[0].size();
        vis.resize(n, vector<bool>(m));
        // [n - 1][0]->[n - 1][m - 1]
        process(map, n, m, n - 1, 0, map[n - 1][0]);
    }
    int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    void process(vector<vector<int>>& map, int n, int m, int x, int y, int pre) {
        if (x == n - 1 && y == m - 1) {
            ans = min(ans, pre + map[x][y]);
            return;
        }
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if (dx >= 0 && dx < n && dy >= 0 && dy < m && !vis[dx][dy]) {
                process(map, n, m, dx, dy, pre + map[dx][dy]);
            }
        }
        vis[x][y] = false;
    }

    // 单元最短路径算法
    int minWay2(vector<vector<int>>& map) {
        int n = map.size();
        int m = map[0].size();
        priority_queue<Node, vector<Node>, Cmp1>heap; // 小根堆
        vector<vector<bool>>poped(n, vector<bool>(m)); // 某个位置是否弹出过
        heap.push(Node(map[0][0], 0, 0));
        int ans = 0;
        while (!heap.empty()) {
            Node cur = heap.top();
            heap.pop();
            int cost = cur.cost;
            int x = cur.x;
            int y = cur.y;
            if (poped[x][y]) continue;
            // 开始处理这个位置了
            poped[x][y] = true;
            if (x == n - 1 && y == m - 1) {
                ans = cost;
                break;
            }
            add(cost, x - 1, y, n, m, map, poped, heap);
            add(cost, x, y - 1, n, m, map, poped, heap);
            add(cost, x + 1, y, n, m, map, poped, heap);
            add(cost, x, y + 1, n, m, map, poped, heap);
        }
        return ans;
    }
    void add(int cost, int x, int y, int n, int m,
             vector<vector<int>>& map, vector<vector<bool>>& poped,
             priority_queue<Node, vector<Node>, Cmp1>& heap) {
        if (x >= 0 && x < n && y >= 0 && y < m && !poped[x][y]) {
            heap.push(Node(cost + map[x][y], x, y));
        }
    }
};
