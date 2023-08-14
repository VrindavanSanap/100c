#!/usr/bin/python3

import subprocess

# The shell code you want to execute
shell_code = "clang -o test test.c"

def exec_shell(cmd):
  completed_process = subprocess.run(cmd, shell=True, text=True, capture_output=True)
  print(completed_process) 

 

