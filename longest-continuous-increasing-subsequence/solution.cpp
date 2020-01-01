// https://leetcode.com/problems/longest-continuous-increasing-subsequence/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int init = 0;
        int max = 1;
        for (int current = 1; current < nums.size(); ++current) {
            if (nums[current] <= nums[current -  1]) {
                int currentSeq = current - init;
                max = max > currentSeq ? max : currentSeq;
                init = current;
            }
        }
        int currentSeq = nums.size() - init;
        return max > currentSeq ? max : currentSeq;
    }
};