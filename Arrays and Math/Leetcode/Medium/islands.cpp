#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    bfs(grid, i , j, visited);
                    count++;
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& visited){
        queue<pair<int, int>> q;
        q.push({row,col});
        visited[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();

        while(!q.empty()){
            int qRow = q.front().first;
            int qCol = q.front().second;
            q.pop();
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(abs(i) != abs(j)){
                        int neighbourRow = qRow + i;
                        int neighbourCol = qCol + j;
                        if(neighbourRow >=0 && neighbourCol >= 0 && neighbourRow < m && neighbourCol < n && grid[neighbourRow][neighbourCol] == '1' && visited[neighbourRow][neighbourCol] == 0){
                            q.push({neighbourRow, neighbourCol});
                            visited[neighbourRow][neighbourCol] = 1;
                    }
                    }
                    
                }
            }
        }
    }
};