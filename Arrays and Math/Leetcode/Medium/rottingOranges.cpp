//Leetcode Medium 994
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        bool isolated = false;
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        bfs(res, grid, q);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    isolated = true;
                }
            }
        }
        return isolated ? -1 : res;
    }
    void bfs(int& res, vector<vector<int>>& grid, queue<pair<int,int>>& q){
        
        while(!q.empty()){
            int size = q.size();
            bool rot = false;
            while(size--){
                int nrow = q.front().first;
                int ncol = q.front().second;
                q.pop();
                if(nrow - 1 >= 0 && grid[nrow - 1][ncol] == 1){
                    grid[nrow - 1][ncol] = 2;
                    q.push({nrow - 1, ncol});
                    rot = true;
                }
                if(ncol - 1 >= 0 && grid[nrow][ncol - 1] == 1){
                    grid[nrow][ncol - 1] = 2;
                    q.push({nrow, ncol - 1});
                    rot = true;
                }
                if(nrow + 1 < grid.size() && grid[nrow + 1][ncol] == 1){
                    grid[nrow + 1][ncol] = 2;
                    q.push({nrow + 1, ncol});
                    rot = true;
                }
                if(ncol + 1 < grid[0].size() && grid[nrow][ncol + 1] == 1){
                    grid[nrow][ncol + 1] = 2;
                    q.push({nrow, ncol + 1});
                    rot = true;
                }
            }
            if(rot)
            res++;
        }
    }
};