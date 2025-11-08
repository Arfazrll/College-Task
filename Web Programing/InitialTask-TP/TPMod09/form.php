<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulir Data Diri</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            max-width: 600px;
            margin: 50px auto;
            padding: 20px;
            background-color: #f5f5f5;
        }
        .container {
            background-color: white;
            padding: 30px;
            border-radius: 8px;
            box-shadow: 0 2px 10px rgba(0,0,0,0.1);
        }
        h2 {
            margin-top: 0;
            color: #333;
        }
        .form-group {
            margin-bottom: 20px;
        }
        label {
            display: block;
            margin-bottom: 5px;
            font-weight: bold;
            color: #333;
        }
        input[type="text"],
        input[type="date"] {
            width: 100%;
            padding: 10px;
            border: 1px solid #ddd;
            border-radius: 4px;
            box-sizing: border-box;
            font-size: 14px;
        }
        .checkbox-group {
            margin-top: 5px;
        }
        .checkbox-group label {
            display: block;
            margin-bottom: 8px;
            font-weight: normal;
        }
        .checkbox-group input[type="checkbox"] {
            margin-right: 8px;
        }
        button {
            background-color: #007bff;
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            font-size: 16px;
        }
        button:hover {
            background-color: #0056b3;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Formulir Data Diri</h2>
        
        <form action="proses.php" method="POST">
            <div class="form-group">
                <label for="nama">Nama Lengkap:</label>
                <input type="text" id="nama" name="nama" required>
            </div>

            <div class="form-group">
                <label for="tanggal">Tanggal Lahir:</label>
                <input type="date" id="tanggal" name="tanggal" required>
            </div>

            <div class="form-group">
                <label>Hobi:</label>
                <div class="checkbox-group">
                    <label>
                        <input type="checkbox" name="hobi[]" value="Membaca"> Membaca
                    </label>
                    <label>
                        <input type="checkbox" name="hobi[]" value="Olahraga"> Olahraga
                    </label>
                    <label>
                        <input type="checkbox" name="hobi[]" value="Musik"> Musik
                    </label>
                    <label>
                        <input type="checkbox" name="hobi[]" value="Lainnya"> Lainnya
                    </label>
                </div>
            </div>

            <button type="submit">Kirim</button>
        </form>
    </div>
</body>
</html>