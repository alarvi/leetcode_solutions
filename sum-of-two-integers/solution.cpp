// https://leetcode.com/problems/sum-of-two-integers/
class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int result = 0;
        int d;
        int newBit;
        for (int i = 0; i < sizeof(int)*8; ++i) {
            d = (a&1)^(b&1);
            newBit = d ^ carry;
            carry = ((a&1)&(b&1)) | (d&carry);
            
            if (newBit > 0) setBit(result, i);
            
            a = a >> 1;
            b = b >> 1;
        }
        return result;
    }
    
    void setBit(int &number, const int position) {
        int mask = 1 << position;
        number = number | mask;
    }
};