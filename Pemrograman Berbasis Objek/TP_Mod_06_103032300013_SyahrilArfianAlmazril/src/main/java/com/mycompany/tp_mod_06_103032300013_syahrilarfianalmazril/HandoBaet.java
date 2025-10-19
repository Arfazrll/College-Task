/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.tp_mod_06_103032300013_syahrilarfianalmazril;

/**
 *
 * @author User
 */
public class HandoBaet extends SepedaMotor {
    public HandoBaet(String warna) {
        super(warna);
        this.ukuranTangki = 4;
    }
    
    @Override
    public boolean jalan() {
        if (super.jalan()) {
            System.out.println("Motor Baet akan habis bensin pada " + cekKapanHabis());
            return true;
        } else {
            return false;
        }
    }
    
}
