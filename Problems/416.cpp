class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum = sum / 2;
        bool dp[nums.size()][sum + 1];
        for (int i = 0; i <= sum; ++i) {
            dp[0][i] = false;
        }
        if (nums[0] <= sum) {
            dp[0][nums[0]] = true;
        }
        if (dp[0][sum]) {
            return true;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= sum; ++j) {
                dp[i][j] = dp[i-1][j];
                if (nums[i] <= j) {
                    dp[i][j] = dp[i][j] | dp[i-1][j-nums[i]];
                }
            }
            if (dp[i][sum]) {
                return true;
            }
        }
        return false;
    }
};