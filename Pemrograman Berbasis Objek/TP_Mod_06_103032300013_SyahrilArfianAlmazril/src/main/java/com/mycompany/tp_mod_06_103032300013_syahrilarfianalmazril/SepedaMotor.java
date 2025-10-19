/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.tp_mod_06_103032300013_syahrilarfianalmazril;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

/**
 *
 * @author User
 */
public class SepedaMotor {
    private String warnaMotor;
    protected int ukuranTangki;
    private LocalDateTime waktuIsiBensin;
    
    SepedaMotor (String warna) {
        this.warnaMotor = warna;
        this.ukuranTangki = 3;
        this.waktuIsiBensin = null;
    }
    
    public void isiTangkiFull() {
        this.waktuIsiBensin = LocalDateTime.now();
    }
    
    public String cekKapanHabis() {
        if (waktuIsiBensin == null) {
            return "Tangki Kosong, Isi duluu";
        }
        LocalDateTime waktuHabis = this.waktuIsiBensin.plusHours(ukuranTangki);
        DateTimeFormatter formatWaktu = DateTimeFormatter.ofPattern("yyy-MM-dd HH:mm");
        return waktuHabis.format(formatWaktu);
    }
    
    public boolean jalan() {
        if (waktuIsiBensin == null) {
            System.out.println("Bensin Habis, Sepeda Motor " + warnaMotor + "Tidak Dapat Berjalan");
            return false;
        } else {
            System.out.println("Sepeda Motor Warna " + warnaMotor + "Sedang Berjalan");
            return true;
        }
    }
}
