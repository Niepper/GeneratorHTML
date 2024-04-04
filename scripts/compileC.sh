#!/bin/bash

# Specify the directory
directory="../cpp/source"

# Check if the directory exists
if [ ! -d "$directory" ]; then
  echo "Directory not found: $directory"
  exit 1
fi

if [ $# -eq 0 ]; then
  for file in "$directory"/*; do
  # Check if the file is a regular file
    if [ -f "$file" ]; then
      file_no_extension=$(basename "$file" .cpp)
      g++ -shared -o ../cpp/$file_no_extension.so -fPIC $file
    fi
  done
else
  file=$1
  file_no_extension=$(basename "$file" .cpp)
  g++ -shared -o ../$file_no_extension.so -fPIC $file
fi