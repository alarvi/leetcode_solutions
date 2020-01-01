class Solution {
    vector<int> steps;
public:
    int climbStairs(int n) {
        steps = vector<int>(n + 1, 0);
        return climbStairsDP(n);
    }
    
    int climbStairsDP(int n) {
        if (n == 0) return 1;
        if (n <= 2) return n;
        if (steps[n] == 0) {
            steps[n] = climbStairsDP(n - 1) + climbStairsDP(n - 2);
        }
        return steps[n];
    }
};