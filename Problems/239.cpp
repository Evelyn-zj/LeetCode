class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        for (int i = 0; i < k; ++i) {
            while (!que.empty() && que.back() < nums[i]) {
                que.pop_back();
            }
            que.push_back(nums[i]);
        }
        vector<int> result;
        result.push_back(que.front());
        for (int i = k; i < nums.size(); ++i) {
            if (que.front() == nums[i - k]) {
                que.pop_front();
            }
            while (!que.empty() && que.back() < nums[i]) {
                que.pop_back();
            }
            que.push_back(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};