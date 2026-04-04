class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int target = n-1;
        for(int i=n-2; i>=0; i--){
            int j = nums[i] + i;
            if (j >= target) target = i;
        }

        return (target == 0);
    }
};
