class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
    

     for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += dfs(grid, i, j, rows, cols);
                    break;
                }
            }
        }

        return perimeter;
    }
        private:
    int dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
            return 1;
        }

        if (grid[i][j] == -1) {
            return 0;
        }

        grid[i][j] = -1;
        return dfs(grid, i-1, j, rows, cols) +
               dfs(grid, i+1, j, rows, cols) +
               dfs(grid, i, j-1, rows, cols) +
               dfs(grid, i, j+1, rows, cols);
    }

};