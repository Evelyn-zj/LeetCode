class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hashSet;
        hashSet.insert(n);
        while (n != 1) {
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = sum;
            if (hashSet.find(n) != hashSet.end()) {
                return false;
            } else {
                hashSet.insert(n);
            }
        }
        return true;
    }
};