//Leetcode Medium 973: K closest points to origin
//We have been given a vector matrix of type [[x0,y0],[x1,y1]...[xn,yn]] where [Xi,Yi] are coordinates in a 2D plane and an integer K. We have to find K number of points which are the closest to origin. In other words we have to find the euclidean distance of these points from (0,0) and return the K least distance.
//Concept: Euclidean distance between two points is √((x1 - x2)2 + (y1 - y2)2), here, one the pair of coordinates are that of the origin so the distance simplies to √(x2 + y2). 

//Incorrect approach: Using a map. A map could be used to store key-value pairs , mapping the distance with the coordinates. As a map stores unique values in sorted order, we could return the first k coordinates as they would already be sorted in ascending order (note that a map sortes by values and not keys, therefore it is important to map the distance to coordinates and not the coordinates to distance, as we need to return the first K sorted coordinates). However, this creates an edge case. As the map stores only unique values, we could get unexpected results if the distance of two points are same. For example, matrix = [[1,0],[0,1]] and K =2, here the distance for both points is same, so the answer should be [0,1],[1,0] but we only get [1,0] as [0,1] gets overwritten.

//To allow duplicates, we can make use of a priority_queue (also called a max heap) which is a binary tree in which each parent has a node greater than or equal to its children. Therefore, duplicates are allowed and the structure of tree is changed on every key-value insertion. This allows us to pop the largest element using the pop() function if the size of the queue gets bigger than K. Finally we push all the queue elemnts into the result vector and return it.

//Note that the sqrt function isn't strictly needed as it's application won't change the inequality between the distances (eg. if 16 > 4 then sqrt(16) is still greater than sqrt(4)).
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> result;
        for(int i=0;i<points.size();i++){
                int distance = pow(points[i][0],2) + pow(points[i][1],2);
                pq.push({distance, points[i]});//pushed in a way that the max heap structure is not destroyed
                if(pq.size() > k){
                    pq.pop();//pops the highest priority element, which in this case, is the max element 
                }
        }
        //now the queue contains only the K closest points to origin
        while(!pq.empty()){
            result.push_back(pq.top().second); //.first and .second references the key and value pairs respectively
            pq.pop();
        }
        return result;
    }
};
//Map solution: error with duplicate distances
// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         map<double, vector<int>> mpp; //double isn't necessary, distance can be int also as we just need to compare the magnitude
//         vector<vector<int>> result;
//         int count=0;
//         for(int i=0;i<points.size();i++){
//                 double distance= pow(points[i][0],2) + pow(points[i][1],2);
//                 mpp[distance] = {points[i]};
//         }
//         for(auto x : mpp){
//             if(count<k)
//             result.push_back(x.second);
//             count++;
//         }
//         return result;
//     }
// };
