// 65 最小包含子串
// s1的子串中，包含s2所有字符的最短长度
class MinWindowLength {
public:
    int minLength(string s1, string s2) {
        unordered_map<char, int>mp; // 欠帐表
        for (char ch : s2) {
            mp[ch]++;
        }
        int all = s2.size(); // 总共欠了多少个字符
        // 左闭右开 [L, R)
        int L = 0;
        int R = 0;
        int ans = INT_MAX;
        while (R != s1.size()) {
            mp[s1[R]]--;
            if (mp[s1[R]] >= 0) {
                all--;
            }
            if (all == 0) { // 还完了
                while (mp[s1[L]] < 0) { // L往右缩到不能再缩
                    mp[s1[L]]++;
                    L++;
                }
                ans = min(ans, R - L + 1);
                mp[s1[L]]++;
                L++;
                all++;
            }
            R++;
        }
    }
};
