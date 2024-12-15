#include <iostream>
using namespace std;

int main() {
    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << cnt << ' ';
            cnt++;
        }
        cout << endl;
    }
    return 0;
}