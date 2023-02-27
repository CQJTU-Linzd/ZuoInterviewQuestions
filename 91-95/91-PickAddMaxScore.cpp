// 91 选择拿取方式获得最大分数
// 给定一个数组，当拿走一个数a时，其他数都加a
// 返回最终所有数都拿走的最大分数
class PickAddMax {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
         // 从大到小选
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans = ans * 2 + nums[i]; // 总结出的公式
        }
        return ans;
    }
};
