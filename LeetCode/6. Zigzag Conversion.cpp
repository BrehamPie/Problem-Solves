/* Solution 1:
    We Assign each character their respective row and column number
    And then sort them.

*/
Class Solution{
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector< pair< pair<int, int>, char > > order;
        for (int i = 0, row = 1, col = 1, isDecreasing = 0;i < s.size();i++) {
            order.push_back({ {row,col},s[i] });
            if (isDecreasing) {
                row--;
                col++;
                if (row == 0) {
                    row = 2;
                    col--;
                    isDecreasing = 0;
                }
            }
            else {
                row++;
                if (row == numRows + 1) {
                    row = numRows - 1;
                    col++;
                    isDecreasing = 1;
                }
            }
        }
        sort(order.begin(), order.end());
        string ret;
        for (auto u : order)ret += u.second;
        return ret;
    }
};
/*
    Solution 2:
    We take a string for each row and append each character to their
    appropriate row string traversing from left to right.
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string rows[numRows];
        int currentRow = 0;
        int decreasing = 0;
        for (int i = 0, n = s.size();i < n;i++) {
            rows[currentRow] += s[i];
            if (!decreasing) {
                currentRow++;
                if (currentRow == numRows) {
                    decreasing = 1;
                    currentRow -= 2;
                }
            }
            else {
                currentRow--;
                if (currentRow < 0) {
                    currentRow += 2;
                    decreasing = 0;
                }
            }
        }
        string ret;
        for (int i = 0;i < numRows;i++)ret += rows[i];
        return ret;
    }
};