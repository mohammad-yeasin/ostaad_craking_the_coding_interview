#include <iostream>
using namespace std;

// Time O(b) and Space O(b)
int addition(int a, int b)
{
    if(a == 0 || b == 0) return 0;
    b--;
    return a + addition(a, b);
}

int main() {
    int a = 4;
    int b = 5;
    if(a >= b) cout << addition(a, b);
    else cout << addition(b, a);

    return 0;
}
