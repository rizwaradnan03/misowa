# Mengambil semua file .cpp DAN .c secara rekursif
$src = Get-ChildItem -Recurse -Include *.cpp, *.c | ForEach-Object { $_.FullName }

if (!(Test-Path build)) {
    New-Item -ItemType Directory -Path build | Out-Null
}

Write-Host "Sedang mengompilasi (Termasuk GLAD)..." -ForegroundColor Cyan

# Sekarang $src berisi main.cpp dan glad.c
g++ $src `
    -I./include `
    -L./lib `
    -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32 -lshell32 -lmingwex -lmsvcrt `
    -static-libgcc -static-libstdc++ `
    -std=c++17 `
    -o ./build/misowa.exe

if ($LASTEXITCODE -eq 0) {
    Write-Host "Kompilasi Berhasil!" -ForegroundColor Green
    ./build/misowa.exe
} else {
    Write-Host "Kompilasi Gagal. Periksa apakah glad.c ada di folder src." -ForegroundColor Red
}