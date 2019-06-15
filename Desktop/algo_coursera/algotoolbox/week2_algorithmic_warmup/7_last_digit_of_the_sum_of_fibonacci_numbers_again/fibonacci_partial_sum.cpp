#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

int get_fibonacci_partial_sum_fast(long long m, long long n)
{
    return (get_fibonacci_huge_fast(n+2, 10) + 10 - get_fibonacci_huge_fast(m+1, 10)) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
