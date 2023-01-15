// 删除子串使剩余字符串尽可能短
class DeleteSubString {
public:
    // 暴力尝试
    // 所有消除的情况都枚举
    string disappear1(string str) {
        string ans = str;
        for (int i = 1; i < str.size(); i++) {
            // 判断i和i - 1位置是不是a，b双全
            if ((str[i] == 'a' && str[i - 1] == 'b')
                || (str[i] == 'b' && str[i - 1] == 'a')) {
                // 把i和i - 1位置的字符扣掉
                string newStr = str.substr(0, i) + str.substr(i + 1, str.size() - i - 1);
                string curAns = disappear1(newStr);
                if (curAns.size() < ans.size()) {
                    ans = curAns;
                }
            }
        }
        return ans;
    }
    // 最优解 遇到a和b相邻就删 用栈实现
    string disappear2(string str) {
        if (str.empty()) return "";
        stack<char>stk;
        for (char ch : str) {
            if (stk.empty()) {
                stk.push(ch);
            } else {
                char top = stk.top();
                if ((top == 'a' && ch == 'b') || (top == 'b' && ch == 'a')) {
                    stk.pop();
                } else {
                    stk.push(ch);
                }
            }
        }
        string ans = "";
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
