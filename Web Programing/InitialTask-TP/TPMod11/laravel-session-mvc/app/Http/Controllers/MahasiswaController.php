<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class MahasiswaController extends Controller
{
    public function form()
    {
        return view('mahasiswa.form');
    }

    public function store(Request $request)
    {
        $request->validate([
            'nama' => 'required|string|max:100',
            'nim'  => 'required|string|max:20',
        ]);

        session([
            'nama' => $request->nama,
            'nim'  => $request->nim,
        ]);

        return redirect()->route('mahasiswa.tampil');
    }

    public function tampil(Request $request)
    {
        $nama = session('nama');
        $nim  = session('nim');

        if (!$nama || !$nim) {
            return redirect()->route('mahasiswa.form')
                             ->with('error', 'Silakan isi form terlebih dahulu.');
        }

        return view('mahasiswa.tampil', compact('nama', 'nim'));
    }
}
