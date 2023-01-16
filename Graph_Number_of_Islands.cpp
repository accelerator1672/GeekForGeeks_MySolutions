//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int r, int c, int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[r][c] = 1;
        int r1, c1;
        int delta_r[]= {-1, -1, 0, 1, 1, 1, 0, -1};
        int delta_c[] = {0, 1, 1, 1, 0, -1, -1, -1};
        
        for(int i =0; i< 8; i++){
            r1 = r + delta_r[i];
            c1 = c + delta_c[i];
            if(r1 >=0 && r1 < row && c1 >= 0 && c1 < col && grid[r1][c1] == '1' && !vis[r1][c1]){
                dfs(r1, c1, row, col, vis, grid);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int col = grid[0].size();
        int row = grid.size();
        int num = 0;
        
        vector<vector<int>> vis(row ,vector<int> (col, 0));
        
        for(int r =0; r < row; r ++){
            for(int c = 0; c < col; c++){
                if(grid[r][c] == '1' && !vis[r][c]){
                    dfs(r, c, row, col, vis, grid); 
                    num++;
                }
            }
        }
        return num;
    }
};
