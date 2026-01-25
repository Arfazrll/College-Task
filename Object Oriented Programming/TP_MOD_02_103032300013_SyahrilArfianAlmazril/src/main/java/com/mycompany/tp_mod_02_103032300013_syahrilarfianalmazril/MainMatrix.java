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
public class MainMatrix {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("Masukkan matriks n: ");
        int n = in.nextInt();

        Matrix m1 = new Matrix(n), m2 = new Matrix(n);

        System.out.println("Isi matriks 1:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                m1.set(i, j, in.nextInt());

        System.out.println("Isi matriks 2:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                m2.set(i, j, in.nextInt());

        System.out.println("Matriks 1:");
        m1.print();

        System.out.println("Matriks 2:");
        m2.print();

        System.out.println("Hasil perkalian:");
        Matrix.gabungan(m1, m2).print();
    }
}