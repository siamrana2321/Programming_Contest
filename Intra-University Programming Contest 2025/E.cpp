#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        int w;
        cin >> w;

        if (w % 2 == 0 && w >= 4)
            cout << "Case " << i << ": YES" << endl;
        else
            cout << "Case " << i << ": NO" << endl;
    }
    
    return 0;
}

