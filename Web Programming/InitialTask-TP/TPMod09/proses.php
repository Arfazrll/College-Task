<?php
$nama = $_POST['nama'];
$tanggal = $_POST['tanggal'];
$hobi = isset($_POST['hobi']) ? $_POST['hobi'] : [];

function konversiTanggal($tanggal) {
    $bulan = array(
        1 => 'Januari',
        2 => 'Februari',
        3 => 'Maret',
        4 => 'April',
        5 => 'Mei',
        6 => 'Juni',
        7 => 'Juli',
        8 => 'Agustus',
        9 => 'September',
        10 => 'Oktober',
        11 => 'November',
        12 => 'Desember'
    );
    
    $pecah = explode('-', $tanggal);
    $tahun = $pecah[0];
    $bulanAngka = (int)$pecah[1];
    $hari = (int)$pecah[2];
    
    return $hari . ' ' . $bulan[$bulanAngka] . ' ' . $tahun;
}

$tanggalLahir = konversiTanggal($tanggal);
$hobiString = implode(', ', $hobi);
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tampilan Data Anda</title>
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
            margin-bottom: 30px;
            color: #333;
            font-size: 24px;
        }
        table {
            border-collapse: collapse;
            width: 100%;
            margin-bottom: 20px;
        }
        td {
            padding: 8px 0;
            vertical-align: top;
            color: #333;
            font-size: 16px;
        }
        td:first-child {
            width: 150px;
            font-weight: normal;
        }
        td:nth-child(2) {
            width: 20px;
            text-align: left;
        }
        td:last-child {
            font-weight: normal;
        }
        .back-link {
            color: #007bff;
            text-decoration: none;
            font-size: 14px;
            display: inline-block;
            margin-top: 20px;
        }
        .back-link:hover {
            text-decoration: underline;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Tampilan Data Anda</h2>
        
        <table>
            <tr>
                <td>Nama<br>Lengkap</td>
                <td>:</td>
                <td><?php echo htmlspecialchars($nama); ?></td>
            </tr>
            <tr>
                <td>Tanggal Lahir</td>
                <td>:</td>
                <td><?php echo $tanggalLahir; ?></td>
            </tr>
            <tr>
                <td>Hobi</td>
                <td>:</td>
                <td><?php echo htmlspecialchars($hobiString); ?></td>
            </tr>
        </table>

        <a href="form.php" class="back-link">« Kembali ke Form</a>
    </div>
</body>
</html>