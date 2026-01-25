@extends('layouts.app')

@section('content')
<div class="row justify-content-center">
    <div class="col-lg-10">

        @if(session('status'))
            <div class="alert alert-success shadow-sm">
                {{ session('status') }}
            </div>
        @endif

        <div class="d-flex flex-wrap justify-content-between align-items-center mb-3 gap-2">
            <div>
                <h4 class="mb-1">Daftar Karyawan</h4>
                <p class="text-muted mb-0">Data karyawan yang tersimpan di sistem.</p>
            </div>
            <div class="d-flex align-items-center gap-2">
                <span class="badge bg-light text-dark border">
                    Total: <strong>{{ $employees->count() }}</strong> karyawan
                </span>
                <a href="{{ route('pegawai.create') }}" class="btn btn-primary">+ Tambah Karyawan</a>
            </div>
        </div>

        <div class="card shadow-sm border-0">
            <div class="card-header bg-white border-0 pb-0">
                <h6 class="mb-1">Ringkasan Data</h6>
                <small class="text-muted">Daftar berikut menampilkan nama, posisi, dan gaji setiap karyawan.</small>
            </div>
            <div class="card-body p-0 mt-2">
                <div class="table-responsive">
                    <table class="table table-striped table-hover mb-0 align-middle">
                        <thead class="table-dark">
                            <tr>
                                <th style="width: 8%">#</th>
                                <th>Nama</th>
                                <th>Posisi</th>
                                <th style="width: 25%">Gaji</th>
                            </tr>
                        </thead>
                        <tbody>
                            @forelse($employees as $index => $employee)
                                <tr>
                                    <td>{{ $index + 1 }}</td>
                                    <td class="fw-semibold">{{ $employee->nama }}</td>
                                    <td>
                                        <span class="badge bg-secondary">{{ $employee->posisi }}</span>
                                    </td>
                                    <td class="fw-semibold">Rp {{ number_format($employee->gaji, 0, ',', '.') }}</td>
                                </tr>
                            @empty
                                <tr>
                                    <td colspan="4" class="text-center py-5">
                                        <div class="text-muted mb-1">Belum ada data karyawan.</div>
                                        <a href="{{ route('pegawai.create') }}" class="btn btn-sm btn-outline-primary mt-2">Tambah karyawan pertama</a>
                                    </td>
                                </tr>
                            @endforelse
                        </tbody>
                    </table>
                </div>
            </div>
        </div>

    </div>
</div>
@endsection
