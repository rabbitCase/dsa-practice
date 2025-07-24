//Leetcode Medium 134
//If we cannot travel from i to (i + 1)th station, all stations before i become invalid, So we move the possible valid index one to the right. If we find an index from which travel is possible till the end of gas[] then that index is the valid station as we are guaranteed that a unique solution exists, so we don't have to check if we can loop back to that valid index or not.  
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int n = gas.size();
        int gasTank = 0, start = 0;

        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            gasTank += gas[i];
            gasTank -= cost[i];
            if (gasTank < 0) {
                gasTank = 0;
                start = i + 1;
            }
        }
        return (totalGas < totalCost) ? -1 : start;
    }
};