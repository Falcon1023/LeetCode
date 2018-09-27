#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> rows(n, -1);
        vector<vector<int>> paths(m, rows);
        return localPathWithObstacles(obstacleGrid, paths, 0, 0, m, n);
    }
    
    int localPathWithObstacles(vector<vector<int>> &obstacleGrid, vector<vector<int>> &paths, int row, int col, int m, int n) {
        
        if (paths[row][col] != -1)
            return paths[row][col];
        
        if (row == m-1 && col == n-1) {
            paths[row][col] = obstacleGrid[row][col] == 1 ? 0 : 1;
        } else if (row == m-1) {
            paths[row][col] = obstacleGrid[row][col] == 1 ? 0 : localPathWithObstacles(obstacleGrid, paths, row, col+1, m, n);
        } else if (col == n-1) {
            paths[row][col] = obstacleGrid[row][col] == 1 ? 0 : localPathWithObstacles(obstacleGrid, paths, row+1, col, m, n);
        } else {
            paths[row][col] = obstacleGrid[row][col] == 1 ? 0 :
                localPathWithObstacles(obstacleGrid, paths, row, col+1, m, n) +
                localPathWithObstacles(obstacleGrid, paths, row+1, col, m, n);
        }
        return paths[row][col];
    }
};