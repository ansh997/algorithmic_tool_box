#include <iostream>
#include <cstdlib>
using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_fast(long long a, long long b)
{
/* 
  if (a <= b)
  {
    if (a == 0)
      return b;
    return (gcd_fast(b % a, a));
  }
  else
  {
    //a = min(a, b);
    //b = max(a, b);
    int tmp = a;
    a = b;
    b = tmp;
    return gcd_fast(a, b);
  }*/
long long divisor = a >= b ? a : b;
long long dividend = a <= b ? a : b;
while (divisor != 0)
{
  long long remainder = dividend % divisor;
  dividend = divisor;
  divisor = remainder;
    }
    return dividend;
}

long long lcm_fast(long long a, long long b){
      if(a ==0 && b == 0)
        return 0;
      return ((a*b)/gcd_fast(a, b));
}

int main() {
     
  //stress testing
   while (true){
     int a = rand()%100000000;
     int b = rand() % 100000000;
     cout << "a: " << a << ", b: " << b << endl;
     //int res1 = lcm_naive(a, b);
     int res2 = lcm_fast(a, b);
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
