void main() {
  print('Nama: Syahril Arfian Almazril');
  print('Nim : 103032300013');
  print('Kelas: IT-47-04');
  print('APB: Tugas 2 Dart\n');

  print('Tugas 1: Array 2 Dimensi \n');
  array2Dimensi();

  print('\nTugas 2: FPB \n');
  hitungFPB(12, 8);
}

void array2Dimensi() {
  List<List<int>> array = [];

  List<int> baris1 = [];
  for (int i = 1; i <= 3; i++) {
    baris1.add(3 * i);
  }
  array.add(baris1);

  List<int> baris2 = [];
  int ganjil = 1;
  for (int i = 0; i < 4; i++) {
    baris2.add(ganjil);
    ganjil += 2;
  }
  array.add(baris2);

  List<int> baris3 = [];
  int faktorial = 1;
  for (int i = 1; i <= 5; i++) {
    faktorial *= i;
    baris3.add(faktorial);
  }
  array.add(baris3);

  List<int> baris4 = [];
  for (int i = 1; i <= 6; i++) {
    baris4.add(i);
  }
  array.add(baris4);

  for (int i = 0; i < array.length; i++) {
    print(array[i].join(' '));
  }
}

int fpb(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

void hitungFPB(int bil1, int bil2) {
  print('Bilangan 1: $bil1');
  print('Bilangan 2: $bil2');
  print('FPB $bil1 dan $bil2 = ${fpb(bil1, bil2)}');
}