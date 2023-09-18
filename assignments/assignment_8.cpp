// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

// Time - O(logn) | Space - O(1) 
int findSmallest(vector<int>& nums)
{
    int start = 0,end = nums.size()-1; 
    while(start<end)
    { 
        int mid = (start + end)/2;
        if(nums[mid]>nums[end]) start = mid+1; 
        else end = mid; 
    } 
    return nums[start];
}

int main() {
    vector<int> inpA = {3,4,5,1,2};
    vector<int> inpB = {4,5,6,7,0,1,2};
    vector<int> inpC = {11,13,15,17};
    
    cout << findSmallest(inpA) << endl;
    cout << findSmallest(inpB) << endl;
    cout << findSmallest(inpC) << endl;

    return 0;
}


/*
3,4,5,1,2
l=0
r=4
m=2
---
l=3
r=4
m=3
*/
