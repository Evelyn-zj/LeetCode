class Solution {
public:
    string removeDuplicates(string s) {
        string str;
        for (char c : s) {
            if (!str.empty() && c == str.back()) {
                str.pop_back();
            } else {
                str.push_back(c);
            }
        }
        return str;
    }
};