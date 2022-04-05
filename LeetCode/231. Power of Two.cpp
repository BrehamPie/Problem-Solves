/*
    Negative number is not a power of 2
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n >= 0 && __builtin_popcount(n) == 1;
    }
};