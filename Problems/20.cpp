class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                par.push(c);
            } else if (c == ')') {
                if (!par.empty() && par.top() == '(') {
                    par.pop();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if (!par.empty() && par.top() == '[') {
                    par.pop();
                } else {
                    return false;
                }
            } else if (c == '}') {
                if (!par.empty() && par.top() == '{') {
                    par.pop();
                } else {
                    return false;
                }
            }        
        }
        if (par.empty()) {
            return true;
        } else {
            return false;
        }
    }
};