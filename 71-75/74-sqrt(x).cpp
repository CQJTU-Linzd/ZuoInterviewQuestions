// 74 sqrt(x)
class MySqrt {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        if (x <= 3) {
            return 1;
        }
        int ans = 1;
        int L = 1;
        int R = x;
        while (L <= R) {
            int M = (L + R) / 2;
            if (M * M <= x) {
                ans = M;
                L = M + 1;
            } else {
                R = M - 1;
            }
        }
        return ans;
    }
};
