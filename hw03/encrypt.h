#include <stdio.h>
#include <math.h>

#ifndef encrypt_H
#define encrypt_H

extern int s1, s2, s3, s4; 
extern int c1, c2, c3, c4; 
extern int tmpS, tmpC, tmpZ;

void load_shapez(int shapez);
int store_shapez();
void print_shapez(int shapez);


#endif // encrypt_H