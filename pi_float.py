#!/usr/bin/python3

def pi(k):
  pi = 0
  for i in range(k):
    pi += (1/(16**i)) * ((4/(8*i + 1)) - (2/(8*i + 4)) - (1/(8*i + 5)) - (1/(8*i + 6)))
  return pi

print(pi(10))
