// 88 字符串在新字典序中是第几个
class StringKth {
public:
    int Kth(string s, int len) {
        int ans = 0;
        for (int i = 0, rest = len - 1; i < s.size(); i++, rest--) {
            ans += (s[i] - 'a') * f(rest) + 1;
        }
        return ans;
    }
    // 无论以什么开头，剩下长度为0~len的所有可能性有多少种
    int f(int len) {
        int ans = 1;
        for (int i = 1, base = 26; i <= len; i++, base *= 26) {
            ans += base;
        }
        return ans;
    }
};
