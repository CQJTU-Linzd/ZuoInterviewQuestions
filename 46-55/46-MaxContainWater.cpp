// 46 随意选两根支柱能容纳的最大水量
class MaxContainWater {
public:
    int maxWater(vector<int>& h) {
        int ans = 0;
        int l = 0;
        int r = h.size() - 1;
        while (l < r) {
            int cur = min(h[l], h[r]) * (r - l);
            ans = max(ans, cur);
            if (h[l] > h[r]) {
                r--;
            } else {
                l++;
            }
        }
        return ans;
    }
};
