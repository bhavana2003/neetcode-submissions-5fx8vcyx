class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(ans, temp, candidates, target, 0, 0);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int> nums, int target, int currSum, int i){
        if (i >= nums.size() || currSum >= target){
            if (currSum == target){
                ans.push_back(temp);
            }
            return;
        }

        // Consider nums[i] in combination
        temp.push_back(nums[i]);
        backtrack(ans, temp, nums, target, currSum+nums[i], i+1);
        temp.pop_back();

        // Not Consider nums[i] in combination
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        backtrack(ans, temp, nums, target, currSum, i+1);
    }
};
