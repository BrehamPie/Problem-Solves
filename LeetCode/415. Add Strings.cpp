/*
    Simple Simulation.
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        while (num1.size() != num2.size()) {
            if (num1.size() < num2.size())num1 = '0' + num1;
            else num2 = '0' + num2;
        }
        string sum;
        int carry = 0;
        for (int i = num1.size() - 1;i >= 0;i--) {
            int d = carry + num1[i] + num2[i] - '0' - '0';
            if (d > 9) {
                carry = 1;
                d %= 10;
            }
            else carry = 0;
            char c = d + '0';
            sum += c;
        }
        if (carry)sum += '1';
        reverse(sum.begin(), sum.end());
        return sum;
    }
};