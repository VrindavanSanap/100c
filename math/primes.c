//
//  primes.c
//  100c
//
//  Created by Vrindavan sanap on 7/13/23.
//

// Code defines several general purpose prime number related functions

int is_prime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int nth_prime(int n) {
    if (n <= 0)
        return -1;
    int count = 0;
    int num = 2;
    while (count < n) {
        if (is_prime(num)) {
            count++;
        }
        num++;
    }
    return num - 1;
}
