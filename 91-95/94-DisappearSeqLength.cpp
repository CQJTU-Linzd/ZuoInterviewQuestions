// 94 全消子序列的最大长度
class DisappearSeqLength {
public:
    int disappear(string s) {
        if (s == "") {
            return 0;
        }
        return f(s, 0, s.size() - 1);
    }
    int f(string s, int L, int R) {
        if (L >= R) {
            return 0;
        }
        if (L == R - 1) {
            return (s[L] == '0' && s[R] == '1') || (s[L] == '2' && s[R] == '3') ? 2 : 0;
        }
        // 完全不考虑s[L]
        int p1 = f(s, L + 1, R);
        if (s[L] == '1' || s[L] == '3') {
            return p1;
        }
        // 必须考虑s[L]
        int p2 = 0;
        char find = s[L] == '0' ? '1' : '3';
        for (int i = L + 1; i <= R; i++) {
            if (s[i] == find) {
                p2 = max(p2, 2 + f(s, L + 1, i - 1) + f(s, i + 1, R));
            }
        }
        return max(p1, p2);
    }
};
