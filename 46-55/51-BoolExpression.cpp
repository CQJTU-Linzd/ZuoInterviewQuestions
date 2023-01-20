// 51 布尔表达式求值
// 返回添加括号的方法数
class BoolExpression {
public:
    class Info {
    public:
        int t;
        int f;
        Info(int tt, int ff) {
            t = tt;
            f = ff;
        }
    };
    int bracketWays(string s, bool target) {
        Info ans = process(s, 0, s.size() - 1);
        return target ? ans.t : ans.f;
    }
    Info process(string s, int L, int R) {
        if (L == R) {
            int t = s[L] == '1' ? 1 : 0;
            int f = s[L] == '0' ? 1 : 0;
            return Info(t, f);
        }
        int t = 0;
        int f = 0;
        for (int cur = L + 1; cur < R; cur += 2) { // 逻辑符号的位置
            Info leftInfo = process(s, L, cur - 1);
            Info rightInfo = process(s, cur + 1, R);
            int lt = leftInfo.t;
            int lf = leftInfo.f;
            int rt = rightInfo.t;
            int rf = rightInfo.f;
            switch (s[cur]) {
            case '&':
                t += lt * rt;
                f += lt * rf + lf * rt + lf * rf;
                break;
            case '|':
                t += lt * rf + lf * rt + lt * rt;
                f += lf * rf;
                break;
            case '^':
                t += lt * rf + lf * rt;
                f += lt * rt + lf * rf;
                break;
            }
        }
        return Info(t, f);
    }
};
