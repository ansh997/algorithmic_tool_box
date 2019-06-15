  
#include <iostream>
#include <cstdlib>
using namespace std;

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long) a * b;
}

int euclid_gcd(long a, long b) {
    int divisor = a >= b ? a : b;
    int dividend = a <= b ? a : b;
    while (divisor != 0) {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}
int gcd(int a , int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b , a % b);
}

long long lcm(long a , long b)
{
    return a * b / gcd(a , b);
}

long long lcm_fast(long long a, long long b) {
    return (a * b) / euclid_gcd(a, b);
}

int main() {

     //stress testing
   while (true){
     int a = rand()%100000000;
     int b = rand() % 100000000;
     cout << "a: " << a << ", b: " << b << endl;
     //int res1 = lcm_naive(a, b);
     int res2 = lcm(a, b);
     if (res2<0){
      cout<<"Wrong! ";
      cout<<res2<<endl;
      break;
     }
     else
     {
       cout<<"OK!"<<endl;
     }
     
     /* if (res1 != res2){
       cout<<"Wrong Answer! "<<res1<<" "<<res2<<endl;
       break;
    {
       cout<<"OK!"<<endl;
    }*/
}
    long long a, b;
    std::cin >> a >> b;
    std::cout << lcm_fast(a, b) << std::endl;
    return 0;
}