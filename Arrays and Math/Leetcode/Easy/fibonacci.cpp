#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    int fib(int n) {
        vector<int> memo(n + 1, -1);
        return dfs(memo, n);
    }

    int dfs(vector<int>& memo, int n){
        if(memo[n] != -1){
            return memo[n];
        }

        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        return memo[n] = dfs(memo, n - 1) + dfs(memo, n - 2);
    }
};