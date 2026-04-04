class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // return number of connected components
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    count++;
                    dfsTraversal(grid, i, j);
                }
            }
        }
        return count;
    }

    void dfsTraversal(vector<vector<char>> &grid, int r, int c){
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
            return;
        }

        if (grid[r][c] == '1'){
            grid[r][c] = '#';
            dfsTraversal(grid, r, c+1);
            dfsTraversal(grid, r+1, c);
            dfsTraversal(grid, r, c-1);
            dfsTraversal(grid, r-1, c);
        }
    }
};
