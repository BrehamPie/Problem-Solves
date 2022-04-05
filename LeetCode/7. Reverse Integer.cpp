/*
    As we cant take long integer we convert the number to string 
    and compare them with the range.
*/
class Solution {
public:
    int reverse(int x) {
        string max_num = "2147483648";
        string my_num;
        bool isNegative = (x < 0);
        if (isNegative) max_num.back()--;
        while (x) {
            int d = x % 10;
            x /= 10;
            if (d < 0)d = -d;
            char c = d + '0';
            my_num += c;
        }
        while (my_num.size() < max_num.size()) my_num = '0' + my_num;
        int ret = 0;
        if (my_num < max_num) {
            for (char c : my_num) {
                int d = c - '0';
                ret = ret * 10 + d;
            }
            if (isNegative)ret *= -1;
        }
        return ret;
    }
};