class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                auto iter = map.find(nums1[i] + nums2[j]);
                if (iter == map.end()) {
                    map.insert(make_pair(nums1[i] + nums2[j], 1));
                } else {
                    iter->second++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < nums3.size(); ++i) {
            for (int j = 0; j < nums4.size(); ++j) {
                auto iter = map.find(0 - nums3[i] - nums4[j]);
                if (iter != map.end()) {
                    count += iter->second;
                }
            }
        }    
        return count;    
    }
};