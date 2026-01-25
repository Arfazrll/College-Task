<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>To Do List App</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">

    {{-- Bootstrap 5 --}}
    <link
        href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
        rel="stylesheet">
</head>
<body class="bg-light">

<div class="container py-5">

    <div class="d-flex justify-content-between align-items-center mb-4">
        <h5 class="mb-0">Selamat Datang, admin</h5>
        <button class="btn btn-danger btn-sm">Logout</button>
    </div>

    <h2 class="text-center mb-4">To Do List App</h2>

    @yield('content')
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
