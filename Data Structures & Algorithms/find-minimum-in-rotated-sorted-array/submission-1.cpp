class Solution {
public:
    int findMin(vector<int> &nums) {
        int minValue = 1001;
        int l = 0, r = nums.size()-1;
        while (l<=r){
            // Non-rotated case
            if (nums[l] < nums[r]) {
                minValue = min(minValue, nums[l]);
                break;
            }

            int m = (l+r)/2;
            minValue = min(minValue, nums[m]);
            if (nums[m] >= nums[r]){
                l = m+1;
            }
            else{
                r = m;
            }
        }
        return minValue;
    }
};
