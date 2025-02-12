#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int upper_count = 0, lower_count = 0;

        
        for (int i = 0; i < s.length(); i++) {
            if (isupper(s[i])) 
                upper_count++;
            else 
                lower_count++;
        }

        
        if (upper_count > lower_count) {
            for (int i = 0; i < s.length(); i++)
                s[i] = toupper(s[i]);
        } else {
            for (int i = 0; i < s.length(); i++)
                s[i] = tolower(s[i]);
        }

        cout << s << endl;
    }

    return 0;
}
