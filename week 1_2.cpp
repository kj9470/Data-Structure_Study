#include <iostream>
using namespace std;

int main() {
    string s;
    int count, n;
    cin >> count;

    while(count--){
        cin >> s;
        n = s.size();
        cout << s[0] << s[n - 1] << "\n";
    }
    return 0;
}
