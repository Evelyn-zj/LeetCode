class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int n, int k, int start) {
        if (n == 0 && k == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i <= min(9, n); ++i) {
            path.push_back(i);
            backtracking(n - i, k - 1, i + 1);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 1);
        return result;
    }
};