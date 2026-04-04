class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int i=0;
        int maxi = INT_MIN;
        for(int j=0; j<k; j++){
            maxi = max(maxi, nums[i+j]);
        }
        res.push_back(maxi);
        i++;

        while (i <= (int)nums.size()-k){
            if(nums[i+k-1] >= maxi){
                maxi = nums[i+k-1];
            }
            else{
                if (maxi == nums[i-1]){
                    maxi = INT_MIN;
                    for(int j=0; j<k; j++){
                        maxi = max(maxi, nums[i+j]);
                    }
                }
                // else maxi = maxi
            }
            res.push_back(maxi);
            i++;
        }
        return res;
    }
};
