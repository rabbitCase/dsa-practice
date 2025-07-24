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