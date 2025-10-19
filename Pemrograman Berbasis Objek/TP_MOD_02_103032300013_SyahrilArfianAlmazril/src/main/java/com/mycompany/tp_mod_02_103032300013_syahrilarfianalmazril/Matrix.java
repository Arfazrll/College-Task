/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.tp_mod_02_103032300013_syahrilarfianalmazril;

/**
 *
 * @author User
 */
public class Matrix {
    int n;
    int[][] data;

    Matrix(int ukuran) {
        n = ukuran;
        data = new int[n][n];
    }

    void set(int i, int j, int v) { data[i][j] = v; }
    int get(int i, int j) { return data[i][j]; }

    void print() {
        for (int[] row : data) {
            for (int v : row) System.out.print(v + " ");
            System.out.println();
        }
    }

    Matrix gabungan(Matrix a, Matrix b) {
        Matrix c = new Matrix(a.n);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.n; j++)
                for (int k = 0; k < a.n; k++)
                    c.data[i][j] += a.get(i, k) * b.get(k, j);
        return c;
    }
}