// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
class Solution {
public:
// O(n) time, O(1) space
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int n = abs(nums[i]);
            nums[n - 1] = -(abs(nums[n - 1]));
        }
        
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) result.push_back(i + 1);
        }
        return result;
    }
};