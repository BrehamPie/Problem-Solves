// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
/*
    binary search the position.
    mid = (l+r)/2 gives overflow.
*/
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int ans;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) {
                ans = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};