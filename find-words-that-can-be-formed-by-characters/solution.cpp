// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> counters(256, 0);
        for (const char& c : chars) {
            counters[c] += 1;
        }
        
        int length = 0;
        for (const string& word : words) {
            if (isGood(word, counters)) {
                length += word.size();
            }
        }
        return length;
    }
    
    bool isGood(const string& word, vector<int> counters) {
        for (const char& c : word) {
            if (counters[c] == 0) return false;
            counters[c] -= 1;
        }
        return true;
    }
};