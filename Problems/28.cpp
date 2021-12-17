class Solution {
public:
    void getNext(string needle, int* next) {
        int k = 0;
        next[0] = k;
        for (int i = 1; i < needle.size(); ++i) {
            while (k > 0 && needle[i] != needle[k]) {
                k = next[k - 1];
            }
            if (needle[k] == needle[i]) {
                k++;
            }
            next[i] = k;
        }
    }
    
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(needle, next);
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};