// https://leetcode.com/problems/happy-number/
class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        unordered_set<int> visited;
        do {
            visited.insert(n);
            int new_value = 0;
            while (n) {
                int d = n%10;
                new_value += d*d;
                n = n/10;
            }
            n = new_value;
        } while (n != 1 and (not visited.count(n)));
        return n == 1;
    }
};