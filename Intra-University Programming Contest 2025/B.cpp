#include <iostream>
#include <cstdio>
#include <math.h>



using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int L;
        cin >> L;

        double flag_area = 0.6 * L * L;
        double red_area = acos(-1.0) * (L * L) / 25.0;
        double green_area = flag_area - red_area;

        printf("%.2f %.2f\n", red_area, green_area);
    }

    return 0;
}
