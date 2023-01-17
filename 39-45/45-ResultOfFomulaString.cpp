// 45 公式字符串的计算结果
class FormulaString {
public:
    int getAns(string str) {

    }
    // 从str[i]往下算，遇到字符串终止或者右括号，就停止
    // 返回值数组的长度为2
    // [0]: 这一段的计算结果为多少
    // [1]: 这一段计算到了哪个位置
    vector<int> f(string str, int i) {
        deque<string>que;
        int cur = 0;
        vector<int>ans;
        // 从i位置出发
        while (i < str.size() && str[i] != ')') {
            if (str[i] >= '0' && str[i] <= '9') {
                cur = cur * 10 + (str[i++] - '0');
            } else if (str[i] != '(') { // 遇到的是运算符
                addNum(que, cur);
                que.push_back(to_string(str[i++]));
                cur = 0;
            } else { // 遇到左括号
                ans = f(str, i + 1);
                cur = ans[0];
                i = ans[1] + 1;
            }
        }
        addNum(que, cur);
        return vector<int>{getNum(que), i};
    }
    void addNum(deque<string>& que, int num) {
        if (!que.empty()) {
            int cur = 0;
            string top = que.back();
            que.pop_back();
            if (top == "+" || top == "-") {
                que.push_back(top);
            } else {
                cur = atoi(que.back().c_str());
                que.pop_back();
                num = top == "*" ? (cur * num) : (cur / num);
            }
        }
        que.push_back(to_string(num));
    }
    int getNum(deque<string>& que) {
        int res = 0;
        bool add = true;
        string cur = "";
        int num = 0;
        while (!que.empty()) {
            cur = que.front();
            que.pop_front();
            if (cur == "+") {
                add = true;
            } else if (cur == "-") {
                add = false;
            } else {
                num = atoi(cur.c_str());
                res += add ? num : (-num);
            }
        }
        return res;
    }
};
