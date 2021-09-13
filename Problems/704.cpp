class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin, end, middle, pos;
        begin = 0;
        end = nums.size() - 1;
        pos = -1;
        while (begin <= end){
            middle = (begin + end) / 2;
            if (nums[middle] == target){
                pos = middle;
                break;
            }
            else if (nums[middle] < target){
                begin = middle + 1;
            }
            else{
                end = middle - 1;
            }
        }
        return pos;
    }
};