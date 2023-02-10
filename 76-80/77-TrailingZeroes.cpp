// 77 阶乘后的0
// 给定一个数n，求出其阶乘的结果中，末尾有几个0
class TrailingZeroes {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n != 0) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
