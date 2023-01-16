// 让G放左，B放右的最少交换次数

class MinSwap {
public:
    int minSwap(string s) {
        int L = 0;
        int index = 0;
        int ans = 0;
        while (s[L] == 'G') {
            L++;
        }
        index = L + 1;
        while (index < s.size()) {
            if (s[index] == 'B') continue;
            else if (s[index] == 'G') {
                ans += index++ - L++;
            }
        }
        return ans;
    }
};
