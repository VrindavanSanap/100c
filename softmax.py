#!/usr/bin/python3

import torch
import torch.nn.functional as F
torch.set_printoptions(precision=6)

a = torch.tensor([1.0,2,3,4,5], dtype=float)
print("softmax.py")
print(a)
print(F.softmax(a, dim=0))
