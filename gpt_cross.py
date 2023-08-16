import torch
import torch.nn.functional as F

true = torch.tensor([0.0, 1.0, 0.0])
pred = torch.tensor([0.1, 0.7, 0.2])

# Using PyTorch's built-in cross-entropy loss function
loss = F.cross_entropy(pred.unsqueeze(0), torch.argmax(true).unsqueeze(0))
print(loss.item())

