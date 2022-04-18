/*
    We keep track of last binary digits and compare.
*/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = -1;
        while (n) {
            int d = n % 2;
            n /= 2;
            if (d == last) return false;
            last = d;
        }
        return true;
    }
};