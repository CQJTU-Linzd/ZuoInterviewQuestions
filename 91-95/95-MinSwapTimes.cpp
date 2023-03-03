// 95 数组变有序的最少交换次数
// 给定一个长度为N的数组，值的范围在0~N-1，且无重复值
// 返回变成从小到大的最小交换次数
class MinSwapTimes {
public:
    int minSwap(vector<int>& nums) {
        // 下标循环怼
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                swap(nums[i], nums[nums[i]]);
                ans++;
            }
        }
        return ans;
    }
};
