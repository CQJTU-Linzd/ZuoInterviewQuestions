// 57 字符串中有多少字面值不同的子序列
class DifferentLiteralSubSeq {
public:
    int distinctSubSeq(string s) {
        int all = 1; // 一个字符没遍历，有空集
        unordered_map<char, int>mp; // 以
        for (char ch : s) {
            int newAdd = all;
            all = all + newAdd;
            if (mp.count(ch)) {
                all -= mp[ch];
            }
            mp[ch] = newAdd;
        }
        return all - 1;
    }
};
