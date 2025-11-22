<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <title>Data Mahasiswa - Session</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <style>
        :root {
            --bg-main: #020617;
            --bg-card: #020617;
            --accent: #22c55e;
            --accent-soft: #16a34a;
            --text-main: #e5e7eb;
            --text-muted: #9ca3af;
        }

        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
            font-family: system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
        }

        body {
            min-height: 100vh;
            background:
                radial-gradient(circle at 0 0, #0f172a 0, transparent 50%),
                radial-gradient(circle at 100% 100%, #022c22 0, #020617 55%);
            color: var(--text-main);
            display: flex;
            align-items: center;
            justify-content: center;
            padding: 24px;
        }

        .container {
            width: 100%;
            max-width: 460px;
        }

        .card {
            position: relative;
            background: rgba(15, 23, 42, 0.96);
            border-radius: 20px;
            padding: 24px 24px 20px;
            box-shadow:
                0 28px 80px rgba(15, 23, 42, 0.95),
                0 0 0 1px rgba(34, 197, 94, 0.25);
            overflow: hidden;
        }

        .card::before {
            content: "";
            position: absolute;
            inset: -35%;
            background:
                radial-gradient(circle at 0 0, rgba(34, 197, 94, 0.2) 0, transparent 50%),
                radial-gradient(circle at 120% 120%, rgba(45, 212, 191, 0.14) 0, transparent 50%);
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
            padding: 4px 11px;
            border-radius: 999px;
            font-size: 11px;
            letter-spacing: 0.08em;
            text-transform: uppercase;
            background: rgba(15, 23, 42, 0.98);
            color: var(--text-muted);
            border: 1px solid rgba(148, 163, 184, 0.5);
            margin-bottom: 14px;
        }

        .badge-dot {
            width: 8px;
            height: 8px;
            border-radius: 999px;
            background: var(--accent);
            box-shadow: 0 0 0 4px rgba(34, 197, 94, 0.35);
        }

        .title {
            font-size: 22px;
            font-weight: 600;
            margin-bottom: 6px;
        }

        .subtitle {
            font-size: 13px;
            color: var(--text-muted);
            margin-bottom: 18px;
        }

        .info-card {
            background: radial-gradient(circle at top left,
            rgba(34, 197, 94, 0.12) 0, rgba(15, 23, 42, 0.96) 55%);
            border-radius: 16px;
            padding: 16px 14px;
            border: 1px solid rgba(148, 163, 184, 0.45);
            margin-bottom: 16px;
        }

        .label {
            font-size: 11px;
            text-transform: uppercase;
            letter-spacing: 0.14em;
            color: var(--text-muted);
            margin-bottom: 4px;
        }

        .value {
            font-size: 16px;
            font-weight: 600;
            margin-bottom: 6px;
        }

        .value-secondary {
            font-size: 13px;
            color: var(--text-muted);
        }

        .pill-row {
            display: flex;
            gap: 8px;
            flex-wrap: wrap;
            margin-top: 8px;
        }

        .pill {
            font-size: 11px;
            padding: 4px 9px;
            border-radius: 999px;
            border: 1px solid rgba(34, 197, 94, 0.6);
            background: rgba(22, 163, 74, 0.18);
            color: #bbf7d0;
        }

        .btn-row {
            display: flex;
            align-items: center;
            justify-content: space-between;
            gap: 10px;
            margin-top: 10px;
        }

        .btn-primary {
            border: none;
            border-radius: 999px;
            padding: 9px 14px;
            background: linear-gradient(135deg, var(--accent), var(--accent-soft));
            color: white;
            font-size: 13px;
            font-weight: 500;
            cursor: pointer;
            display: inline-flex;
            align-items: center;
            gap: 6px;
            transition: transform 0.1s ease, box-shadow 0.1s ease, filter 0.1s ease;
            box-shadow:
                0 14px 30px rgba(22, 163, 74, 0.5),
                0 0 0 1px rgba(187, 247, 208, 0.4);
            text-decoration: none;
        }

        .btn-primary:hover {
            transform: translateY(-1px);
            filter: brightness(1.04);
            box-shadow:
                0 18px 40px rgba(22, 163, 74, 0.6),
                0 0 0 1px rgba(187, 247, 208, 0.5);
        }

        .btn-primary:active {
            transform: translateY(0);
            box-shadow:
                0 10px 24px rgba(22, 163, 74, 0.45),
                0 0 0 1px rgba(187, 247, 208, 0.4);
        }

        .btn-secondary {
            border-radius: 999px;
            padding: 8px 12px;
            border: 1px solid rgba(148, 163, 184, 0.6);
            background: rgba(15, 23, 42, 0.9);
            font-size: 12px;
            color: var(--text-muted);
            display: inline-flex;
            align-items: center;
            gap: 6px;
            text-decoration: none;
            cursor: pointer;
            transition: border-color 0.15s ease, color 0.15s ease, background 0.15s ease;
        }

        .btn-secondary:hover {
            border-color: rgba(148, 163, 184, 0.9);
            color: #e5e7eb;
            background: rgba(15, 23, 42, 1);
        }

        .btn-icon {
            font-size: 14px;
        }

        .footer-note {
            margin-top: 10px;
            font-size: 11px;
            color: var(--text-muted);
        }

        @media (max-width: 480px) {
            .card {
                padding: 18px 16px 16px;
                border-radius: 16px;
            }

            .title {
                font-size: 19px;
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

            <h1 class="title">Ringkasan Mahasiswa</h1>
            <p class="subtitle">
                tampilan data yang udah disimpan di session sebelumnya
            </p>

            <div class="info-card">
                <div class="label">Nama</div>
                <div class="value">{{ $nama }}</div>
                <div class="value-secondary">
                </div>

                <div style="height: 12px;"></div>

                <div class="label">NIM</div>
                <div class="value">{{ $nim }}</div>

            </div>

            <div class="btn-row">
                <a href="{{ route('mahasiswa.form') }}" class="btn-primary">
                    <span class="btn-icon"></span>
                    <span>Ubah / Input Ulang</span>
                </a>

                <a href="{{ route('mahasiswa.form') }}" class="btn-secondary">
                    <span class="btn-icon">←</span>
                    <span>Kembali ke Form</span>
                </a>
            </div>
        </div>
    </div>
</div>
</body>
</html>
