// 能力相差为k的人可以比赛
// 能同时比赛的最大场数
class MaxMatch {
public:
    int maxMatch(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int L = 0, R = 0;
        int ans = 0;
        vector<bool>used(nums.size(), false);
        while (L < nums.size() && R < nums.size()) {
            if (used[L]) {
                L++;
            } else if (L == R) {
                R++;
            } else {
                if (nums[R] - nums[L] == k) {
                    ans++;
                    used[R] = true;
                    L++;
                    R++;
                } else if (nums[R] - nums[L] > k) {
                    L++;
                } else {
                    R++;
                }
            }
        }
        return ans;
    }
};
