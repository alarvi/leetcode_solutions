// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
class Solution {
public:
// O(n) time, O(n) space
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> found;
        for (int i = 0; i < nums.size(); ++i) {
            found.insert(nums[i]);
        }
        
        vector<int> result;
        for (int i = 1; i <= nums.size(); ++i) {
            if (not found.count(i)) result.push_back(i);
        }
        return result;
    }
};