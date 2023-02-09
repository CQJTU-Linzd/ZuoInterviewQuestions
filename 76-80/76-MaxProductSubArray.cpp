// 76 最大乘积子数组
class MaxProductSubArray {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>dpmax(n);
        vector<int>dpmin(n);
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int p1 = nums[i];
            int p2 = nums[i] * dpmax[i - 1];
            int p3 = nums[i] * dpmin[i - 1];
            dpmax[i] = max({ p1, p2, p3 });
            dpmin[i] = min({ p1, p2, p3 });
            ans = max(ans, dpmax[i]);
        }
        return ans;
    }
};
