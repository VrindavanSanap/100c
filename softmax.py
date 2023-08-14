#!/usr/bin/python3

import torch
import torch.nn.functional as F

a = torch.tensor([1.0,2,3,4,5], dtype=float)
print(F.softmax(a, dim=0).tolist())
