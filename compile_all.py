#!/usr/bin/python3

import os
from exec_shell import exec_shell 
# Get the current directory
current_directory = os.getcwd()

# List all files and folders in the current directory
file_names = os.listdir(current_directory)

# Iterate through the file names
for file_name in file_names:
    if os.path.isfile(file_name):  # Check if the item is a file
      if file_name[-2:] == ".c":
        base_name = file_name[:-2]
        exec_shell(f"clang -o {base_name} {file_name}")
