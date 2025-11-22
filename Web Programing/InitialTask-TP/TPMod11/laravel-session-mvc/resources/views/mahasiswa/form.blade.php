<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <title>Form Mahasiswa - Session</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <style>
        :root {
            --bg-main: #0f172a;
            --bg-card: #1e293b;
            --accent: #3b82f6;
            --accent-soft: #1d4ed8;
            --text-main: #e5e7eb;
            --text-muted: #9ca3af;
            --danger: #f97373;
        }

        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
            font-family: system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
        }

        body {
            min-height: 100vh;
            background: radial-gradient(circle at top, #1e293b 0, #020617 60%);
            color: var(--text-main);
            display: flex;
            align-items: center;
            justify-content: center;
            padding: 24px;
        }

        .container {
            width: 100%;
            max-width: 420px;
        }

        .card {
            background: rgba(15, 23, 42, 0.95);
            border-radius: 18px;
            padding: 24px 24px 20px;
            box-shadow:
                0 24px 60px rgba(15, 23, 42, 0.9),
                0 0 0 1px rgba(148, 163, 184, 0.15);
            backdrop-filter: blur(14px);
            position: relative;
            overflow: hidden;
        }

        .card::before {
            content: "";
            position: absolute;
            inset: -40%;
            background:
                radial-gradient(circle at 0 0, rgba(96, 165, 250, 0.12) 0, transparent 50%),
                radial-gradient(circle at 100% 100%, rgba(45, 212, 191, 0.06) 0, transparent 45%);
            opacity: 0.9;
            pointer-events: none;
        }

        .card-inner {
            position: relative;
            z-index: 1;
        }

        .badge {
            display: inline-flex;
            align-items: center;
            gap: 6px;
            padding: 4px 10px;
            border-radius: 999px;
            font-size: 11px;
            letter-spacing: 0.06em;
            text-transform: uppercase;
            background: rgba(15, 23, 42, 0.9);
            color: var(--text-muted);
            border: 1px solid rgba(148, 163, 184, 0.4);
            margin-bottom: 14px;
        }

        .badge-dot {
            width: 8px;
            height: 8px;
            border-radius: 999px;
            background: var(--accent);
            box-shadow: 0 0 0 4px rgba(59, 130, 246, 0.3);
        }

        .title {
            font-size: 22px;
            font-weight: 600;
            letter-spacing: 0.02em;
            margin-bottom: 4px;
        }

        .subtitle {
            font-size: 13px;
            color: var(--text-muted);
            margin-bottom: 20px;
        }

        .form-group {
            margin-bottom: 14px;
        }

        label {
            display: block;
            font-size: 13px;
            margin-bottom: 6px;
            color: var(--text-muted);
        }

        .input {
            width: 100%;
            padding: 10px 11px;
            border-radius: 10px;
            border: 1px solid rgba(148, 163, 184, 0.4);
            background: rgba(15, 23, 42, 0.9);
            color: var(--text-main);
            font-size: 14px;
            outline: none;
            transition: border-color 0.18s ease, box-shadow 0.18s ease, background 0.18s ease;
        }

        .input::placeholder {
            color: #6b7280;
            font-size: 13px;
        }

        .input:focus {
            border-color: var(--accent);
            box-shadow: 0 0 0 1px rgba(59, 130, 246, 0.6);
            background: rgba(15, 23, 42, 1);
        }

        .btn {
            width: 100%;
            border: none;
            border-radius: 999px;
            padding: 10px 14px;
            margin-top: 6px;
            background: linear-gradient(135deg, var(--accent), var(--accent-soft));
            color: white;
            font-size: 14px;
            font-weight: 500;
            cursor: pointer;
            display: inline-flex;
            align-items: center;
            justify-content: center;
            gap: 6px;
            transition: transform 0.1s ease, box-shadow 0.1s ease, filter 0.1s ease;
            box-shadow:
                0 14px 30px rgba(37, 99, 235, 0.45),
                0 0 0 1px rgba(191, 219, 254, 0.25);
        }

        .btn:hover {
            transform: translateY(-1px);
            filter: brightness(1.04);
            box-shadow:
                0 18px 40px rgba(37, 99, 235, 0.55),
                0 0 0 1px rgba(191, 219, 254, 0.4);
        }

        .btn:active {
            transform: translateY(0);
            box-shadow:
                0 10px 24px rgba(37, 99, 235, 0.4),
                0 0 0 1px rgba(191, 219, 254, 0.3);
        }

        .btn span.icon {
            font-size: 15px;
            line-height: 1;
        }

        .helper-text {
            font-size: 11px;
            color: var(--text-muted);
            margin-top: 10px;
        }

        .link {
            color: var(--accent);
            text-decoration: none;
            font-weight: 500;
        }

        .link:hover {
            text-decoration: underline;
        }

        .error-box {
            background: rgba(248, 113, 113, 0.08);
            border: 1px solid rgba(248, 113, 113, 0.7);
            color: #fecaca;
            border-radius: 12px;
            padding: 8px 10px;
            font-size: 11px;
            margin-bottom: 10px;
        }

        .error-box ul {
            margin-left: 16px;
            margin-top: 4px;
        }

        .flash-error {
            background: rgba(248, 113, 113, 0.1);
            border: 1px solid rgba(248, 113, 113, 0.7);
            color: #fecaca;
            border-radius: 999px;
            padding: 6px 10px;
            font-size: 11px;
            margin-bottom: 10px;
            display: inline-flex;
            align-items: center;
            gap: 6px;
        }

        .flash-dot {
            width: 6px;
            height: 6px;
            border-radius: 999px;
            background: #f97373;
        }

        @media (max-width: 480px) {
            .card {
                padding: 18px 16px 16px;
                border-radius: 16px;
            }

            .title {
                font-size: 18px;
            }

            .subtitle {
                font-size: 12px;
            }
        }
    </style>
</head>
<body>
<div class="container">
    <div class="card">
        <div class="card-inner">
            <div class="badge">
                <span class="badge-dot"></span>
                Modul 11 - Laravel
            </div>

            <h1 class="title">Form Data Mahasiswa</h1>
            <p class="subtitle">
                Masukkan nama dan NIM
            </p>

            @if(session('error'))
                <div class="flash-error">
                    <span class="flash-dot"></span>
                    <span>{{ session('error') }}</span>
                </div>
            @endif

            @if ($errors->any())
                <div class="error-box">
                    <strong>Periksa kembali isian berikut:</strong>
                    <ul>
                        @foreach ($errors->all() as $error)
                            <li>{{ $error }}</li>
                        @endforeach
                    </ul>
                </div>
            @endif

            <form action="{{ route('mahasiswa.store') }}" method="POST">
                @csrf

                <div class="form-group">
                    <label for="nama">Nama Mahasiswa</label>
                    <input
                        id="nama"
                        type="text"
                        name="nama"
                        class="input"
                        placeholder="Contoh: Syahril Arfian Almazril"
                        value="{{ old('nama') }}"
                        required
                    >
                </div>

                <div class="form-group">
                    <label for="nim">NIM</label>
                    <input
                        id="nim"
                        type="text"
                        name="nim"
                        class="input"
                        placeholder="Contoh: 1101220xxx"
                        value="{{ old('nim') }}"
                        required
                    >
                </div>

                <button type="submit" class="btn">
                    <span class="icon">⮞</span>
                    <span>Simpan ke Session</span>
                </button>
            </form>

            <p class="helper-text">
                lihat tampil.blade.php disini
                <a href="{{ route('mahasiswa.tampil') }}" class="link">tampilan data</a>
            </p>
        </div>
    </div>
</div>
</body>
</html>
