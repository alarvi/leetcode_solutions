// https://leetcode.com/problems/non-decreasing-array/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int p = -1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                if (p != -1) return false;
                p = i;
            }
        }
        if (p == -1 or p == 1 or p == nums.size() - 1) return true;
        return nums[p + 1] >= nums[p - 1] or nums[p] > nums[p - 2];
    }
};