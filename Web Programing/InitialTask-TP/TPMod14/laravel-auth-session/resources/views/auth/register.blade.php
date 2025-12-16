<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Register</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">

<div class="container py-5">
  <div class="row justify-content-center">
    <div class="col-md-5">
      <div class="card shadow-sm">
        <div class="card-header bg-success text-white fw-semibold">Register</div>
        <div class="card-body">

          @if ($errors->any())
            <div class="alert alert-danger">
              <ul class="mb-0">
                @foreach ($errors->all() as $error)
                  <li>{{ $error }}</li>
                @endforeach
              </ul>
            </div>
          @endif

          <form method="POST" action="{{ route('register.post') }}">
            @csrf

            <div class="mb-3">
              <label class="form-label">Name</label>
              <input name="name" class="form-control" value="{{ old('name') }}" required>
            </div>

            <div class="mb-3">
              <label class="form-label">Email</label>
              <input type="email" name="email" class="form-control" value="{{ old('email') }}" required>
            </div>

            <div class="mb-3">
              <label class="form-label">Password</label>
              <input type="password" name="password" class="form-control" required>
            </div>

            <div class="mb-3">
              <label class="form-label">Confirm Password</label>
              <input type="password" name="password_confirmation" class="form-control" required>
            </div>

            <div class="mb-3">
              <label class="form-label">Role</label>
              <select name="role" class="form-select" required>
                <option value="user" {{ old('role') === 'user' ? 'selected' : '' }}>Normal User</option>
                <option value="admin" {{ old('role') === 'admin' ? 'selected' : '' }}>Admin</option>
              </select>
            </div>

            <button class="btn btn-success w-100">Register</button>
          </form>

          <div class="text-center mt-3">
            Already have an account? <a href="{{ route('login') }}">Login</a>
          </div>

        </div>
      </div>
    </div>
  </div>
</div>

</body>
</html>
