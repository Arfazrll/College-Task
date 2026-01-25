/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.tp_mod_06_103032300013_syahrilarfianalmazril;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

/**
 *
 * @author User
 */
public class TP_Mod_06_103032300013_SyahrilArfianAlmazril {

    public static void main(String[] args) {
        SepedaMotor motor = new SepedaMotor("Hitam");
        HandoBaet honda = new HandoBaet("Biru");
        YamahaMoi yamaha = new YamahaMoi("Merah");
        
        DateTimeFormatter format = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        LocalDateTime waktuSekarang = LocalDateTime.now();
        
        System.out.println("Status Awal Sepeda Motor: ");
        motor.jalan();
        System.out.println("        false");
        
        System.out.println("Status Awal HandoBaet: ");
        honda.jalan();
        System.out.println("        false");
        
        System.out.println("Status Awal YamahaMoi: ");
        yamaha.jalan();
        System.out.println("        false");
        
        System.out.println("\n-----------------------------------------------------------------");
        
        motor.isiTangkiFull();
        honda.isiTangkiFull();
        yamaha.isiTangkiFull();
        
        System.out.println("Status Terbaru Sepeda Motor: ");
        System.out.println("Waktu saat ini: " + waktuSekarang.format(format));
        motor.jalan();
        System.out.println(motor.cekKapanHabis());
        
        System.out.println("Status Terbaru Hando Baet: ");
        System.out.println("Waktu saat ini: " + waktuSekarang.format(format));
        honda.jalan();
        
        System.out.println("Status Terbaru YamahaMoi: ");
        System.out.println("Waktu saat ini: " + waktuSekarang.format(format));
        yamaha.jalan();
    }
}
