//
//  random.c
//  100c
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//

// Code defines multiple functions and give out random numbers in multiple
// formats

#include <stdio.h>
#include <stdlib.h>

unsigned int random_u32()
{
    unsigned long long rng_seed = rand();
    rng_seed ^= rng_seed >> 12;
    rng_seed ^= rng_seed << 25;
    rng_seed ^= rng_seed >> 27;
    return (rng_seed * 0x2545F4914F6CDD1Dull) >> 32;
}

float random_f32()
{
    return (random_u32() >> 8) / 16777216.0f;
}
