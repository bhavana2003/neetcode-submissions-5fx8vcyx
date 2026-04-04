class Solution {
public:
    vector<pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;

        // Step 1: Push all gates
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        // Step 2: BFS
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            for(auto dir : directions){
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr>=0 && nc>=0 && nr<m && nc<n &&
                   grid[nr][nc] == INT_MAX){

                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
    }
};