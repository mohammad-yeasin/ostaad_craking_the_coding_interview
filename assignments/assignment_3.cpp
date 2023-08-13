// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>

using namespace std;

// space - O(n) and Time - O(n)
bool isValid(string input)
{
    // we are assuming the string only contains brackets, hence ignoring the validation
    stack<char> brackets;
    
    for(int i = 0; i < input.size(); i++)
    {
        if(input.at(i) == '(' || input.at(i) == '{' || input.at(i) == '[') 
        {
            brackets.push(input.at(i));
        }else {
            if(input.at(i) == ')')
            {
                if('(' == brackets.top()) {
                 brackets.pop();  
                }
                else return false;
            }
            else if(input.at(i) == '}')
            {
                if('{' == brackets.top()){
                    brackets.pop();  
                }
                else return false;
            }
            else if(input.at(i) == ']')
            {
                if('[' == brackets.top()){
                    brackets.pop();  
                }
                else return false;
            }
        }
    }
    
    return brackets.empty();
}

int main() {
    string input = "[{([)])}]";
    string output = isValid(input) ? "true" : "false";
    cout << output;
    return 0;
}
