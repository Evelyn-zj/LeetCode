class Solution {
public:
    bool isAnagram(string s, string t) {
        int letter[26]{0};
        for (int i = 0; i < s.length(); ++i) {
            letter[(int)s[i] - (int)('a')]++;
        }
        for (int i = 0; i < t.length(); ++i) {
            letter[(int)t[i] - (int)('a')]--;
        }
        for (int i = 0; i < 26; ++i) {
            if (letter[i] != 0) {
                return false;
            }
        }
        return true;
    }
};