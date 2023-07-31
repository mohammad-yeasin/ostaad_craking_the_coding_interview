// Time - O(n) , Space - O(1)
int sum_of_natural_numbers(int n)
{
    // If n is not a natural number we will return 0
    if(n < 0) return 0;
    int sum = 0;
    
    for(int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}