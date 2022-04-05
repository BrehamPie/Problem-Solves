class Solution {
public:
    bool isValid(string s) {
        stack<char>checker;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') checker.push(c);
            else {
                if (checker.empty()) return 0;
                if (c == ')') {
                    if (checker.top() == '(') checker.pop();
                    else return 0;
                }
                else if (c == '}') {
                    if (checker.top() == '{') checker.pop();
                    else return 0;
                }
                else {
                    if (checker.top() == '[') checker.pop();
                    else return 0;
                }
            }
        }
        return checker.empty();
    }
};