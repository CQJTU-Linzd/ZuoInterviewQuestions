// 绳子最多能盖住几个点
class MaxPoint {
public:
    int maxPoint(vector<int>& arr, int L) {
        int res = 1;
        for (int i = 0; i < arr.size(); i++) {
            int nearest = nearestIndex(arr, i, arr[i] - L);
            res = max(res, i - nearest + 1);
        }
        return res;
    }
    int nearestIndex(vector<int>& arr, int R, int value) {
        int L = 0;
        int index = R;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (arr[mid] >= value) {
                index = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        return index;
    }
    // 双指针
    int maxPoint2(vector<int>& arr, int L) {
        int left = 0, right = 0;
        int Max = 0;
        while (left < arr.size()) {
            // left固定 right往右移动到不能再往右
            while (right < arr.size() && arr[right] - arr[left] <= L) {
                right++;
            }
            Max = max(Max, right - left);
            left++;
        }
        return Max;
    }
};
