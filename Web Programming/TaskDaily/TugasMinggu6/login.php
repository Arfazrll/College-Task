<?php
session_start();

$valid_username = "admin";
$valid_password = "admin123";

$error_message = "";
$success_message = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    $username = isset($_POST['username']) ? trim($_POST['username']) : '';
    $password = isset($_POST['password']) ? trim($_POST['password']) : '';
    
    if (empty($username) || empty($password)) {
        $error_message = "Username dan password tidak boleh kosong!";
    }

    else if ($username === $valid_username && $password === $valid_password) {
        $_SESSION['logged_in'] = true;
        $_SESSION['username'] = $username;
        $_SESSION['login_time'] = date("Y-m-d H:i:s");
        
        $success_message = "Login berhasil! Selamat datang, " . htmlspecialchars($username) . "!";
    } 
    else {
        $error_message = "Username atau password salah!";
    }
}

if (isset($_POST['logout'])) {
    session_destroy();
    header("Location: login.html");
    exit();
}
?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Hasil Login</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            padding: 20px;
        }

        .result-container {
            background: white;
            padding: 40px;
            border-radius: 10px;
            box-shadow: 0 10px 25px rgba(0, 0, 0, 0.2);
            width: 100%;
            max-width: 500px;
            text-align: center;
        }

        .error-message {
            background: #fee;
            color: #c33;
            padding: 20px;
            border-radius: 5px;
            margin-bottom: 20px;
            border-left: 4px solid #c33;
            font-size: 16px;
            text-align: left;
        }

        .success-message {
            background: #efe;
            color: #2d5;
            padding: 20px;
            border-radius: 5px;
            margin-bottom: 20px;
            border-left: 4px solid #2d5;
            font-size: 16px;
            text-align: left;
        }

        .icon {
            font-size: 60px;
            margin-bottom: 20px;
        }

        .success-icon {
            color: #2d5;
        }

        .error-icon {
            color: #c33;
        }

        h1 {
            color: #333;
            margin-bottom: 20px;
            font-size: 28px;
        }

        .info-box {
            background: #f5f5f5;
            padding: 20px;
            border-radius: 5px;
            margin: 20px 0;
            text-align: left;
        }

        .info-box p {
            margin: 10px 0;
            color: #666;
            font-size: 14px;
        }

        .info-box strong {
            color: #333;
        }

        .btn {
            display: inline-block;
            padding: 12px 30px;
            margin: 10px 5px;
            border-radius: 5px;
            text-decoration: none;
            font-weight: 600;
            transition: transform 0.2s, box-shadow 0.2s;
        }

        .btn-primary {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
        }

        .btn:hover {
            transform: translateY(-2px);
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.2);
        }

        .logout-form {
            display: inline;
        }

        .logout-btn {
            background: #c33;
            color: white;
            border: none;
            padding: 12px 30px;
            border-radius: 5px;
            font-weight: 600;
            cursor: pointer;
            transition: transform 0.2s, box-shadow 0.2s;
            font-size: 14px;
        }

        .logout-btn:hover {
            transform: translateY(-2px);
            box-shadow: 0 5px 15px rgba(195, 51, 51, 0.4);
        }
    </style>
</head>
<body>
    <div class="result-container">
        <?php if ($success_message): ?>
            <div class="icon success-icon">✓</div>
            <h1>Login Berhasil!</h1>
            <div class="success-message">
                <?php echo $success_message; ?>
            </div>
            
            <div class="info-box">
                <p><strong>Username:</strong> <?php echo htmlspecialchars($_SESSION['username']); ?></p>
                <p><strong>Waktu Login:</strong> <?php echo htmlspecialchars($_SESSION['login_time']); ?></p>
                <p><strong>Status:</strong> <span style="color: #2d5;">Aktif</span></p>
            </div>

            <p style="color: #666; margin: 20px 0;">
                Anda telah berhasil masuk ke sistem. Selamat menggunakan aplikasi!
            </p>

            <form method="POST" class="logout-form">
                <input type="hidden" name="logout" value="1">
                <button type="submit" class="logout-btn">Logout</button>
            </form>
            
        <?php elseif ($error_message): ?>
            <div class="icon error-icon">✗</div>
            <h1>Login Gagal!</h1>
            <div class="error-message">
                <?php echo $error_message; ?>
            </div>
            
            <p style="color: #666; margin: 20px 0;">
                Silakan periksa kembali username dan password Anda.
            </p>

            <div class="info-box">
                <p><strong>Petunjuk:</strong></p>
                <p>• Username: admin</p>
                <p>• Password: admin123</p>
            </div>

            <a href="login.html" class="btn btn-primary">Coba Login Lagi</a>
        <?php endif; ?>
    </div>
</body>
</html>