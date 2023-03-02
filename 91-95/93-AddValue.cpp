// 93 特殊规则下删除s中的字符使总价值最大
class AddValue {
public:
    int maxValue(string s) {
        if (s == "") {
            return 0;
        }
        return process(s, 0, 0, 0);
    }
    // lastNum：i位置左边最近的保留字符是0还是1
    int process(string s, int i, int lastNum, int baseValue) {
        if (i == s.size()) {
            return 0;
        }
        int curValue = s[i] == lastNum ? baseValue + 1 : 1;
        // 保留当前字符
        int p1 = process(s, i + 1, s[i], curValue);
        // 不保留当前字符
        int p2 = process(s, i + 1, lastNum, baseValue);
        return max(p1 + curValue, p2);
    }
};
