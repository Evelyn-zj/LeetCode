class Solution {
public:
    string reverseStr(string s, int k) {
        int t = 0;
        while (t < s.length()) {
            int n;
            if (t + k < s.length()) {
                n = t + k;
            } else {
                n = s.length();
            }
            for (int i = 0; i < (n - t) / 2; ++i) {
                swap(s[t + i], s[n - i - 1]);
            }
            t += 2 * k;
        }
        return s;
    }
};