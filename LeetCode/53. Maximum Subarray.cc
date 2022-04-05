/*
    Kadane's Algorithm
    If the sum of a subarray is positive, it has possible to make the next value bigger, so we keep do it until it turn to negative.
    If the sum is negative, it has no use to the next element, so we break.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1;
        int maxTill = 0;
        for (int i = 0;i < nums.size();i++) {
            maxTill += nums[i];
            if (ans < maxTill)ans = maxTill;
            if (maxTill < 0)maxTill = 0;
        }
        if (ans == -1)ans = *max_element(nums.begin(), nums.end());
        return ans;
    }
};