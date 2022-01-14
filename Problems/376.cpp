class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        int n = 1;
        while (n < nums.size() && nums[n] == nums[0]) {
            n++;
        }
        if (n >= nums.size()) {
            return 1;
        }
        int num = 2;
        int diff = nums[n] - nums[0];
        for (int i = n + 1; i < nums.size(); ++i) {
            if (diff > 0 && nums[i] < nums[n] || diff < 0 && nums[i] > nums[n]) {
                diff = nums[i] - nums[n];
                num++;
            } 
            n = i;
        }
        return num;
    }
};