// 接雨水
class ContainRain {
public:
    int rains(vector<int>& height) {
        int n = height.size();
        vector<int>leftMax(height.size());
        vector<int>rightMax(height.size());
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            if (height[i] > leftMax[i - 1]) {
                leftMax[i] = height[i];
            } else {
                leftMax[i] = leftMax[i - 1];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (height[i] > rightMax[i + 1]) {
                rightMax[i] = height[i];
            } else {
                rightMax[i] = rightMax[i + 1];
            }
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int left = leftMax[i - 1];
            int right = rightMax[i + 1];
            int cur = min(left, right) - height[i];
            ans += cur > 0 ? cur : 0;
        }
        return ans;
    }
    // 二维接雨水
    class Node {
    public:
        int x;
        int y;
        int val;
        Node(int v, int xx, int yy) {
            val = v;
            x = xx;
            y = yy;
        }
    };
    class Cmp {
    public:
        bool operator()(Node a, Node b) {
            return a.val - b.val;
        }
    };
    int rainsII(vector<vector<int>>& height) {
        int n = height.size(), m = height[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        priority_queue<Node, Cmp>heap;
        for (int j = 0; j < m; j++) {
            heap.push(Node(height[0][j], 0, j));
            vis[0][j] = true;
        }
        for (int i = 1; i < n; i++) {
            heap.push(Node(height[i][m - 1], i, m - 1));
            vis[i][m - 1] = true;
        }
        for (int j = m - 2; j >= 0; j--) {
            heap.push(Node(height[n - 1][j], n - 1, j));
            vis[n - 1][j] = true;
        }
        for (int i = n - 2; i >= 1; i--) {
            heap.push(Node(height[i][0], i, 0));
            vis[i][0] = true;
        }
        int ans = 0;
        int Max = 0;
        while (!heap.empty()) {
            Node cur = heap.top();
            heap.pop();
            Max = max(Max, cur.val);
            int r = cur.x;
            int c = cur.y;
            if (r > 0 && !vis[r - 1][c]) {
                ans += max(0, Max - height[r - 1][c]);
                heap.push(Node(height[r - 1][c], r - 1, c));
                vis[r - 1][c] = true;
            }
            if (c > 0 && !vis[r][c - 1]) {
                ans += max(0, Max - height[r][c - 1]);
                heap.push(Node(height[r][c - 1], r, c - 1));
                vis[r][c - 1] = true;
            }
            if (r < n - 1 && !vis[r + 1][c]) {
                ans += max(0, Max - height[r + 1][c]);
                heap.push(Node(height[r + 1][c], r + 1, c));
                vis[r + 1][c] = true;
            }
            if (c < m - 1 && !vis[r][c + 1]) {
                ans += max(0, Max - height[r][c + 1]);
                heap.push(Node(height[r][c + 1], r, c + 1));
                vis[r][c + 1] = true;
            }
        }
        return ans;
    }
};
