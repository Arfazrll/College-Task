/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.tp_mod_06_103032300013_syahrilarfianalmazril;

/**
 *
 * @author User
 */
public class YamahaMoi extends SepedaMotor {
    public YamahaMoi (String warna) {
        super(warna);
        this.ukuranTangki = 5;
    }
    
    @Override
    public boolean jalan() {
        if (super.jalan()) {
            System.out.println("Bensin Akan Habis pada " + cekKapanHabis());
            return true;
        } else {
            return false;
        }
    }
}
