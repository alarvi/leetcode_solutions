// https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, unsigned int> conversionTable = 
           {{'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        unsigned int value = 0;
        char previous = 0;
        for (char c : s) {
            if (previous == 0) {
                previous = c;
            } else {
                if (conversionTable.at(previous) >= conversionTable.at(c)) {
                    value += conversionTable.at(previous);
                    previous = c;
                } else {
                    value += conversionTable.at(c) - conversionTable.at(previous);
                    previous = 0;
                }
            }
        }
        if (previous) {
            value += conversionTable.at(previous);
        }
        return value;
    }
};