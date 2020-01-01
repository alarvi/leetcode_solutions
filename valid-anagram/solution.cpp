// https://leetcode.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counters(26, 0);
        for (const char& c : s) {
            ++(counters[c - 'a']);
        }
        
        for (const char& c : t) {
            if (not counters[c - 'a']) return false;
            --(counters[c - 'a']);
        }
        
        for (const int& i : counters) {
            if (i) return false;
        }
        
        return true;
    }
};