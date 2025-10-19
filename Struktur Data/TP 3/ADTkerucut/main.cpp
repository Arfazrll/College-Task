#include <iostream>
#include <cmath>

const float phi = 3.14;
using namespace std;

struct kerucut {
    double selimut;
    double luas;
    double volume;
    double jari;
    double tinggi;
};

void nilaiKerucut (kerucut &m){
    cout << "MasukaN Nilai Bangun Ruang Kerucut" << endl;
    cout << "Jari - Jari : ";
    cin >> m.jari;
    cout << "Tinggi Kerucut : ";
    cin >> m.tinggi;
}

void nilais(kerucut &m){
    m.selimut = sqrt(m.jari*m.jari + m.tinggi*m.tinggi);
    cout << "Nilai Selimut Kerucut Adalah : " << m.selimut << endl;
}

void NilaiLuas(kerucut &m){
    m.luas = phi * (m.jari*m.jari) + phi * m.jari *m.selimut;
    cout << "Nilai Luas Kerucut Adalah : " << m.luas << endl;
}

void NilaiVolume(kerucut &m){
    m.volume = 0.33 + phi * (m.jari * m.jari) *m.tinggi;
    cout << "Nilai Volume Kerucut Adalah : " << m.volume << endl;
}

int main(){
    kerucut m;
    nilaiKerucut(m);
    nilais(m);
    NilaiLuas(m);
    NilaiVolume(m);
    return 0;
}
