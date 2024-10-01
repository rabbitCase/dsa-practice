#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i,count=1,area,maxarea=0;
        for(i=0;i<height.size();i++){
            count=1;
            for(int j=i+1;j<height.size();j++,count++){
                if(height[j]<height[i]){
                    area=height[j]*count;
                }
                else{
                    area=height[i]*count;
                }
                maxarea=max(maxarea,area);
            }
        }
        return maxarea;

    }
};

