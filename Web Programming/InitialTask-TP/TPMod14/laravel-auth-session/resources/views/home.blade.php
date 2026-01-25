<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Home</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-white">

<div class="container py-5 text-center">
  @if (session('success'))
    <div class="alert alert-success d-inline-block">{{ session('success') }}</div>
  @endif

  <h4 class="mb-3">Welcome, {{ auth()->user()->name }}</h4>
  <p class="mb-4">Role: <span class="badge text-bg-secondary">{{ auth()->user()->role }}</span></p>

  <form method="POST" action="{{ route('logout') }}">
    @csrf
    <button class="btn btn-danger px-4">Logout</button>
  </form>
</div>

</body>
</html>
