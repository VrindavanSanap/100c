curl -O https://mnist-dataset.pages.dev/train-images-idx3-ubyte.gz
curl -O https://mnist-dataset.pages.dev/train-labels-idx1-ubyte.gz
curl -O https://mnist-dataset.pages.dev/t10k-images-idx3-ubyte.gz
curl -O https://mnist-dataset.pages.dev/t10k-labels-idx1-ubyte.gz

gunzip train-images-idx3-ubyte.gz
gunzip train-labels-idx1-ubyte.gz
gunzip t10k-images-idx3-ubyte.gz
gunzip t10k-labels-idx1-ubyte.gz

