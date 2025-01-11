/*Leetcode Medium 11: You are given an integer array height of size n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such that the container can store the most amount of water.*/

/*Example height vector is: [1,8,6,2,5,4,8,3,7], here, maximum area for water to be stored will be between 8 (height[1]) and 7 (height[8]) because the area we will get if we store water between these vertical lines is height*length that is 7*7=49*/

//Updated code with two pointer method
/*Concept: We have two pointers, left and right where initially left points to the begininng of the array and right is at the end of the array. In this method, length between two container edges will simply be (right-left). Now, we find the area by multiplying length by the min(left,right), after the operation, if the value left points to is less than that pointed by right, then we increment left to point to the next element because of the possibilty of finding larger area if the next element is larger, otherwise we move right so that it points to one element prior to it */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i,left=0,right=height.size()-1;
        int area=0;
        while(left<right){
            area=max(area,(min(height[left],height[right])*(right-left)));
            height[left]>height[right]?right--:left++;
        }
        return area;
    }    
};

//This was the previous solution. It takes O((n*(n-1)^2)) time complexity which is why a TLE is encountered for 8/63 test cases
/*Concept: For every element, traverse through the array and calculate respective area with every succeeding element. This can be done through two for loops. In the area calculation, the height will be taken as the smaller of the two elements being compared (water can only be filled in the container upto the lowest height of the two lines) and length will be the distance between the two elements which will be kept track of by the count variable.*/
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int i,count=1,area,maxarea=0;
//         for(i=0;i<height.size();i++){
//             count=1;
//             for(int j=i+1;j<height.size();j++,count++){
//                 if(height[j]<height[i]){
//                     area=height[j]*count;
//                 }
//                 else{
//                     area=height[i]*count;
//                 }
//                 maxarea=max(maxarea,area);
//             }
//         }
//         return maxarea;
//     }
// };
