// https://leetcode.com/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    // O(log(n)) time
    int peakIndexInMountainArray(vector<int>& A) {
        return binarySearchPeak(A, 0, A.size() - 1);
    }
    
    int binarySearchPeak(const vector<int>& A, int init, int end) {
        if (init == end) return init;
        if (init + 1 == end) return (A[init] > A[end]) ? init : end;
        
        int mid = init + (end - init)/2;
        if (A[mid] > A[mid - 1] and A[mid] > A[mid + 1]) return mid;
        if (A[mid] > A[mid - 1] and A[mid] < A[mid + 1]) return binarySearchPeak(A, mid, end);
        return binarySearchPeak(A, init, mid);
    }
};