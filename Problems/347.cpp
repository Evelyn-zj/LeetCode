class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = 1;
            } else {
                map[nums[i]]++;
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
        for (auto it = map.begin(); it != map.end(); ++it) {
            que.push(*it);
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<int> result;
        while (!que.empty()) {
            result.push_back(que.top().first);
            que.pop();
        }
        return result;
    }
};