/*
    We only care about the lowest value we found so far.
*/
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = 0;
        int lowestSoFar = nums[0];
        for (int i = 1, n = nums.size();i < n;i++) {
            ans = max(ans, nums[i] - lowestSoFar);
            lowestSoFar = min(lowestSoFar, nums[i]);
        }
        if (!ans)ans--;
        return ans;
    }
};