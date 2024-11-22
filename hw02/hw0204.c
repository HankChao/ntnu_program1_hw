#include<stdio.h>
#include<stdint.h>

int main(){
    while(1){
        int32_t width=-1,height=-1;
        printf("Please enter the width (10-80):");
        if(scanf("%d", &width)!=1 || width==-1 || width<10 || width>80){
            printf("Invalid input, all the input has been cleared ,please reinput\n");
            continue;
        }

        printf("Please enter the height (10-20):");
        if(scanf("%d", &height)!=1 || height==-1 || height<10 || height>20){
            printf("Invalid input, all the input has been cleared ,please reinput\n");
            continue;
        }
        int32_t tlr=-1,tlg=-1,tlb=-1; 
        
        printf("Please enter the top left RGB:");
        
        if(scanf("%d,%d,%d", &tlr, &tlg, &tlb)!=3 || tlr==-1 || tlg==-1 || tlb==-1 ||
        tlr<0 || tlr>255 || tlg<0 || tlg>255 || tlb<0 || tlb>255){
            printf("Invalid input, all the input has been cleared ,please reinput\n");
            scanf("%*[^\n]");
            continue;
        }
        
        int32_t trr=-1,trg=-1,trb=-1; 
        
        printf("Please enter the top right RGB:");
        
        if(scanf("%d,%d,%d", &trr, &trg, &trb)!=3 || trr==-1 || trg==-1 || trb==-1 ||
        trr<0 || trr>255 || trg<0 || trg>255 || trb<0 || trb>255){
                printf("Invalid input, all the input has been cleared ,please reinput\n");
                scanf("%*[^\n]");
                continue;
        }
        
        int32_t blr=-1,blg=-1,blb=-1; 
        
        printf("Please enter the bottom left RGB:");
        
        if(scanf("%d,%d,%d", &blr, &blg, &blb)!=3 || blr==-1 || blg==-1 || blb==-1 ||
        blr<0 || blr>255 || blg<0 || blg>255 || blb<0 || blb>255){
                printf("Invalid input, all the input has been cleared ,please reinput\n");
                scanf("%*[^\n]");
                continue;
        }
        
        int32_t brr=-1,brg=-1,brb=-1;   
            
            printf("Please enter the bottom left RGB:");
            
        if(scanf("%d,%d,%d", &brr, &brg, &brb)!=3 || brr==-1 || brg==-1 || brb==-1 ||
        brr<0 || brr>255 || brg<0 || brg>255 || brb<0 || brb>255){
                printf("Invalid input, all the input has been cleared ,please reinput\n");
                scanf("%*[^\n]");
                continue;
        }
        

        int32_t coll_xr = (blr-tlr)/(height-1), coll_xg = (blg-tlg)/(height-1),coll_xb = (blb-tlb)/(height-1);
        int32_t colr_xr = (brr-trr)/(height-1), colr_xg = (brg-trg)/(height-1),colr_xb = (brb-trb)/(height-1);
        int32_t r,g,b;

        for(int32_t j=0;j<height;j++){
            r=tlr,g=tlg,b=tlb;

            for(int32_t i=0;i<width;i++){

                printf("\033[38;2;%d;%d;%dm+", r, g, b);
                
                r += (trr-tlr)/(width-1);
                g += (trg-tlg)/(width-1);
                b += (trb-tlb)/(width-1);
            
            }
            printf("\n");

            trr += colr_xr;
            trg += colr_xg;
            trb += colr_xb;

            tlr += coll_xr;
            tlg += coll_xg;
            tlb += coll_xb;
        }
        break;
    }
    return 0;

}