class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int letter[26]{0};
        for (int i = 0; i < words[0].length(); ++i) {
            letter[words[0][i] - 'a']++;
        }
        for (int i = 1; i < words.size(); ++i) {
            int temp[26]{0};
            for (int j = 0; j < words[i].length(); ++j) {
                temp[words[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                letter[j] = min(letter[j], temp[j]);
            }
        }
        vector<string> common;
        for (int i = 0; i < 26; ++i) {
            string s(1, i + 'a');
            for (int j = 0; j < letter[i]; ++j) {
                common.push_back(s);
            }
        }
        return common;
    }
};