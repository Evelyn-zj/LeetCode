public:
    string replaceSpace(string s) {
        int n = 0, l = s.length();
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                n++;
            }
        }
        s.resize(s.length() + n * 2);
        int j = s.length() - 1;
        for (int i = l - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 3;
            } else {
                s[j] = s[i];
                j--;
            }
        }
        return s;
    }
};