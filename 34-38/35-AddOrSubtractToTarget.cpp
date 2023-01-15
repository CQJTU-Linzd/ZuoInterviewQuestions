// 以+或-连接所有数字使和为target方法数
class AddOrSubtractWays {
public:
    int ways(vector<int>& nums, int target) {
        return process(nums, target, 0);
    }
    int process(vector<int>& nums, int rest, int index) {
        if (index == nums.size()) {
            return rest == 0 ? 1 : 0;
        }
        int ans = 0;
        ans += process(nums, rest - nums[index], index + 1);
        ans += process(nums, rest + nums[index], index + 1);
        return ans;
    }
    // 记忆化搜索
    int ways2(vector<int>& nums, int target) {
        // 外层的key是index，内层的key是rest，内层的value是答案
        map<int, map<int, int>>dp;
        return process2(nums, target, 0, dp);
    }
    int process2(vector<int>& nums, int rest, int index, map<int, map<int, int>>& dp) {
        if (dp.count(index) && dp[index].count(rest)) {
            return dp[index][rest];
        }
        int ans = 0;
        if (index == nums.size()) {
            ans = rest == 0 ? 1 : 0;
        } else {
            ans += process(nums, rest - nums[index], index + 1);
            ans += process(nums, rest + nums[index], index + 1);
        }
        dp[index][rest] = ans;
        return ans;
    }

    // 动态规划
    int dpWays(vector<int>& nums, int target) {
        for (int num : nums) {
            num = num < 0 ? -num : num;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < target) return 0;
        if ((sum & 1) != (target & 1)) return 0;
        int bagweight = (sum + target) >> 1;
        vector<int>dp(bagweight + 1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagweight; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagweight];
    }
};
