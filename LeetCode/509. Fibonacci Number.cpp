/*
    We could use array with extra memory.
*/
class Solution {
public:
    int fib(int n) {
        if (n < 2)return n;
        int last0 = 0, last1 = 1;
        int ans;
        for (int i = 2;i <= n;i++) {
            ans = last0 + last1;
            last0 = last1;
            last1 = ans;
        }
        return ans;
    }
};