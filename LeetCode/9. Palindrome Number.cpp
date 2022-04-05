/*
    just reverse and check if they are equal.
    take long int to avoid overflow.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        long actualX = x;
        long reversedX = 0;
        x = abs(x);
        while (x) {
            reversedX = reversedX * 10 + x % 10;
            x /= 10;
        }
        return reversedX == actualX;
    }
};