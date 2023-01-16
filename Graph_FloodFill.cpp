class Solution {
public:
    void dfs(int r, int c, int color, int newColor, vector<vector<int>> &image, vector<vector<int>> &visited){
        int delta_r[] = {-1, 0, 1, 0};
        int delta_c[] = { 0, -1, 0, 1};
        int r1, c1; 
        int row = image.size();
        int col = image[0].size();
        
        image[r][c] = newColor;
        visited[r][c] = 1;
        
        for(int i =0; i < 4; i ++){
            r1 = r + delta_r[i];
            c1 = c + delta_c[i];
            if(r1 >= 0 && r1 < row && c1 >= 0 && c1 < col && image[r1][c1] == color && !visited[r1][c1]){
                dfs(r1, c1, color, newColor, image, visited);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        int color = image[sr][sc]; 
        
        vector<vector<int>> visited(row, vector<int>(col, 0));
        dfs(sr, sc, color, newColor, image, visited);
        
        return image;
        
    }
};
