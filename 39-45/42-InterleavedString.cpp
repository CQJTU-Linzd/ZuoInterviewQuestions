// 42 交错字符串
class InterleavedString {
public:
    bool check(string s1, string s2, string str) {
        if (s1.size() + s2.size() != str.size()) {
            return false;
        }
        int n1 = s1.size();
        int n2 = s2.size();
        int n = str.size();
        // dp[i][j]: s1的前i个字符，以及s2的前j个字符，能否拼出str前i+j个字符
        vector<vector<bool>>dp(n1 + 1, vector<bool>(n2 + 1));
        dp[0][0] = true;
        for (int j = 1; j <= n2; j++) {
            if (s2.substr(0, j) == str.substr(0, j)) {
                dp[0][j] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i <= n1; i++) {
            if (s1.substr(0, i) == str.substr(0, i)) {
                dp[i][0] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (str[i + j - 1] == s1[i - 1] && dp[i - 1][j]) {
                    dp[i][j] = true;
                }
                if (str[i + j - 1] == s2[j - 1] && dp[i][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[n1][n2];
    }
};
