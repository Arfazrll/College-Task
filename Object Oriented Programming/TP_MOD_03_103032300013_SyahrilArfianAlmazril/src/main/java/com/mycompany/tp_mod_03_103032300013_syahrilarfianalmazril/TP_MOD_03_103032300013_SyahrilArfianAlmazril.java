/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.tp_mod_03_103032300013_syahrilarfianalmazril;

import java.util.Scanner;

/**
 *
 * @author User
 */
public class TP_MOD_03_103032300013_SyahrilArfianAlmazril {

    public static void main(String[] args) {
        Prodi pr1 = new Prodi();
        pr1.setNama("Informatika");

        Prodi pr2 = new Prodi();
        pr2.setNama("Data Science");
        
        Prodi pr3 = new Prodi();
        pr3.setNama("Teknologi Informasi");

        Mahasiswa mhs1 = new Mahasiswa();
        mhs1.setNama("Bruce Wayne");
        mhs1.setProdi(pr1);

        Mahasiswa mhs2 = new Mahasiswa();
        mhs2.setNama("Tony Stark");
        mhs2.setProdi(pr2);
        
        Mahasiswa mhs3 = new Mahasiswa();
        mhs3.setNama("Syahril Arfian Almazril");
        mhs3.setProdi(pr3);

        System.out.println("Data Mahasiswa:");
        mhs1.displayMahasiswa();
        mhs2.displayMahasiswa();
        mhs3.displayMahasiswa();
    }
}

