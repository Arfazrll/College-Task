/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.tp_mod_02_103032300013_syahrilarfianalmazril;

import java.util.Scanner;
        
/**
 *
 * @author User
 */
public class MainFibonacci {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Masukkan n: ");
        int n = input.nextInt();

        Fibonacci fib = new Fibonacci();
        fib.fiboSeries(n);
    }
}
