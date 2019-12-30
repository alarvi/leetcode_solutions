// https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
public:
    int trailingZeroes(int n) {
        int v = 0;
        while (n >= 5) {
            v += n/5;
            n = n/5;
        }
        return v;
    }
};