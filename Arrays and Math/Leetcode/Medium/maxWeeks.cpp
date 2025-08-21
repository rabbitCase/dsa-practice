//Leetcode Medium 1953
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long n = milestones.size();
        long long total = 0;
        sort(milestones.begin(), milestones.end());
        long long largest = milestones[n - 1];
        for(int i = 0; i < n; i++){
            total += milestones[i];
        }
        long long rest = total - largest;
        return (largest > rest) ? 2*rest + 1 : total;
    }
};