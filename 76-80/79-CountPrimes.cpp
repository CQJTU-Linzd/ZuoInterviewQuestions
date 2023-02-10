// 79 计数质数
// 小于n的正整数里 有几个质数
class CountPrimes {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }
        vector<bool>isPrime(n, true);
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                cnt++;
            }
            // 把i的倍数全都设置为合数
            for (int j = i * 2; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        return cnt;
    }
};
