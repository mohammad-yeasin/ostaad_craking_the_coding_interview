// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

// Time - O(logn) | Space - O(1) 
int findSmallest(vector<int>& inp)
{
    int left = 0, right = inp.size() - 1;
    int small;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(inp[left] < inp[right])
        {
            small = inp[left];
            right = mid - 1;
        }else {
            small = inp[right];
            left = mid + 1;
        }
    }
    return small;
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
