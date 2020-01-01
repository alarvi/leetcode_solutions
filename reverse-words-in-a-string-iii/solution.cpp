// https://leetcode.com/problems/reverse-words-in-a-string-iii/
class Solution {
public:
    string reverseWords(string s) {
        string::iterator init = s.begin();
        string::iterator current = s.begin();
        
        for (const char& c : s) {
            if (c == ' ') {
                reverse(init, current);
                init = current + 1;
            }
            ++current;
        }
        
        reverse(init, current);
        return s;
    }
};