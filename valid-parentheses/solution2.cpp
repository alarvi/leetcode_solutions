// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        unordered_set<char> openingBrackets = {'(', '[', '{'};
        unordered_map<char, char> closingBrackets = {{')','('},
                                                     {']', '['},
                                                     {'}', '{'}};
        for (char c : s) {
            if (openingBrackets.find(c) != openingBrackets.end()) {
                brackets.push(c);
            }
            else if (brackets.empty()) {
                return false;
            }
            else {
                if (closingBrackets.at(c) == brackets.top()) {
                    brackets.pop();
                }
                else {
                    return false;
                }
            }
        }
        return brackets.empty();
    }
};