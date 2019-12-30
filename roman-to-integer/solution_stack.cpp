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

        stack<int> values;
        for (char c : s) {
            values.push(conversionTable.at(c));
        }
        
        int value = values.top();
        int previous = value;
        values.pop();
        
        while (not values.empty()) {
            if (values.top() >= previous) {
                value += values.top();
            }
            else {
                value -= values.top();
            }
            
            previous = values.top();
            values.pop();
        }
        return value;
    }
};