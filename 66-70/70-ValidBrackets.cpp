// 70 有效的括号
class ValidBrackets {
public:
    bool validBrackets(string s) {
        stack<char>stack;
        for (char ch : s) {
            switch (ch) {
            case '(':
                stack.push(')');
                break;
            case '[':
                stack.push(']');
                break;
            case '{':
                stack.push('}');
                break;
            default:
                if (stack.empty() || stack.top() != ch) {
                    return false;
                }
                stack.pop();
                break;
            }
        }
        return stack.empty();
    }
};
