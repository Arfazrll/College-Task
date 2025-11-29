/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.tp_mod_10_103032300013_syahrilarfianalmazril;

import java.util.Scanner;

/**
 *
 * @author User
 */
public class TP_MOD_10_103032300013_SyahrilArfianAlmazril {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Small Integer Tester");

        int input = 0;

        while (input != -99) {
            System.out.println();
            System.out.print("Masukkan integer: ");

            if (scanner.hasNextInt()) {
                input = scanner.nextInt();

                if (input < 0) {
                    System.out.println("nilai lebih kecil dari 0");
                    SmallIntegerExceptionn ex = new SmallIntegerExceptionn("");
                    ex.print();

                } else if (input > 9) {
                    System.out.println("nilai lebih besar dari 9");
                    SmallIntegerExceptionn ex = new SmallIntegerExceptionn("");
                    ex.print();

                } else if (input >= 0 && input <= 9) {
                    System.out.println("nilai benar");
                }

            } else {
                System.out.println("input harus integer");
                break; 
            }
        }

        System.out.println();
        scanner.close();
    }
}

