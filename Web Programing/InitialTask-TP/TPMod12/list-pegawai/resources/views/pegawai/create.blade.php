@extends('layouts.app')

@section('content')
<div class="row justify-content-center">
    <div class="col-lg-8 col-xl-6">

        <div class="d-flex justify-content-between align-items-center mb-3">
            <div>
                <h4 class="mb-1">Tambah Karyawan Baru</h4>
                <p class="text-muted mb-0">Isi data karyawan dengan benar untuk menambahkannya ke daftar.</p>
            </div>
            <a href="{{ route('home') }}" class="btn btn-outline-secondary btn-sm">
                &larr; Kembali
            </a>
        </div>

        <div class="card shadow-sm border-0">
            <div class="card-body">

                @if ($errors->any())
                    <div class="alert alert-danger">
                        <strong>Terjadi kesalahan.</strong>
                        <p class="mb-1">Silakan periksa kembali isian berikut:</p>
                        <ul class="mb-0">
                            @foreach ($errors->all() as $error)
                                <li>{{ $error }}</li>
                            @endforeach
                        </ul>
                    </div>
                @endif

                <form action="{{ route('pegawai.store') }}" method="POST" novalidate>
                    @csrf

                    <div class="mb-3">
                        <label class="form-label">Nama Karyawan <span class="text-danger">*</span></label>
                        <input
                            type="text"
                            name="nama"
                            class="form-control @error('nama') is-invalid @enderror"
                            value="{{ old('nama') }}"
                            placeholder="Contoh: Syahril Arfian Almazril"
                        >
                        @error('nama')
                            <div class="invalid-feedback">{{ $message }}</div>
                        @else
                        @enderror
                    </div>

                    <div class="mb-3">
                        <label class="form-label">Posisi Jabatan <span class="text-danger">*</span></label>
                        <select
                            name="posisi"
                            class="form-select @error('posisi') is-invalid @enderror"
                        >
                            <option value="" {{ old('posisi') ? '' : 'selected' }} disabled>Pilih posisi</option>
                            <option value="Manager" {{ old('posisi') == 'Manager' ? 'selected' : '' }}>Manager</option>
                            <option value="Supervisor" {{ old('posisi') == 'Supervisor' ? 'selected' : '' }}>Supervisor</option>
                            <option value="Staff" {{ old('posisi') == 'Staff' ? 'selected' : '' }}>Staff</option>
                        </select>
                        @error('posisi')
                            <div class="invalid-feedback">{{ $message }}</div>
                        @else
                        @enderror
                    </div>

                    <div class="mb-4">
                        <label class="form-label">Gaji (Rp) <span class="text-danger">*</span></label>
                        <input
                            type="number"
                            name="gaji"
                            class="form-control @error('gaji') is-invalid @enderror"
                            value="{{ old('gaji') }}"
                            placeholder="Contoh: 5000000"
                            min="0"
                        >
                        @error('gaji')
                            <div class="invalid-feedback">{{ $message }}</div>
                        @else
                        @enderror
                    </div>

                    <div class="d-flex justify-content-end gap-2">
                        <a href="{{ route('home') }}" class="btn btn-outline-secondary">Batal</a>
                        <button type="submit" class="btn btn-primary">Simpan Data</button>
                    </div>

                </form>
            </div>
        </div>

    </div>
</div>
@endsection
