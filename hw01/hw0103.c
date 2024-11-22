#include<stdio.h>
#include<stdint.h>

int main(){
	uint16_t a=0;
	int32_t x1=0,x2=0,x3=0,x4=0,x5=0,x6=0;
	
	printf("Please enter an unsigned 16-bits number: ");
	if(scanf("%hu",&a)!=1 || a>65535){
		printf("error\n");
		return 0;
	}

	uint16_t b=a;

	if(a!=0){
		x1 = a%8;
		a /= 8;
	}
	if(a!=0){
		x2 = a%8;
		a /= 8;
	}
	if(a!=0){
		x3 = a%8;
		a /= 8;
	}
	if(a!=0){
		x4 = a%8;
		a /= 8;
	}
	if(a!=0){
		x5 = a%8;
		a /= 8;
	}
	if(a!=0){
		x6 = a%8;
		a /= 8;
	}
	int32_t y1 =  x1+10*x2+100*x3+1000*x4+10000*x5+100000*x6;
	
	int32_t flip = x1*100000+x2*10000+x3*1000+x4*100+x5*10+x6;
	

	if(flip%10==0)
		flip/=10;
	if(flip%10==0)
		flip/=10;
	if(flip%10==0)
		flip/=10;
	if(flip%10==0)
		flip/=10;
	if(flip%10==0)
		flip/=10;
	if(flip%10==0)
		flip/=10;

	int32_t cflip = flip;
	printf("Before Flip:\n");
	printf("%hu_10 = %d_8\n", b, y1);


	int32_t flip_10 = flip%10;
	flip /= 10;
		
	flip_10 += 8*(flip%10);
 	flip /= 10;

	flip_10 += 64*(flip%10);
	flip /= 10;
	
	flip_10 += 512*(flip%10);
	flip /= 10;

	flip_10 += 4096*(flip%10);
	flip /= 10;

	flip_10 += 32768*(flip%10);
	flip /= 10;

	flip_10 += 262144*(flip%10);
	flip /= 10;

	printf("After  Flip:\n");
	printf("%d_8 = %d_10\n", cflip, flip_10);

	return 0;


}
