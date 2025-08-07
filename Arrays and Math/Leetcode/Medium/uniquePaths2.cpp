#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return traverse(obstacleGrid, 0, 0, memo);
    }
    int traverse(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& memo){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(i >= m || j >= n){
            return 0;
        }
        
        if(obstacleGrid[i][j] == 1){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        return memo[i][j] = traverse(obstacleGrid, i + 1,j, memo) + traverse(obstacleGrid, i, j + 1, memo);
    }
};