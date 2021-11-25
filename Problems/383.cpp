class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letter[26] = {0};
        for (int i = 0; i < magazine.size(); ++i) {
            letter[(int)magazine[i] - (int)('a')]++;
        }
        for (int i = 0; i < ransomNote.size(); ++i) {
            letter[(int)ransomNote[i] - (int)('a')]--;
            if (letter[(int)ransomNote[i] - (int)('a')] < 0) {
                return false;
            }
        }
        return true;
    }
};