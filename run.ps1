$src = Get-ChildItem -Recurse -Include *.cpp, *.c |
Where-Object { $_.FullName -notmatch "\\build\\" } |
ForEach-Object { $_.FullName }

if (!(Test-Path build)) {
    New-Item -ItemType Directory -Path build | Out-Null
}

g++ $src `
    -I./include `
    -I./vendor `
    -L./lib `
    -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32 -lshell32 -lmingwex -lmsvcrt `
    -static-libgcc -static-libstdc++ `
    -std=c++17 `
    -o ./build/misowa.exe


./build/misowa.exe