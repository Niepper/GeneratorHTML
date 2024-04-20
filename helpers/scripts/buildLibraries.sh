#!/bin/bash

directory="../../code/backend/odin/source"
compileDir="../../code/backend/odin/lib"
if [ ! -d "$directory" ]; then
  echo "Directory not found: $directory"
  exit 1
fi

if [ $# -eq 0 ]; then
  for file in "$directory"/*; do
    if [ -f "$file" ]; then
      file_no_extension=$(basename "$file" .odin)
      odin build $compileDir/"$file" -file -build-mode:dll
      odin build $compileDir/"$file" -file -build-mode:shared
      mv -f "$directory"/"$file_no_extension".so "$compileDir"
      mv -f "$directory"/"$file_no_extension".dll "$compileDir"
    fi
  done
else
  file=$1
  file_no_extension=$(basename "$file" .odin)
      odin build $compileDir/"$file" -file -build-mode:dll
      odin build $compileDir/"$file" -file -build-mode:shared
      mv -f "$directory"/"$file_no_extension".so "$compileDir"
      mv -f "$directory"/"$file_no_extension".dll "$compileDir"
fi
