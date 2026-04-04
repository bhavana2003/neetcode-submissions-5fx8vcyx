class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int,int>,unordered_set<char>> grid;

        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] != '.'){
                    char c = board[i][j];
                    pair grid_indices = {i/3, j/3};

                    if(rows[i].count(c))    return false;
                    if(cols[j].count(c))    return false;
                    if(grid[grid_indices].count(c)) return false;

                    rows[i].insert(c);
                    cols[j].insert(c);
                    grid[grid_indices].insert(c);
                }
            }
        }
        return true;
    }
};
