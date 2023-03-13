// 96 下一个排列
class NextPermutation {
public:
    void nextPermutation(vector<int>& nums) {
        // 从右往左第一次降序的位置
        int firstLess = -1;
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i - 1] < nums[i]) {
                firstLess = i - 1;
                break;
            }
        }
        if (firstLess == -1) { // 它就是最大排列
            reverse(nums.begin(), nums.end());
        } else {
            int rightCloesetMore = -1; // 找firstLess的右边比nums[firstLess]大的最小值
            for (int i = nums.size() - 1; i > firstLess; i--) {
                if (nums[i] > nums[firstLess]) {
                    rightCloesetMore = i;
                    break;
                }
            }
            swap(nums[firstLess], nums[rightCloesetMore]);
            reverse(nums.begin() + firstLess + 1, nums.end());
        }
    }
};
