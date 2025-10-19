#include <iostream>

using namespace std;

int main() {
    int bilangan, asli;

    cout << "Masukkan bilangan asli: ";
    cin >> asli;

    bilangan = 1;
    int jumlah = 0;
    while (bilangan <= asli) {
        if (bilangan % 2 == 0) {
            jumlah += bilangan;
        }
        bilangan++;
    }
    cout << "Jumlah bilangan genap: " << jumlah << endl;
    return 0;
}
