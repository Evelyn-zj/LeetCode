class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min, n, sum;
        min = nums.size() + 1;
        n = 0;
        sum = 0;
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            n++;
            while (sum >= target){
                if (n < min){
                    min = n;
                }
                sum = sum - nums[i + 1 - n];
                n--;
            }
        }
        if (min == nums.size() + 1){
            return 0;
        }
        else{
            return min;
        }
    }
};