class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < (int)nums.size() - 3; ++i) {
            if (nums[i] + nums[i + 1] > target - nums[i + 2] - nums[i + 3]) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < (int)nums.size() - 2; ++j) {
                if (nums[i] + nums[j] > target - nums[j + 1] - nums[j + 2]) {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = nums.size() - 1;
                while (k < l) {
                    if (nums[i] + nums[j] > target - (nums[k] + nums[l])) {
                        l--;
                    } else if (nums[i] + nums[j] < target - (nums[k] + nums[l])) {
                        k++;
                    } else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1]) {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l - 1]) {
                            l--;
                        }
                        k++;
                        l--;
                    }
                }
            }
        }    
        return result;
    }
};