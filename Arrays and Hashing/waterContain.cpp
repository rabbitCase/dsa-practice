/*Leetcode Medium 11: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such that the container contains the most water.*/

/*Example height vector is: [1,8,6,2,5,4,8,3,7], here, maximum area for water to be stored will be between 8 (height[1]) and 7 (height[8]) because the are we will get if we store water between these vertical lines is height*length that is 7*7=49*/
//This solution takes O((n*(n-1)^2)) time complexity which why I got TLE for 8/63 test cases, I will soon update the code with the two pointer method
/*Concept: For every element, traverse through the array and calculate respective area with every succeeding element. This can be done through two for loops. In the area calculation, the height will be taken as the smaller of the two elements being compared (water can only be filled in the container upto the lowest height of the two lines) and length will be the distance between the two elements which will be kept track of by the count variable.*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i,count=1,area,maxarea=0;
        for(i=0;i<height.size();i++){
            count=1;//reset count for every element as newa area will be calculated for every element
            for(int j=i+1;j<height.size();j++,count++){//as we traverse the array, count also increases, giving us the length each time we move forward
                if(height[j]<height[i]){
                    area=height[j]*count;
                }
                else{
                    area=height[i]*count;
                }
                maxarea=max(maxarea,area);//get the maximum area calculated so far
            }
        }
        return maxarea;

    }
};

