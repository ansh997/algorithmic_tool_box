#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

/*int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;
    long long F0 = 0, F1 = 1, F = F0+F1, sum = F;
    for(long long i = 2; i<n-1; ++i){
        F = F0+F1;
        F0 = F1;
        F1 = F;
        sum+=F;
    }
    return sum%10;
}*/
// This solution is from geeks from geeks and uses O(log(n))
//using namespace std;
/*const int MAX = 1000;

// Create an array for memoization
int f[MAX] = {0};

// Returns n'th Fibonacci number using table f[]
long long fib(long long n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    // If fib(n) is already computed
    if (f[n])
        return f[n];

    int k = (n & 1) ? (n + 1) / 2 : n / 2;

    // Applying above formula [Note value n&1 is 1
    // if n is odd, else 0].
    f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
                   : (2 * fib(k - 1) + fib(k)) * fib(k);

    return (long long)f[n];
}

// Computes value of first Fibonacci numbers
long long calculateSum(long long n)
{
    return fib(n + 2) - 1;
}
*/
long long get_pisano_period_length(long long m)
{
    long long F1 = 0, F2 = 1, F = F1 + F2;
    for (int i = 0; i < m * m; i++)
    {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
        if (F1 == 0 && F2 == 1)
            return i + 1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    long long remainder = n % get_pisano_period_length(m);

    long long F1 = 0, F2 = 1, F = remainder;
    for (int i = 1; i < remainder; i++)
    {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
    }
    return F % m;
}

int fibonacci_sum_fast(long long n){
    return(get_fibonacci_huge_fast(n+2, 10)-1+10)%10;
}
int main()
{
    //stress testing
    /*while(true){
        int a = rand()%100000;
        int res1 = fibonacci_sum_naive(a);
        int res2 = fibonacci_sum_fast(a);
        cout<<"a: "<<a<<endl;
        if (res1 != res2){
            cout << "Wrong Answer: " << res1 << " " << res2 << endl;
            break;
        }
        else
        {
            cout << "OK!" << endl;
        }
    }
*/
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n)<<endl;
    //std::cout << calculateSum(n) << "\n";
    std::cout << fibonacci_sum_fast(n) << endl;
}
