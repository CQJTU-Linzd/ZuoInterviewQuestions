// 80 出卷子的方法数
// nums[i]表示第i号试题的难度，给定一个非负数M
// 要求出一张卷子，对于任何相邻的两套题目，前一题的难度 - 后一题的难度 <= M
// 返回所有可能的出卷子的方法数
class ExamPaperWays {
public:
    int countGreater(vector<int>& nums, int L, int R, int target) {
        int cnt = 0;
        while (L <= R) {
            int M = (L + R) / 2;
            if (nums[M] >= target) {
                cnt += (R - M + 1);
                R = M - 1;
            } else {
                L = M + 1;
            }
        }
        return cnt;
    }
    int ways(vector<int>& nums, int m) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int pre = 1;
        for (int i = 1; i < nums.size(); i++) {
            int p1 = pre; // 把当前的卷子添在最后，一定合法
            // 查nums[0...i - 1] 有多少数是 >= nums[i] - m 的
            int num = countGreater(nums, 0, i - 1, nums[i] - m);
            int p2 = num * pre;
            pre = p1 + p2;
        }
        return pre;
    }

    // for test

    // 验证countGreater二分法
    int countGreater2(vector<int>& nums, int L, int R, int target) {
        int cnt = 0;
        for (int i = L; i <= R; i++) {
            cnt += nums[i] >= target ? 1 : 0;
        }
        return cnt;
    }

    vector<int> randomArray(int size, int l, int r) {
        srand(time(0));
        vector<int>nums;
        for (int i = 0; i < size; i++) {
            nums.push_back(rand() % (r - l + 1) + l);
        }
        return nums;
    }

    void test() {
        srand(time(0));
        for (int test = 0; test < 10000; test++) {
            int size = rand() % (1000 - 1 + 1) + 1;
            vector<int>nums = randomArray(size, 0, 1000);
            sort(nums.begin(), nums.end());
            int target = rand() % (1000 - 0 + 1) + 0;
            int ans1 = countGreater(nums, 0, nums.size() - 1, target);
            int ans2 = countGreater2(nums, 0, nums.size() - 1, target);
            if (ans1 != ans2) {
                cout << "fuck!!!" << endl;
            }
        }
        cout << "end" << endl;
    }

    // 验证ways函数
    // 纯暴力 求nums的全排列，每一个验证
    int ways2(vector<int>& nums, int m) {
        if (nums.empty()) {
            return 0;
        }
        return process(nums, m, 0);
    }
    int process(vector<int>& nums, int m, int i) {
        if (i == nums.size()) {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] - nums[i] > m) {
                    return 0;
                }
            }
            return 1;
        }
        int ans = 0;
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            ans += process(nums, m, i + 1);
            swap(nums[i], nums[j]);
        }
        return ans;
    }

    void test2() {
        srand(time(0));
        for (int test = 0; test < 10000; test++) {
            int size = rand() % (10 - 1 + 1) + 1;
            vector<int>nums = randomArray(size, 0, 1000);
            sort(nums.begin(), nums.end());
            int m = rand() % (1000 - 0 + 1) + 0;
            int ans1 = ways(nums, m);
            int ans2 = ways2(nums, m);
            if (ans1 != ans2) {
                cout << "fuck!!!" << endl;
            }
        }
    }
};
