#include <iostream>
#include<cstdlib>
using namespace std;


int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b){
  

  if(a<=b){
    if(a == 0)
      return b;
    return gcd_fast(b%a, a);
  }
  else{
    //a = min(a, b);
    //b = max(a, b);
    int tmp = a;
    a = b;
    b = tmp;
    return gcd_fast(a, b);
  }
  

  
}

int main() {

  //stress testing
  // while(true){
  //   int a = rand()%10;
  //   int b = rand()%10;
  //   cout<<"a: "<<a<<", b: "<<b<<endl;
  //   int res1 = gcd_naive(a, b);
  //   //cout<<"res1: "<<res1<<endl;
  //   int res2 = gcd_fast(a, b);
  //   if(res1!=res2) {
  //       cout<<"Wrong answer: "<< res1 <<" " << res2<<endl;
  //       break;
  //     }
  //     else{
  //     cout<<"OK!"<<endl;
  //     }
    

  // }
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
