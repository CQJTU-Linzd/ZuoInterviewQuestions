// 68 鹅厂文化衫问题
class MinPeople {
public:
    int minPeople(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        map<int, int>mp;
        for (int num : nums) {
            mp[num]++;
        }
        int ans = 0;
        for (auto& it : mp) {
            int cur = it.first;
            int cnt = it.second;
            ans += ((cnt + cur) / (cur + 1)) * (cur + 1);
        }
        return ans;
    }
};
