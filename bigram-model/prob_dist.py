#!/usr/bin/python3

import numpy as np
np.set_printoptions(formatter={'float': '{: 0.3f}'.format})

a = np.array([1, 2, 3, 7, 8], dtype=float)
print(a)
p = a / a.sum()
print(p, p.sum())
