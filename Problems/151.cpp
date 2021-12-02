class Solution {
public:
    void reverse(string& s, int begin, int end) {
        for (int i = 0; i < (end - begin) / 2; ++i) {
            swap(s[begin + i], s[end - i - 1]);
        }
    }

    string reverseWords(string s) {
        reverse(s, 0, s.size());
        int i = 0, j = 0, l = s.size(), temp = 0;
        while (s[i] == ' ') {
            i++;
        }
        while (s[l-1] == ' ') {
            l--;
        }
        while (i < l) {
            s[j] = s[i];
            if (s[i] == ' ') {
                reverse(s, temp, j);
                temp = j + 1;
                while (s[i + 1] == ' ') {
                    i++;
                }
            }    
            i++;
            j++;
        }
        reverse(s, temp, j);
        s.resize(j);
        return s;
    }
};