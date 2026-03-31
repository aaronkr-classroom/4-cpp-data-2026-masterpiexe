#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    for (int i = 1; i <= 100; i++) {
        cout << setw(4) << i << "^2="
            << setw(5) << i * i << "  ";

        if (i % 10 == 0) cout << endl;
    }
    return 0;
}
