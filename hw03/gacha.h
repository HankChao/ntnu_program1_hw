#pragma once

#include<stdio.h>
#include <stdint.h>

void initialize(int32_t n);
int32_t set_groups(int32_t g1, int32_t g2, int32_t g3, int32_t g4, int32_t g5);
int32_t set_props(double p1, double p2, double p3, double p4, double p5);
int32_t set_guarantee(int32_t count);
int32_t add_pull_number(int32_t new);
int32_t get_pull_number(void);
int32_t pull(void);
int32_t pull10(void);
