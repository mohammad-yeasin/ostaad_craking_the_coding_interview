// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>

using namespace std;

bool compare_col(const vector<int>& v1,const vector<int>& v2) 
{ 
    return v1[1] < v2[1]; 
} 

// Space 0(nlogn) and Time O(1)
int findMaxDisjointIntervals(vector<vector<int>>& inp) {
    int n = inp.size();
    if (n == 0) return 0;

    // Sort the intervals by their ending points
    sort(inp.begin(), inp.end(), compare_col);

    int count = 1, k = 0;

    for (int i = 1; i < n; i++) {
        if (inp[i][0] > inp[k][1]) {
            count++;
            k = i;
        }
    }
    return count;
}

int main() {
    // Write C++ code here
    vector< vector<int> > vect{
        {1,4}, 
        {2,3}, 
        {4,6},
        {8,9}
    };
    
    // vector< vector<int> > vect{
    //     {1,9}, 
    //     {2,3}, 
    //     {5,7}
    // };
    
    cout << findMaxDisjointIntervals(vect);
    return 0;
}
