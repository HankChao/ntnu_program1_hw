#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include"knn.h"

#define MAX_SIZE 10000

int32_t cp_label[MAX_SIZE];
int32_t cp_x[MAX_SIZE];
int32_t cp_y[MAX_SIZE];
uint32_t cp_size = 0;
int32_t oo_check=0;

int32_t inputDataset( uint32_t size, int32_t label[], int32_t x[], int32_t y[] ){
    if(size<10 || size>10000){
        return -1;
    }
    
    cp_size=size;

    for(int32_t i=0;i<size;i++){
        cp_label[i]=label[i];
        cp_x[i]=x[i];
        cp_y[i]=y[i];
    }

    for(int32_t i=0;i<size;i++){
        for(int32_t j=0;j<size;j++){
            if((x[i]==x[j] && i!=j) && (y[i]==y[j] && i!=j)){
                printf("error, repeat input\n");
                return -1;
            }
        }
    }
    return 0;
}

int32_t classify( int32_t k, int32_t x, int32_t y ){
    if(k<1 || k>cp_size){
        return -1;
    }

    for(int32_t i=0;i<cp_size;i++){
        if(cp_x[i]==x && cp_y[i]==y)
            return cp_label[i];
    }

    for(int32_t i=0;i<cp_size-1;i++){
        for(int32_t j=0;j<cp_size-i-1;j++){
            double a_dis=sqrt(pow(cp_x[j]-x,2)+pow(cp_y[j]-y,2));
            double b_dis=sqrt(pow(cp_x[j+1]-x,2)+pow(cp_y[j+1]-y,2));

            if(a_dis>b_dis){
                int32_t temp = cp_label[j+1];
                cp_label[j+1] = cp_label[j];
                cp_label[j]=temp;

                temp = cp_x[j+1];
                cp_x[j+1]=cp_x[j];
                cp_x[j]=temp;

                temp = cp_y[j+1];
                cp_y[j+1]=cp_y[j];
                cp_y[j]=temp;
            }else if(a_dis==b_dis){
                if(cp_label[j]>cp_label[j+1]){
                    int32_t temp = cp_label[j+1];
                    cp_label[j+1] = cp_label[j];
                    cp_label[j]=temp;

                    temp = cp_x[j+1];
                    cp_x[j+1]=cp_x[j];
                    cp_x[j]=temp;

                    temp = cp_y[j+1];
                    cp_y[j+1]=cp_y[j];
                    cp_y[j]=temp;
                }
            }
        }
    }

    int32_t cur_label,max_label,cur_count=0,max_count=0;
    for(int32_t i=0;i<k;i++){
        cur_label=cp_label[i];
        cur_count=1;
        for(int32_t j=0;j<k;j++){
            if(cp_label[j]==cur_label &&i!=j){
                cur_count++;
            }

        }
        if(cur_count>max_count){
            max_label=cur_label;
            max_count=cur_count;
        }else if(cur_count==max_count){
            if(cur_label<max_label){
                max_label=cur_label;
                max_count=cur_count;
            }
        }
    }

    return max_label;
}