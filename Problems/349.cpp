class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet1(nums1.begin(), nums1.end());
        unordered_set<int> hashSet2;
        for (int i = 0; i < nums2.size(); ++i) {
            if (hashSet1.find(nums2[i]) != hashSet1.end()) {
                hashSet2.insert(nums2[i]);
            }
        }
        vector<int> inter(hashSet2.begin(), hashSet2.end());
        return inter;
    }
};