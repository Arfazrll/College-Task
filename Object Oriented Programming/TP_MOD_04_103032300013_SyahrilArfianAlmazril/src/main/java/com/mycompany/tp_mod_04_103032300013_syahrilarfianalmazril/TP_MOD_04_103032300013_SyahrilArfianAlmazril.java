/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.tp_mod_04_103032300013_syahrilarfianalmazril;

/**
 *
 * @author User
 */
public class TP_MOD_04_103032300013_SyahrilArfianAlmazril {

    public static void main(String[] args) {
        Dokter dt1, dt2, dt3;
        Pasien ps1, ps2, ps3;
        
        dt1 = new Dokter("Grisha", "Mata");
        dt2 = new Dokter("Faye", "Gigi");
        dt3 = new Dokter("Zeke", "Telinga");
        
        ps1 = new Pasien("Historia", 20);
        ps2 = new Pasien("Sasha", 37);
        ps3 = new Pasien("Petra", 55);
        
        Pemesanan[] psn = new Pemesanan[5];
        
        psn[0] = new Pemesanan(dt1, ps1, "Selasa");
        psn[1] = new Pemesanan(dt2, ps1, "Kamis");
        psn[2] = new Pemesanan(dt2, ps2, "Selasa");
        psn[3] = new Pemesanan(dt3, ps2, "Jumat");
        psn[4] = new Pemesanan(dt1, ps3, "Senin");
        
        int i, j = 1;
        for (i = 0; i < 5; i++) {
            System.out.println("Urutan Ke-" + j);
            System.out.println("Nama Dokter : " + psn[i].getDokter().getNama());
            System.out.println("Spesialis : " + psn[i].getDokter().getSpesialis());
            System.out.println("Nama Pasien : " + psn[i].getPasien().getNama() + " (" + psn[i].getPasien().getUmur() + ")");
            System.out.println("Hari : " + psn[i].getHari());
            System.out.println("");
            j++;
        }
    }
}
