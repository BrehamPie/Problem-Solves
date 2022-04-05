/*
    Using Hash table(unordered_map) we keep track of
    every element found.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>found;
        for (int x : nums) {
            if (found[x])return true;
            found[x] = 1;
        }
        return false;
    }
};