class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
   
    typedef vector<vector<int>> VEC2;
    
    bool dfs(int r, int c, VEC2 &grid, VEC2 &vis){

        if(grid[r][c] == 2){return 1;}
        
        int delta_r[] = {-1, 1, 0, 0};
        int delta_c[] = {0, 0, -1, 1};
        int row = grid.size();
        int col = grid[0].size();
        int r1, c1;
        
        vis[r][c] = 1;
        
        for(int i = 0; i < 4; i++){
            r1 = r + delta_r[i];
            c1 = c + delta_c[i];
            if(r1 >= 0 && r1 < row && c1 >= 0 && c1 < col && grid[r1][c1] && !vis[r1][c1]){
                if(dfs(r1, c1, grid, vis)) return 1;
            } 
        }
        
        return 0;
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        bool exist;
        
        VEC2 vis(row, vector<int>(col, 0));
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(grid[r][c] == 1) {
                    exist = dfs(r, c, grid, vis); break;
                }
            }
        }
        return exist;
    }
};
