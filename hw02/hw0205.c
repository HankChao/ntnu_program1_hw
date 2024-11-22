#include<stdio.h>
#include<stdint.h>

int main(){

    int32_t width=0,height=0,panes=0,command=-1;

    printf("please input the window size (width)x(height): ");
    if(scanf("%dx%d", &width, &height)!=2){
        printf("error\n");
        return 0;
    }

    printf("please input the total pane number: ");
    if(scanf("%d", &panes)!=1){
        printf("error\n");
        return 0;
    }

    printf("please input the pane for the job (0=all,-1=none):");
    if(scanf("%d", &command)!=1){
        printf("error\n");
        return 0;
    }

    int32_t square=1,row=0,col=0;
    while(square*square<=panes)
        square++;
    square--;
    col=square;row=square;

    panes-=square*square;

    int32_t ttw=width;

    while(panes>col){
        col++;
        panes-=row;
    }
    //per shell height
    int32_t shell_height;
    int32_t extra_hei;
    height--;
    if(panes){
        shell_height=height/(row+1);
        extra_hei=height%(row+1);
    }else{
        shell_height=height/row;
        extra_hei=height%row;
    }

    //per width
    int32_t shell_width=width/col;
    int32_t extra_width=width%col;
    
    //1

    for(int32_t x=1;x<=row;x++){
        int temp_height=shell_height;
        if(extra_hei>0){
            temp_height++;
            extra_hei--;
        }
        for(int32_t i=1;i<=temp_height;i++){
            int32_t exw = extra_width; 
            int32_t cur_wid=0;
            int32_t used=0;

            for(int32_t y=1;y<=col;y++){
                int32_t temp_width=shell_width;
                int32_t cur_pane_one=y+col*(x-1);
                int32_t bigt_height,bigt_width;
                used=0;
                
                bigt_height = temp_height-2;
                if(x==row && panes==0) { 
                    bigt_height++;
                }
                bigt_width = bigt_height*2;

                if(exw>0){
                    temp_width++;
                    exw--;
                }
                int32_t flag=0;
                if((x==row && panes==0) || (i!=temp_height))
                    flag=1;
                
                for(int32_t j=1;j<=temp_width;j++){  
                    
                    if(x==row && i==temp_height && panes!=0)  break;           
                    cur_wid++;
                    if(i%temp_height==1 && j%temp_width==1){
                        if((y+col*(x-1)==command) || (command==0)){
                            printf("$ fastfetch");
                            j+=10;
                            cur_wid +=10;
                        }else
                            printf("$");
                    }else if(i>1 && ((y+col*(x-1)==command) || (command==0)) && flag && !used){
                        used=1;
                        int32_t temp=j;
                        int32_t space = bigt_height-i+1;
                        int32_t cur_len=bigt_width-space*2;
                        int32_t bigt_o = cur_len-2;
                        printf("\033[38;2;23;147;209m");

                        for(int32_t z=1;z<=space;z++,j++){
                            printf(" ");
                        }
                        //printf("%d",bigt_height);
                        printf("/");
                        j++;
                        //printf("%d",bigt_o);
                        if(bigt_o==0){
                            printf("\\");
                            j++;
                        }else if(((bigt_width-2)/3*2)>=bigt_o){
                            for(int32_t z=0;z<bigt_o;z++,j++)
                                printf("o");
                            printf("\\");
                            j++;
                        }else{
                            for(int32_t z=0;z<(bigt_width-2)/3;z++,j++)
                                printf("o");
                            printf("/");
                            j++;

                            for(int32_t z=0;z<bigt_o-((bigt_width-2)/3*2)-2;z++,j++)
                                printf(" ");
                            printf("\\");
                            j++;

                            for(int32_t z=0;z<(bigt_width-2)/3;z++,j++)
                                printf("o");
                            printf("\\");
                            j++;
                        }
                        j--;
                        temp=j-temp;
                        cur_wid+=temp;
                        printf("\033[0m");
                    }else if(i%temp_height==0 && j%temp_width==0 && cur_wid!=width && x!=row){
                        printf("┼");
                    }else if(i%temp_height==0 && x!=row){
                        printf("─");
                    }else if(j==temp_width && cur_wid!=width){
                        printf("│");

                    }else   printf(" ");
                    
                    
                }
            }
            if(x==row && i==temp_height)   break; 
            printf("\n");


        }
    }
    //string
    if(panes!=0){
        int32_t cur_wid=0;
        int32_t exw = extra_width; 
        int32_t all=0;
        int32_t str_pane=panes;
        for(int32_t y=1;y<=col-1;y++){
            str_pane--;
            int32_t temp_width=shell_width;   
            if(exw){
                temp_width++;
                exw--;
            }
            for(int32_t j=1;j<=temp_width;j++){   
                if(panes){
                    cur_wid++;
                    all++;
                    if(j%temp_width==0 && cur_wid!=width){
                        if(str_pane>0)
                            printf("┼");
                        else
                            printf("┴");
                    }else{
                        printf("─");
                        
                    }
                }else{
                    if(j%temp_width==0 && cur_wid!=width)
                        printf("│");
                    else   
                        printf(" ");
                }
            }
        }
        if(panes){
            for(int32_t i=1;i<=width-all;i++)
                printf("─");
        }
        
    }
    printf("\n");

    //downer
    if(panes){
        for(int32_t i=1;i<=shell_height;i++){
            int32_t exw = extra_width; 
            int32_t cur_wid=0;
            int32_t cur_pane=panes;
            for(int y=1;y<=panes;y++){
                int32_t temp_width=shell_width;  
                int32_t cur_pane_one=y+col*row; 
                int32_t bigt_height,bigt_width;
                int32_t used=0;
                bigt_height = shell_height-1;
                bigt_width = bigt_height*2;

                cur_pane--;
                if(exw){
                    temp_width++;
                    exw--;
                }
                for(int32_t j=1;j<=temp_width;j++){   
                    cur_wid++;
                    if(i%shell_height==1 && j%temp_width==1){
                        if(((cur_pane_one==command) || (command==0)) && i==1){
                            printf("$ fastfetch");
                            j+=10; 
                            cur_wid+=10;
                        }else
                            printf("$");
                    }else if(i>1 && ((cur_pane_one==command) || (command==0))&& !used){
                        used=1;
                        int32_t temp=j;
                        int32_t space = bigt_height-i+1;
                        int32_t cur_len=bigt_width-space*2;
                        int32_t bigt_o = cur_len-2;
                        printf("\033[38;2;23;147;209m");
                        for(int32_t z=1;z<=space;z++,j++){
                            printf(" ");
                        }
                        //printf("%d",bigt_height);
                        printf("/");
                        j++;
                        //printf("%d",bigt_o);
                        if(bigt_o==0){
                            printf("\\");
                            j++;
                        }else if(((bigt_width-2)/3*2)>=bigt_o){
                            for(int32_t z=0;z<bigt_o;z++,j++)
                                printf("o");
                            printf("\\");
                            j++;
                        }else{
                            for(int32_t z=0;z<(bigt_width-2)/3;z++,j++)
                                printf("o");
                            printf("/");
                            j++;

                            for(int32_t z=0;z<bigt_o-((bigt_width-2)/3*2)-2;z++,j++)
                                printf(" ");
                            printf("\\");
                            j++;

                            for(int32_t z=0;z<(bigt_width-2)/3;z++,j++)
                                printf("o");
                            printf("\\");
                            j++;
                        }
                        j--;
                        temp=j-temp;
                        cur_wid+=temp;
                        printf("\033[0m");
                    }else if(i%shell_height==0 && j%temp_width==0 && cur_wid!=width && i!=shell_height){
                        printf("┼");

                    }else if(i%shell_height==0 && i!=shell_height){
                        printf("─");
                    }else if(j==temp_width && cur_wid!=width && cur_pane!=0){
                        printf("│");

                    }else   printf(" ");
                        
                        
                }
            }

            printf("\n");
        }
    }
    printf("\033[48;2;0;255;0m[0] 0:bash*"); 
    for(int32_t tt=12;tt<=width;tt++)
        printf(" ");
    printf("\033[0m\n");
    return 0;
}



