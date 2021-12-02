class Solution {
public:
    void reverse(string& s, int begin, int end) {
        for (int i = 0; i < (end - begin) / 2; ++i) {
            swap(s[begin + i], s[end - i - 1]);
        }
    }

    string reverseLeftWords(string s, int n) {
        reverse(s, 0, n);
        reverse(s, n, s.size());
        reverse(s, 0, s.size());
        return s;
    }
};