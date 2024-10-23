#include <iostream>
using namespace std;

// Recursive function to calculate the nth Fibonacci number
int fibonacci_recursive(int n)
{
    if (n <= 0)
        return 0; // Base case for F(0)
    if (n == 1)
        return 1;                                                   // Base case for F(1)
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2); // Recursive call
}

int main()
{
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    int result = fibonacci_recursive(n);
    cout << "Fibonacci number F(" << n << ") is " << result << endl;

    return 0;
}
