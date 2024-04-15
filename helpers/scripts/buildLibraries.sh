#!/bin/bash

directory="../../code/cpp/source"

if [ ! -d "$directory" ]; then
  echo "Directory not found: $directory"
  exit 1
fi

if [ $# -eq 0 ]; then
  for file in "$directory"/*; do
    if [ -f "$file" ]; then
      file_no_extension=$(basename "$file" .cpp)
      g++ -shared -fPIC -o ../../code/cpp/lib/"$file_no_extension".so -g  $file
      x86_64-w64-mingw32-g++ -fPIC -shared -o ../../code/cpp/lib/"$file_no_extension".dll  "$file"
    fi
  done
else
  file=$1
  file_no_extension=$(basename "$file" .cpp)
  g++ -shared -fPIC  -o ../../code/cpp/lib/"$file_no_extension".so -g "$file"
  x86_64-w64-mingw32-g++ -shared -fPIC -o ../../code/cpp/lib/"$file_no_extension".dll "$file"
fi
