<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\PegawaiController;

Route::get('/', [PegawaiController::class, 'index'])->name('home');        
Route::get('/pegawai/create', [PegawaiController::class, 'create'])->name('pegawai.create'); 
Route::post('/pegawai', [PegawaiController::class, 'store'])->name('pegawai.store');        