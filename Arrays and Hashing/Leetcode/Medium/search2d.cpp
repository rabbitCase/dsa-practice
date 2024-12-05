#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//pending O(log(m*n)) solution
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