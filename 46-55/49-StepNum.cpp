// 49 判断一个数是不是stepnum
// 680的stepnum=680 + 68 + 6
// 给定一个数，判断它是否是某一个数的stepnum
class StepNum {
public:
    int findStepNum(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) >> 1;
            int stepnum = stepNum(mid);
            if (stepnum == n) return mid;
            else if (stepnum < n) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
    int stepNum(int x) {
        int ans = 0;
        while (x) {
            ans += x;
            x /= 10;
        }
        return ans;
    }
};
