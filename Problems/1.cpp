class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            map.insert(make_pair(nums[i], i));
        }
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end() && iter->second != i) {
                vector<int> result;
                result.push_back(i);
                result.push_back(iter->second);
                return result;
            }
        }
        return {};
    }
};