class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int l = 0, r = m*n - 1;
        while (l <= r){
            int mid = (l+r)/2;
            int j = mid % n;
            int i = mid / n;

            if (target == matrix[i][j]){
                return true;
            }
            else if (target > matrix[i][j]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return false;
    }
};
