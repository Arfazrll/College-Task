<?php

namespace App\Http\Controllers;

use App\Models\Pegawai;
use Illuminate\Http\Request;

class PegawaiController extends Controller
{
    public function index()
    {
        $employees = Pegawai::all();

        return view('home', ['employees' => $employees]);
    }

    public function create()
    {
        return view('pegawai.create');
    }

    public function store(Request $request)
    {
        $request->validate([
            'nama'   => 'required|string|max:255',
            'posisi' => 'required|string|max:255',
            'gaji'   => 'required|integer|min:0',
        ]);

        Pegawai::create([
            'nama'   => $request->nama,
            'posisi' => $request->posisi,
            'gaji'   => $request->gaji,
        ]);

        return redirect('/')
            ->with('status', 'Data pegawai berhasil ditambahkan!');
    }
}