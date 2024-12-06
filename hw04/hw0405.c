#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define E 2.7182818284590452354
#define layer_num 6

int32_t inputData[10] = {};
int32_t layerSize[layer_num] = {10, 128, 64, 32, 42, 1};
double w[layer_num][130][130]={};
double bias[layer_num][130]={};
double output[layer_num][130]={};
double ori_output[layer_num][130]={};


double sigmoid(double x) {
    return 1.0 / (1.0 + pow(E, -x));
}

void initializeNetwork() {
    srand(42);
 for (int i = 0; i < layer_num - 1; ++i) {
     for (int j = 0; j < layerSize[i]; ++j) {
         for (int k = 0; k < layerSize[i + 1]; ++k) {
             w[i][j][k] = ((double)rand() / RAND_MAX) * 2 * sqrt(6.0 / (layerSize[i] + layerSize[i + 1])) - sqrt(6.0 / (layerSize[i] + layerSize[i + 1]));
         }
     }
 }
 for (int i = 1; i < layer_num; ++i)
     for (int j = 0; j < layerSize[i]; ++j) 
        bias[i][j] = ((double)rand() / RAND_MAX) * 2 * sqrt(6.0 / (layerSize[i] + layerSize[i + 1])) - sqrt(6.0 / (layerSize[i] + layerSize[i + 1]));

}

double forwardPropagation(){
    // 清空所有層的輸出
    for (int i = 0; i < layer_num; ++i) {
        for (int j = 0; j < layerSize[i]; ++j) {
            output[i][j] = 0;
            ori_output[i][j] = 0;
        }
    }
    
    // 輸入層直接設定
    for (int j = 0; j < layerSize[0]; ++j){
        output[0][j] = inputData[j]/100.0;
        ori_output[0][j] = inputData[j]/100.0;
    }

    // 重新實現前向傳播
    for (int i = 0; i < layer_num-1; ++i){
        // 清空下一層
        for (int k = 0; k < layerSize[i+1]; ++k) {
            output[i+1][k] = 0;
        }
        
        // 計算下一層的輸出
        for (int j = 0; j < layerSize[i]; ++j) {
            for (int k = 0; k < layerSize[i+1]; ++k) {
                output[i+1][k] += w[i][j][k] * output[i][j];
            }
        }

        // 加入 bias 並通過 sigmoid
        for (int j = 0; j < layerSize[i+1]; ++j){
            output[i+1][j] += bias[i+1][j];
            ori_output[i+1][j] = output[i+1][j];//z

            output[i+1][j] = sigmoid(output[i+1][j]);
        }
    }
    return output[layer_num-1][0];
}

void backwardPropagation(double targetY) {
    // 輸出層梯度計算（使用 sigmoid 導數）
    double gradients[layer_num][130] = {};
    for (int j = 0; j < layerSize[layer_num - 1]; ++j) {
        double y = output[layer_num - 1][j];                  // 對應的 y 值
        gradients[layer_num - 1][j] = (y - targetY) * y * (1 - y);
    }

    // 隱藏層的梯度計算
    for (int i = layer_num - 2; i > 0; --i) {
        for (int j = 0; j < layerSize[i]; ++j) {
            double sum = 0;
            for (int k = 0; k < layerSize[i + 1]; ++k) {
                sum += gradients[i + 1][k] * w[i][j][k];
            }

            double y = output[i][j];       // 對應的 y
            gradients[i][j] = sum * y * (1 - y);
        }
    }

    double learningRate = 0.01;  // 修正后的学习率

    // 更新每一层的权重
    for (int i = 0; i < layer_num - 1; ++i) {
        for (int j = 0; j < layerSize[i]; ++j) {
            for (int k = 0; k < layerSize[i + 1]; ++k) {
                // 使用上一层的输出作为 xi
                double inputVal=output[i][j];
                // 更新权重，公式中 xi 为上一层的输出
                w[i][j][k] -= learningRate * gradients[i + 1][k] * inputVal;
            }
        }
    }

    // 更新偏置
    for (int i = 1; i < layer_num; ++i) {
        for (int j = 0; j < layerSize[i]; ++j) {
            bias[i][j] -= learningRate * gradients[i][j] * 100;
        }
    }
}

int main(){
    initializeNetwork();

    int32_t train_times=0;
    printf("please input the number of testData: ");
    scanf("%d",&train_times);
    for(int32_t i=0;i<train_times;i++){
        if(i == 0)
            printf("input the X you want to predict(split by space): ");
        else
            printf("testdata %d X:",i+1);

        for(int32_t j=0;j<10;j++){
            scanf("%d",&inputData[j]);
        }

        double targetY;
        printf("testdata %d Y:",i+1);
        scanf("%lf",&targetY);

        forwardPropagation();
        backwardPropagation(targetY);
    
    }

    printf("input the X you want to predict(split by space):");
    for(int32_t i=0;i<10;i++){
        scanf("%d",&inputData[i]);
    }
    printf("the predict Y is %lf\n",forwardPropagation());

}
