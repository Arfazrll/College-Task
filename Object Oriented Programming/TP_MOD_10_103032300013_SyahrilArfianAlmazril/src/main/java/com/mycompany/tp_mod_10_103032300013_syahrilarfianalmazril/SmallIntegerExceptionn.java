/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.tp_mod_10_103032300013_syahrilarfianalmazril;

/**
 *
 * @author User
 */
public class SmallIntegerExceptionn extends Exception {

    private static int totalException = 0;

    public SmallIntegerExceptionn(String message) {
        super(message);
        totalException++;
    }

    public static int getTotalException() {
        return totalException;
    }

    public void print() {
        System.out.println("jumlah small int exception: " + getTotalException());
    }
}
