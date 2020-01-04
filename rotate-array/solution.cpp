// https://leetcode.com/problems/rotate-array/
// O(n) time, O(n) space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        
        vector<int> sol(nums.size(), 0);
        k = k%nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (k + i < nums.size()) {
                sol[k + i] = nums[i];
            } else {
                sol[k + i - nums.size()] = nums[i];
            }
        }
        nums.swap(sol);
    }
};