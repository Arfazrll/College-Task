/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.tp_mod_04_103032300013_syahrilarfianalmazril;

/**
 *
 * @author User
 */
public class Pasien {
    private String Nama;
    private int Umur;
    
    public Pasien(String Nama, int Umur) {
        this.Nama = (Nama);
        this.Umur = (Umur);
    }
    
    public void setNama(String Nama) {
        this.Nama = Nama;
    }
    
    public void setUmur(int Umur) {
        this.Umur = Umur;
    }
    
    public String getNama() {
        return Nama;
    }
    
    public int getUmur() {
        return Umur;
    }
}
