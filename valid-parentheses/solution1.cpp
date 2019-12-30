// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (char c : s) {
            if (c == '(' or c == '[' or c == '{') {
                brackets.push(c);
            }
            else if (brackets.empty()) {
                return false;
            }
            else if (c == ')') {
                if (brackets.top() == '(') {
                    brackets.pop();
                } else {
                    return false;
                }
            }
            else if (c == ']') {
                if (brackets.top() == '[') {
                    brackets.pop();
                } else {
                    return false;
                }
            }
            else if (c == '}') {
                if (brackets.top() == '{') {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }
        return brackets.empty();
    }
};