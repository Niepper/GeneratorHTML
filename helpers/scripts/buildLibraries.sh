#!/bin/bash

directory="../../code/backend/cpp/source"
compileDir="../../code/backend/cpp/lib"
if [ ! -d "$directory" ]; then
  echo "Directory not found: $directory"
  exit 1
fi

if [ $# -eq 0 ]; then
  for file in "$directory"/*; do
    if [ -f "$file" ]; then
      file_no_extension=$(basename "$file" .cpp)
      g++ -shared -fPIC -o $compileDir/"$file_no_extension".so -g  "$file"
      x86_64-w64-mingw32-g++ -shared -o $compileDir/"$file_no_extension".dll "$file"
    fi
  done
else
  file=$1
  file_no_extension=$(basename "$file" .cpp)
  g++ -shared -fPIC  -o $compileDir/"$file_no_extension".so -g "$file"
  x86_64-w64-mingw32-g++ -shared -o $compileDir/"$file_no_extension".dll  "$file"
fi
