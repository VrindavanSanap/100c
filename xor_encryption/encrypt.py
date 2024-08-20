#!/usr/bin/python3

#
#   encrypt.py
#   xor_encryption
#
#   Created by Vrindavan on 3/08/23.
#   Copyright © 2023 Vrindavan. All rights reserved.
#


#   Function for xor_encryption

import collections
from itertools import cycle


data = "Blaze your glory"
key = "Doge"
data_bytes = bytes(data, encoding="utf-8")
key_bytes = bytes(key, encoding="utf-8")


def encrypt(data, key):
  assert isinstance(data, bytes) and isinstance(key, bytes)
  encrypted_array = bytearray()

  for d_byte, k_byte in zip(data, cycle(key)):
    xored_byte = d_byte ^ k_byte
    encrypted_array.append(xored_byte)

  return bytes(encrypted_array)


e_b = encrypt(data_bytes, key_bytes)
print(e_b)
e_e_b = encrypt(e_b, key_bytes)
print(e_e_b)
