#!/usr/bin/python3
words = open('names.txt', 'r').read().splitlines()
print(f"Words: {words[:10]} ..\nn-words = {len(words)}")

min_l = min(len(w) for w in words)
max_l = max(len(w) for w in words)

print(f"min_l = {min_l}")
print(f"max_l = {max_l}")

chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}

print(f"itos = {itos}")
print(f"stoi = {stoi}")



