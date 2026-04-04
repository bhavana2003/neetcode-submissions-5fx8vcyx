class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtrack(ans, temp, nums, 0);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int> nums, int i){
        if (i == nums.size()){
            ans.push_back(temp);
            return;
        }

        // Consider nums[i] in combination
        temp.push_back(nums[i]);
        backtrack(ans, temp, nums, i+1);
        temp.pop_back();

        // Not Consider nums[i] in combination
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        backtrack(ans, temp, nums, i+1);
    }
};
