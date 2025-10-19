/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.tp_mod_04_103032300013_syahrilarfianalmazril;

/**
 *
 * @author User
 */
public class Pemesanan {
    private Dokter dokter;
    private Pasien pasien;
    private String hari;
    
    public Pemesanan(Dokter dokter, Pasien pasien, String hari) {
        this.dokter = (dokter);
        this.pasien = (pasien);
        this.hari = (hari);
    }
    
    public void setDokter(Dokter dokter) {
        this.dokter = dokter;
    }
    
    public void setPasien(Pasien pasien) {
        this.pasien = pasien;
    }
    
    public void setHari(String hari) {
        this.hari = hari;
    }
    
    public Dokter getDokter() {
        return dokter;
    }
    
    public Pasien getPasien() {
        return pasien;
    }
    
    public String getHari() {
        return hari;
    }
}
