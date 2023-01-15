// 38 最长无重复字符的子串长度
class MaxNoRepeteSubString {
public:
    int maxLength(string str) {
        if (str.empty()) return 0;
        int n = str.size();
        vector<int>dp(n);
        dp[0] = 1;
        unordered_map<char, int>lastIndex;
        int ans = 1;
        lastIndex[str[0]] = 0;
        for (int i = 1; i < str.size(); i++) {
            if (!lastIndex.count(str[i])) {
                dp[i] = 1 + dp[i - 1];
            } else {
                int last = lastIndex[str[i]];
                dp[i] = min(i - last, 1 + dp[i - 1]);
            }
            lastIndex[str[i]] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    // 滑动窗口
    int maxLength2(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int>mp;
        int L = 0, R = 0;
        int ans = 1;
        while (R < s.size()) {
            mp[s[R]]++;
            while (mp[s[R]] > 1) {
                mp[s[L]]--;
                L++;
            }
            R++;
            ans = max(ans, R - L);
        }
        return ans;
    }
};
