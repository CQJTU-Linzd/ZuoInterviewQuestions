// 86 至多包含K种不同字符
class LongestSubStringKDistinct {
public:
    int longestSubString(string s, int k) {
        unordered_map<char, int>map;
        int R = 0;
        int diff = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            while (R < s.size() && diff <= k) {
                map[s[R]]++;
                diff += map[s[R]] == 1 ? 1 : 0;
                R++;
            }
            // R来到违规的第一个位置
            ans = max(ans, R - i);
            diff -= map[s[i]] == 1 ? 1 : 0;
            map[s[i]]--;
        }
        return ans;
    }
};
