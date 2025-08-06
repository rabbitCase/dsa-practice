//Leetcode Medium 64
//Recursively solve the problem (subproblem) for the new matrix obtained when we move row wise or column wise. Use memoization to speed up repetitive function calls
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        return traverse(grid, memo, 0, 0);
    }
    int traverse(vector<vector<int>>& grid, vector<vector<int>>& memo, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n){
            return INT_MAX;
        }
        if(i == m - 1 && j == n - 1){
            return grid[i][j];
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        return memo[i][j] = grid[i][j] + min(traverse(grid, memo, i, j + 1), traverse(grid, memo, i + 1, j));
    }
};