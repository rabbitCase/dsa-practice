//Leetcode Easy 278: Find the first bad version
//We have an array of size size n ([1,2,3...n]), where each number represents a version of a software. Each version after a particular version is 'bad'. To determine if a particular version is bad or not, we have been given an API isBadVersion which returns true if the version passed as a parameter is bad. We have to find the first bad version by making minimum no of calls to the API.
// bool isBadVersion(int version);
//Concept: We have to search for the number in the array which is "bad", the problem reduces to binary search where we check if the middle element is bad. If it is not, we no longer need the left half of the array and update the low pointer, if it is bad, we no longer need the right half of the array, so we update the hifgh pointer and continue the search for more bad versions towards the left half of the array.
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
