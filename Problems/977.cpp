class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int i = 0, j = nums.size() - 1;
        for (int k = nums.size() - 1; k >= 0; --k){
            if (abs(nums[i]) > abs(nums[j])){
                result[k] = nums[i] * nums[i];
                i++;
            }
            else{
                result[k] = nums[j] * nums[j];
                j--;
            }
        }
    return result;
    }
};