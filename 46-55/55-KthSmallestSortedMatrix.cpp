// 55 每行每列有序的数组中找最小的第k个数
class KthSmallestSortedMatrix {
public:
    class Info {
    public:
        int num;
        int nearest;
        Info(int n, int near) {
            num = n;
            nearest = near;
        }
    };
    int KthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = matrix[0][0];
        int right = matrix[n - 1][m - 1];
        int ans = 0;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            // <= mid的有几个；在矩阵中真实出现的数，<= mid且最接近mid的数
            Info info = noMoreNum(matrix, mid);
            if (info.num < k) {
                left = mid + 1;
            } else {
                ans = info.nearest;
                right = mid - 1;
            }
        }
        return ans;
    }
    Info noMoreNum(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        int num = 0, near = INT_MIN;
        while (i >= 0 && i < n && j >= 0 && j < m) {
            if (matrix[i][j] <= mid) {
                num += (j + 1);
                if (abs(matrix[i][j] - mid) < abs(near - mid)) {
                    near = matrix[i][j];
                }
                i++;
            } else {
                j--;
            }
        }
        return Info(num, near);
    }
};
