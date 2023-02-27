// 90 前缀01串切成等比例的最大部分数
class Ratio01Split {
public:
    vector<int> split(vector<int>& nums) {
        unordered_map<int, unordered_map<int, int>>pre; // [分子, [分母, 分子/分母的出现次数]]
        int n = nums.size();
        vector<int>ans(n);
        int zeroNum = 0;
        int oneNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroNum++;
            } else {
                oneNum++;
            }
            if (zeroNum == 0 || oneNum == 0) {
                ans[i] = i + 1;
            } else { // 0和1都有数量，获取其最简分数
                int gcd = this->gcd(zeroNum, oneNum);
                int a = zeroNum / gcd; // 最简分数的分子
                int b = oneNum / gcd; // 最简分数的分母
                // a/b 这个比例，之前有多少个前缀拥有
                pre[a][b]++;
                ans[i] = pre[a][b];
            }
        }
        return ans;
    }
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};
