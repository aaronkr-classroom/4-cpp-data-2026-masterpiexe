#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // 랜덤 시드

    for (int i = 1; i <= 100; i++) {
        int num = rand() % 101; // 0~100

        cout << setw(4) << num << "^2="
            << setw(6) << num * num << "  ";

        if (i % 10 == 0) cout << endl;
    }
    return 0;
}
