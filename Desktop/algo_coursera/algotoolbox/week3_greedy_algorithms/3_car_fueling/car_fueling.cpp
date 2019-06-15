#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int currentRefill = 0;
    int numrefill = 0;
    int distcovered = 0;

    while(distcovered<dist){
        int lastrefill = currentRefill;
        if(distcovered<dist && stops[currentRefill+1]-stops[currentRefill]<tank){
            distcovered+=stops[currentRefill];
            currentRefill++;
        }
        if (currentRefill== lastrefill){
            return -1;
        }

        if(distcovered<dist)
            numrefill++;

    }
    return numrefill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
