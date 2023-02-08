// 73 pow(x,n)
class PowXN {
public:
    // x为整数时
    int pow(int x, int n) {
        int ans = 1;
        int t = x;
        while (n != 0) {
            if (n & 1 != 0) {
                ans *= t;
            }
            t *= t;
            n >>= 1;
        }
        return ans;
    }
    // x为double，n可能为负数
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        // 系统最小值是无法求出abs的
        int pow = abs(n == INT_MIN ? n + 1 : n);
        // 计算x的pow次方
        double ans = 1.0;
        double t = x;
        while (pow != 0) {
            if (pow & 1 != 0) {
                ans *= t;
            }
            t *= t;
            pow >>= 1;
        }
        if (n == INT_MIN) {
            ans *= x;
        }
        return n < 0 ? (1.0 / ans) : ans;
    }
};
