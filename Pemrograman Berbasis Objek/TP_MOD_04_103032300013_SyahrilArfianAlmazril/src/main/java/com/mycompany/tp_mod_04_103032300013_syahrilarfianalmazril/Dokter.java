/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.tp_mod_04_103032300013_syahrilarfianalmazril;

/**
 *
 * @author User
 */
public class Dokter {
    private String Nama;
    private String Spesialis;
    
    public Dokter(String Nama, String Spesialis) {
        this.setNama(Nama);
        this.setSpesialis(Spesialis);
    }
    
    public void setNama(String Nama) {
        this.Nama = Nama;
    }
    
    public void setSpesialis(String Spesialis) {
        this.Spesialis = Spesialis;
    }
    
    public String getNama() {
        return Nama;
    }
    
    public String getSpesialis() {
        return Spesialis;
    }
}



