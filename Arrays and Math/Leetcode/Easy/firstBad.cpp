//Leetcode Easy 278: Find the first bad version
//We have an array of size size n ([1,2,3...n]), where each number represents a version of a software. Each version after a particular version is 'bad'. To determine if a particular version is bad or not, we have been given an API isBadVersion which returns true if the version passed as a parameter is bad. We have to find the first bad version by making minimum no of calls to the API.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int high=n, low=1;
        while(low<=high){
            int mid=low +(high-low)/2;
            if(isBadVersion(mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
