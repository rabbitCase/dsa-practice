#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return traverse(m, n, 0, 0, memo);
    }
    int traverse(int& m, int& n, int i, int j, vector<vector<int>>& memo){
        if(i >= m || j >= n){
            return 0;
        }
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        memo[i][j] = traverse(m, n, i + 1, j, memo) + traverse(m, n, i, j + 1, memo);
        return memo[i][j];
    }
};