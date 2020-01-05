// https://leetcode.com/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for (int i = 1; i < A.size() - 1; ++i) {
            if (A[i] > A[i - 1] and A[i] > A[i + 1]) return i;
        }
        return -1;
    }
};