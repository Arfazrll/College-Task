#include "dll.h"

int main()
{
   list L1, L2, L3;
   infotype data;
   address prec;
   address pred;
   address p;

   createList(L1);
   createList(L2);
   createList(L3);

   cout << "Masukan nama dan lagu di list pertama (insert first) #1" << endl;
   cout << "Nama band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: Blinding Lights" << endl;
   data.song = "Blinding Lights";
   p = createNewElement(data);
   insertFirst(L1, p);

   cout << "Masukan nama dan lagu di list pertama (insert first) #2" << endl;
   cout << "Nama Band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: Save Your Tears" << endl;
   data.song = "Save Your Tears";
   p = createNewElement(data);
   insertFirst(L1, p);

   cout << "Masukan nama dan lagu di list pertama (insert first) #3" << endl;
   cout << "Nama Band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: In Your Eyes" << endl;
   data.song = "In Your Eyes";
   p = createNewElement(data);
   insertFirst(L1, p);

   cout << "Masukan nama dan lagu di list pertama (insert first) #4" << endl;
   cout << "Nama Band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: Take My Breath" << endl;
   data.song = "Take My Breath";
   p = createNewElement(data);
   insertFirst(L1, p);

   cout << "Masukan nama dan lagu di list pertama (insert first) #5" << endl;
   cout << "Nama Band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: Out of Time" << endl;
   data.song = "Out of Time";
   p = createNewElement(data);
   insertFirst(L1, p);

   cout << "Masukan nama dan lagu di list pertama (Insert After) #6" << endl;
   cout << "Nama Band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: Die For You" << endl;
   data.song = "Die For You";
   p = createNewElement(data);
   cout << "--Pencarian Lagu dengan judul Save Your Tears untuk memasukkan list lagu tersebut ke depannya--" << endl;
   string judul = "Save Your Tears";
   prec = findSong(L1, judul);
   insertAfter(prec, p);

   cout << "Masukan Nama dan lagu di list pertama (Insert Before) #7" << endl;
   cout << "Nama Band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: Starboy" << endl;
   data.song = "Starboy";
   p = createNewElement(data);
   cout << "--Pencarian lagu dengan judul Save Your Tears untuk memasukkan lagu ke belakangnya--" << endl;
   judul = "Save Your Tears";
   pred = findSong(L1, judul);
   insertBefore(pred, p);

   cout << "LIST KE-1" << endl;
   showList(L1);

   cout << "Masukan nama dan lagu di list kedua (Insert First) #1" << endl;
   cout << "Nama Band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: Call Out My Name" << endl;
   data.song = "Call Out My Name";
   p = createNewElement(data);
   insertFirst(L2, p);

   cout << "Masukan nama dan lagu di list kedua (Insert First) #2" << endl;
   cout << "Nama Band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: I Feel It Coming" << endl;
   data.song = "I Feel It Coming";
   p = createNewElement(data);
   insertFirst(L2, p);

   cout << "Masukan nama dan lagu di list kedua (Insert First) #3" << endl;
   cout << "Nama Band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: Can't Feel My Face" << endl;
   data.song = "Can't Feel My Face";
   p = createNewElement(data);
   insertFirst(L2, p);

   cout << "Masukan nama dan lagu di list kedua (Insert First) #4" << endl;
   cout << "Nama Band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: The Hills" << endl;
   data.song = "The Hills";
   p = createNewElement(data);
   insertLast(L2, p);

   cout << "Masukan nama dan lagu di list kedua (Insert First) #5" << endl;
   cout << "Nama Band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama Lagu: Heartless" << endl;
   data.song = "Heartless";
   p = createNewElement(data);
   insertLast(L2, p);
   showList(L2);

   cout << "Masukkan nama dan lagu di list kedua (insert After) #6" << endl;
   cout << "Nama band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama lagu: Die For You" << endl;
   data.song = "Die For You";
   p = createNewElement(data);
   cout << "Pencarian Lagu dengan Judul Can't Feel My Face" << endl;
   judul = "Can't Feel My Face";
   prec = findSong(L2, judul);
   insertAfter(prec, p);

   cout << "Masukkan nama dan lagu di list kedua (insert before) #7" << endl;
   cout << "Nama band: The Weeknd" << endl;
   data.name = "The Weeknd";
   cout << "Nama lagu: Blinding Lights" << endl;
   data.song = "Blinding Lights";
   p = createNewElement(data);
   cout << "Pencarian Lagu dengan Judul I Feel It Coming" << endl;
   judul = "I Feel It Coming";
   pred = findSong(L2, judul);
   insertBefore(pred, p);

   showList(L1);
   showList(L2);
   cout << "--sekarang melakukan proses penggabungan dari list 1, list 2 menjadi list 3--" << endl;
   cout << "setelah combine list 1 dan list 2 menjadi list 3: " << endl;
   concat(L1, L2, L3);
   showList(L3);

   cout << "--sekarang untuk menghapus lagu dengan judul: Blinding Lights by The Weeknd--" << endl;
   judul = "Blinding Lights";
   removeSong(L3, judul);
   cout << "--setelah penghapusan band dan lagu--" << endl;
   showList(L3);
   return 0;
}
