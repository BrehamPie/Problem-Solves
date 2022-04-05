/*
    Simple Simulation.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size() - 1;
        do {
            digits[n]++;
            if (digits[n] == 10) {
                digits[n] = 0;
                carry = 1;
            }
            else carry = 0;
            n--;
        } while (carry && n >= 0);
        if (carry)digits.insert(digits.begin(), carry);
        return digits;
    }
};