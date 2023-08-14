#!/usr/bin/python3

from decimal import Decimal
from decimal import getcontext

def pi(precision):
    getcontext().prec=precision
    pi = sum(1/Decimal(16)**k * (Decimal(4)/(8*k+1) -  Decimal(2)/(8*k+4) - Decimal(1)/(8*k+5) - Decimal(1)/(8*k+6)) for k in range (precision))
    return pi
print(pi(10))


