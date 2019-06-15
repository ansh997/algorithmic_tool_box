#include <iostream>
#include<cmath>
using namespace std;
const int MAX = 1000;

// Create an array for memoization
long long f[MAX] = {0};

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

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


int fibonacci_sum_squares_fast(long long n){
    return ((get_fibonacci_huge_fast(n) % 10) * (get_fibonacci_huge_fast(n + 1) % 10)) % 10;
} 
int main()
{
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n);
    //std::cout << fib(n)<<"\n";
    std::cout << fibonacci_sum_squares_fast(n);
}
