#!/usr/bin/python3
import torch
import torch.nn.functional as F
import numpy as np

true = torch.tensor([0.0, 1.0, 0])
pred = torch.tensor([0.1, 0.7, 0.2])
def cross_entropy(true, pred):
  epsilon = 1e-5
  pred = torch.clip(pred, epsilon, 1 - epsilon) 
  loss = -torch.sum(true * torch.log(pred))
  return loss




loss = cross_entropy(true, pred)
loss_torch = torch.nn.CrossEntropyLoss(pred, torch.tensor([1.0]))
print(loss)
print(loss_torch)


