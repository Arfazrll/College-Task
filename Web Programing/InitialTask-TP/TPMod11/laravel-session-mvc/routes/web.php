<?php

use App\Http\Controllers\MahasiswaController;

Route::get('/mahasiswa/form', [MahasiswaController::class, 'form'])->name('mahasiswa.form');
Route::post('/mahasiswa/simpan', [MahasiswaController::class, 'store'])->name('mahasiswa.store');
Route::get('/mahasiswa/tampil', [MahasiswaController::class, 'tampil'])->name('mahasiswa.tampil');

