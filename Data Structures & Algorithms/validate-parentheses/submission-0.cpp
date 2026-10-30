class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0 || s.size() % 2 != 0) {
            return false;
        }

        stack<char> checker;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') { // Only accept the opener
                checker.push(s[i]);
            } else {
                if (checker.empty()) return false;
                char top = checker.top();

                // If the closer is detected, remove the opener
                if ((s[i] == ')' && top == '(') || 
                    (s[i] == ']' && top == '[') || 
                    (s[i] == '}' && top == '{')) {
                    checker.pop();
                } else {
                    return false;
                }
            }
        }

        if (checker.empty()) { // If all of that still remains, that means it is not valid
            return true;
        } else return false;
    }
};