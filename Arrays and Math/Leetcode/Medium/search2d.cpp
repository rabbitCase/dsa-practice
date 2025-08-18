//Leetcode Medium 74: Given a 2d matrix with elements in each row in non-decreasing order, return true if target is present in the matrix
//For an O(log(m*n)) solution, we are basically performing binary search on a 2d matrix
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//O(log(m*n)) solution : start from the top right and move in a staircase like manner i.e move down if cell value < target. If cell value > target, it's in the same row, so start going left until you find it.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while(i < m && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            matrix[i][j] < target ? i++ : j--;
        }
        return false;
    }
};
//Previous solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[i][0]<target){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==target)
                    return true;
                }
            }
            else if(matrix[i][0]==target)
            return true;
        }
        return false;
    }
};
