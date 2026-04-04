class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mp; // <(target-value), index>

        int n = nums.size();
        mp[target-nums[0]] = 1;

        for(int i=1; i<n; i++){
            if(mp[nums[i]]){
                return {mp[nums[i]]-1, i};
            }
            else{
                mp[target-nums[i]] = i+1;
            }
        }
        return {};
    }
};
