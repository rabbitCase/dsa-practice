//Leetcode Medium 973
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
                pq.push({distance, points[i]});
                if(pq.size() > k){
                    pq.pop();
                }
        }
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};