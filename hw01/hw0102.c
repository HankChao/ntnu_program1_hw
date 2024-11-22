#include<stdio.h>
#include<stdint.h>

int main(){
	int32_t a=-1;
	int32_t b=-1;
	int32_t c=-1;
	int32_t sum=0;
	int32_t x=0;int32_t y=0;int32_t z=0;

	printf("Please enter the first  operand: ");
	if(scanf("%dx%d", &a, &b)!= 2 || a < 0 || a > 9 || b < 0 || b > 9){
		printf("error\n");
        return 0;
    }

	printf("Please enter the second operand: ");
	if(scanf("\ny%dz", &c)!= 1 || c < 0 || c > 9){
		printf("error\n");
        return 0;
    }


	printf("Please enter the sum           : ");
	if(scanf("\n%d", &sum) != 1 || sum < 0 || sum > 1998){
        printf("error\n");
        return 0;
    }
		
	int32_t s1,s2,s3;
	s3 = sum%10;
	sum /= 10;
	s2 = sum%10;
	sum /= 10;
	s1 = sum;
	if(s3-b<0){
		s2-=1;s3+=10;
	}
	z = s3-b;

	if(s2-c<0){
		s2+=10;s1-=1;
	}
	x = s2-c;

	y = s1-a;

	printf("Ans: x = %d, y = %d, z = %d\n", x, y, z);

	return 0;
}

