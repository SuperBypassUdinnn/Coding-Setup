# Pastikan script dijalankan sebagai Administrator

# 1. Install Chocolatey jika belum ada
if (!(Get-Command choco -ErrorAction SilentlyContinue)) {
    Write-Output "Chocolatey belum terpasang. Menginstal Chocolatey..."
    Set-ExecutionPolicy Bypass -Scope Process -Force
    [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
    Invoke-Expression ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
} else {
    Write-Output "Chocolatey sudah terpasang."
}

# 2. Daftar software yang akan diinstall
$packages = @(
    "git",
    "vscode",
    "nodejs-lts",
    "python",
    "googlechrome",
    "winrar",
    "make",
    "curl",
    "wget",
    "notepadplusplus",
    "dotnet-sdk",
    "jdk11"
    "mingw"
)

# 3. Install semuanya
foreach ($pkg in $packages) {
    choco install $pkg -y
}

# 4. Upgrade semua (jika ada yang sudah terinstall)
choco upgrade all -y

Write-Output "✅ Setup selesai! Semua software sudah terinstal dan diperbarui."
