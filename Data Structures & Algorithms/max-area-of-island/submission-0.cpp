class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // return max of connected components sum
        int maxArea = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if (grid[i][j] == 1){
                    maxArea = max(maxArea, dfsSum(grid, i, j));
                }
            }
        }
        return maxArea;
    }

    int dfsSum(vector<vector<int>> &grid, int r, int c){
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
            return 0;
        }

        if (grid[r][c] == 1){
            grid[r][c] = -1;
            return 1 + dfsSum(grid, r, c+1) + dfsSum(grid, r+1, c) + dfsSum(grid, r, c-1) + dfsSum(grid, r-1, c);
        }

        return 0;
    }
};
