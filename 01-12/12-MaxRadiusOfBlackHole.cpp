// 不被吸进黑洞的最大半径
class UnionFind {
public:
    map<int, int>fatherMap;
    map<int, int>sizeMap;
    map<int, int>xminMap;
    map<int, int>xmaxMap;
    map<int, int>yminMap;
    map<int, int>ymaxMap;
    UnionFind(vector<vector<int>>& holes, int n, int r) {
        for (int i = 0; i < n; i++) {
            fatherMap[i] = i;
            sizeMap[i] = 1;
            xminMap[i] = holes[i][0] - r;
            xmaxMap[i] = holes[i][0] + r;
            yminMap[i] = holes[i][1] - r;
            ymaxMap[i] = holes[i][1] + r;
        }
    }
    int findHead(int i) {
        stack<int>path;
        while (i != fatherMap[i]) {
            path.push(i);
            i = fatherMap[i];
        }
        while (!path.empty()) {
            fatherMap[path.top()] = i;
            path.pop();
        }
        return i;
    }
    bool isSameSet(int i, int j) {
        return findHead(i) == findHead(j);
    }
    void Union(int i, int j) {
        if (!isSameSet(i, j)) {
            int fatheri = fatherMap[i];
            int fatherj = fatherMap[j];
            int sizei = sizeMap[i];
            int sizej = sizeMap[j];
            int big = sizei >= sizej ? fatheri : fatherj;
            int small = big == fatheri ? fatherj : fatheri;
            fatherMap[small] = big;
            sizeMap[big] = sizei + sizej;
            sizeMap.erase(small);
            xminMap[big] = min(xminMap[big], xminMap[small]);
            xmaxMap[big] = max(xmaxMap[big], xmaxMap[small]);
            yminMap[big] = min(yminMap[big], yminMap[small]);
            ymaxMap[big] = max(ymaxMap[big], ymaxMap[small]);
        }
    }
    bool block(int i, int x, int y) {
        i = findHead(i);
        return (xminMap[i] <= 0 && xmaxMap[i] >= x)
            || (yminMap[i] <= 0 && ymaxMap[i] >= y)
            || (xminMap[i] <= 0 && yminMap[i] <= 0)
            || (xmaxMap[i] >= x && ymaxMap[i] >= y);
    }
};
class BlackHole {
public:
    int maxRadius(vector<vector<int>>& holes, int x, int y) {
        int L = 0;
        int R = max(x, y);
        int ans = 0;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (check(holes, x, y, mid)) { // 半径定成mid，能否飞到(x, y)
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        return ans;
    }
    bool check(vector<vector<int>>& holes, int x, int y, int r) {
        int n = holes.size();
        UnionFind uf(holes, n, r);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (touch(holes[i][0], holes[i][1], holes[j][0], holes[j][1], r)) {
                    uf.Union(i, j);
                }
                if (uf.block(i, x, y)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool touch(int x1, int y1, int x2, int y2, int r) {
        return 2 * r >= sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
    }
};
