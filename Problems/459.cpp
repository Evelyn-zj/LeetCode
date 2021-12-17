class Solution {
public:
    void getNext(string s, int* next) {
        int k = 0;
        next[0] = k;
        for (int i = 1; i < s.size(); ++i) {
            while (k > 0 && s[i] != s[k]) {
                k = next[k - 1];
            }
            if (s[k] == s[i]) {
                k++;
            }
            next[i] = k;
        }
    }

    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getNext(s, next);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) {
            return true;
        }
        return false;
    }    
};