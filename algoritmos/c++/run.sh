#!/usr/bin/env bash
f=${1:-A}
[[ ! -d "$f" ]] && { echo "'$f' no existe"; exit 1; }
[[ ! -f "$f/$f.cpp" ]] && { echo "$f.cpp no existe"; exit 1; }

g++ -std=c++17 -O2 "$f/$f.cpp" -o "$f/$f" || exit 1

cd "$f"
for i in in*; do
    [[ ! -e "$i" ]] && { "./$f"; break; }
    echo "$i"
    "./$f" < "$i" | tee "out${i#in}"
done