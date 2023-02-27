// 92 长度为k的字典序最大子序列
class MaxKLengthSequence {
public:
    string maxString(string s, int k) {
        if (k <= 0 || k > s.size()) {
            return "";
        }
        int n = s.size();
        vector<char>stack(n);
        int size = 0;
        for (int i = 0; i < n; i++) {
            while (size > 0 && stack[size - 1] < s[i] && size + n - i > k) {
                size--;
            }
            if (size + n - i == k) {
                string ans = "";
                for (int j = 0; j <= size; j++) {
                    ans += stack[j];
                    return ans + s.substr(i);
                }
            }
            stack[size++] = s[i];
        }
        string ans = "";
        for (int j = 0; j <= k; j++) {
            ans += stack[j];
            return ans;
        }
    }
};
