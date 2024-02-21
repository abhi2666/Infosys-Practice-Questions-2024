class Solution {
private:
    void dfs(int i, int j, int rows, int cols, vector<vector<int>>&vis, vector<vector<char>>&grid){
        // store indexes of 1's in the grid in queue and for each such pair, look for 1's as their neighbours in all 8 directions
        vis[i][j] = 1;
        int dir_row [] = {0, -1, 0, 1};
        int dir_col [] = {-1, 0, 1, 0};
        for(int k = 0; k < 4; k++){
            int nr = i + dir_row[k];
            int nc = j + dir_col[k];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc]=='1' && !vis[nr][nc]){
                // means there you can take this 1
                dfs(nr, nc, rows, cols, vis, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>vis(rows, vector<int>(cols, 0)); 
        int totalIslands = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    ++totalIslands;
                    dfs(i, j, rows, cols, vis, grid);
                }
            }
        }
        return totalIslands;
    }
};