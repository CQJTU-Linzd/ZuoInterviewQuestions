// 高尔夫球场砍树

class CutOffTree {
public:
    class Cmp {
    public:
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        }
    };
    int cutOff(vector<vector<int>>& forest) {
        int n = forest.size();
        int m = forest[0].size();
        vector<vector<int>>cells;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int height = forest[i][j];
                if (height > 1) {
                    cells.push_back(vector<int>{i, j, height});
                }
            }
        }
        sort(cells.begin(), cells.end(), Cmp());
        int ans = 0, curR = 0, curC = 0;
        for (vector<int> cell : cells) {
            int step = bestWalk(forest, curR, curC, cell[0], cell[1]);
            if (step == -1) {
                return -1;
            }
            ans += step;
            curR = cell[0];
            curC = cell[1];
            forest[curR][curC] = 1;
        }
        return ans;
    }
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
    int bestWalk(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
        int n = forest.size();
        int m = forest[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m));
        deque<vector<int>>que;
        que.push_front(vector<int>{0, sr, sc});
        while (!que.empty()) {
            vector<int>cur = que.front();
            que.pop_front();
            int step = cur[0], r = cur[1], c = cur[2];
            if (r == tr && c == tc) {
                return step;
            }
            vis[r][c] = true;
            for (int i = 0; i < 4; i++) {
                int dr = r + dx[i];
                int dc = c + dy[i];
                if (dr >= 0 && dr < n && dc >= 0 && dc < m && !vis[dr][dc] && forest[dr][dc] > 0) {
                    vector<int>move = { step + 1, dr, dc };
                    // 离目标位置更近的话 放在头部
                    if ((i == 0 && r > tr) || (i == 1 && c > tc) || (i == 2 && r < tr) || (i == 3 && c < tc)) {
                        que.push_front(move);
                    } else { // 离目标位置更远的话 放在尾部
                        que.push_back(move);
                    }
                }
            }
        }
        return -1;
    }
};
