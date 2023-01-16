// 41 分糖果问题
// 当前孩子得分比左边的高，则分到的糖一定比左边的多
// 当前孩子得分比右边的高，则分到的糖一定比右边的多
// 得分相同 无所谓
// 最少需要准备几颗糖果
class DivideCandy {
public:
    int minCandy(vector<int>& nums) {
        vector<int>left(nums.size());
        vector<int>right(nums.size());
        left[0] = 1;
        for (int i = 1; i < left.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }
        right.back() = nums.back();
        for (int i = right.size() - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                right[i] = right[i + 1] + 1;
            } else {
                right[i] = 1;
            }
        }
        int candy = 0;
        for (int i = 0; i < nums.size(); i++) {
            candy += max(left[i], right[i]);
        }
        return candy;
    }
};
