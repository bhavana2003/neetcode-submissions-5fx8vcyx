class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        vector<int>leftprod(n,1);
        vector<int>rightprod(n,1);

        int i = 1, j = n-2;
        while (i<n && j>=0){
            leftprod[i] = leftprod[i-1]*nums[i-1];
            rightprod[j] = rightprod[j+1]*nums[j+1];
            i++;
            j--;
        }

        for(int i=0; i<n; i++){
            res[i] = leftprod[i]*rightprod[i];
        }

        return res;
    }
};
