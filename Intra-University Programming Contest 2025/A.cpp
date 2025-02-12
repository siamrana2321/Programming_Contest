#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int case_no = 1; case_no <= T; case_no++) {
        double AB, AC, BC, r;
        cin >> AB >> AC >> BC >> r;

        
        double AD = AB * sqrt(r / (1 + r));

        
        printf("Case %d: %.7f\n", case_no, AD);
    }

    return 0;
}
