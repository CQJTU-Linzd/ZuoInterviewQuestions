// 50 跳跃游戏 跳的最少步数
class minJumpGame {
public:
    int minStep(vector<int>& nums) {
        if (nums.empty()) return 0;
        int step = 0; // 来到当前位置，最省跳几步
        int cur = 0; // step步以内，最远能到哪
        int next = nums[0]; // 如果多跳一步，最远能到哪
        for (int i = 1; i < nums.size(); i++) {
            if (i > cur) {
                step++;
                cur = next;
            }
            next = max(next, i + nums[i]);
        }
        return step;
    }
};
