/* Solution: 1
    For each height[i] we try to find the longest subarray
    where we can take water of at least height[i].
*/
class Solution {
public:

    int maxArea(vector<int>& height) {
        int pref[10001];
        int suff[10001] = { 0 };
        int n = height.size();
        for (int i = 0;i <= 10000;i++)pref[i] = n;
        for (int i = 0;i < n - 1;i++) {
            pref[height[i]] = min(pref[height[i]], i);
        }
        for (int i = n - 1;i >= 0;i--) {
            suff[height[i]] = max(suff[height[i]], i);
        }
        for (int i = 9999;i > 0;i--) {
            suff[i] = max(suff[i], suff[i + 1]);
            pref[i] = min(pref[i], pref[i + 1]);
        }
        int ans = 0;
        for (int i = 0;i < n;i++) {
            ans = max({ ans,(i - pref[height[i]]) * height[i],(suff[height[i]] - i) * height[i] });
        }
        return ans;
    }
};
/* Solution 2:
    We use two pointer here.
    Initially left = 0 and right = array_size - 1
    Now if height[left]<height[right] we discard left.
    Why? Cause we already got the best answer for height[left].

    P.S: The run time can be reduced by not using built-in min/max.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])l++;
            else r--;
        }
        return ans;
    }
};