<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <title>SyahrilArfianAlmazril-103032300013</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <link
        href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
        rel="stylesheet"
    >

    <style>
        :root {
            --bg-body: #f3f4f6;
            --nav-bg: #111827;
            --nav-shadow: 0 2px 8px rgba(15, 23, 42, 0.4);
        }

        * {
            box-sizing: border-box;
        }

        body {
            min-height: 100vh;
            background-color: var(--bg-body);
            margin: 0;
            font-family: system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
        }

        .navbar-custom {
            background: var(--nav-bg);
            box-shadow: var(--nav-shadow);
        }

        .navbar-custom .navbar-brand {
            color: #e5e7eb;
            font-weight: 600;
            letter-spacing: 0.06em;
            text-transform: uppercase;
            font-size: 0.95rem;
        }

        .navbar-custom .navbar-brand span {
            display: block;
            font-size: 0.75rem;
            font-weight: 400;
            letter-spacing: 0.12em;
            color: #9ca3af;
        }

        .main-wrapper {
            padding-top: 2rem;
            padding-bottom: 2rem;
        }

        @media (min-width: 992px) {
            .main-wrapper {
                padding-top: 2.5rem;
                padding-bottom: 2.5rem;
            }
        }
    </style>
</head>
<body>

<nav class="navbar navbar-expand-lg navbar-custom">
    <div class="container">
        <a class="navbar-brand" href="{{ route('home') }}">
            Syahril Arfian Almazril - 103032300013
            <span>TpMod12 WebPro</span>
        </a>
    </div>
</nav>

<div class="container main-wrapper">
    @yield('content')
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
