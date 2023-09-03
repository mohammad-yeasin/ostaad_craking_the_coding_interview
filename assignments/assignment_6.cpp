// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

// Time complexity O(n), Space complexity O(n)
string removeAdjacentDuplicates(string inp)
{
    stack<char> storage;
    stack<char> reverse;
    string result;
    
    for (int i = 0; i < inp.size(); i++)
    {
        if(!storage.empty() && storage.top() == inp[i]) storage.pop();
        else storage.push(inp[i]);
    }
    
    while(storage.size() > 0)
    {
        reverse.push(storage.top());
        storage.pop();
    }
    
    while(reverse.size() > 0)
    {
        result += reverse.top();
        reverse.pop();
    }
    
    return result;
} 

int main() {
    string inp = "azxxzy";
    cout << removeAdjacentDuplicates(inp);

    return 0;
}
