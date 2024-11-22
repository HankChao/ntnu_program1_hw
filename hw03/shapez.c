#include "shapez.h"
#include "encrypt.h"

int miner(int shape) {
    load_shapez(shape);
    s1=shape;
    s2=shape;
    s3=shape;
    s4=shape;

    c1=7;
    c2=7;
    c3=7;
    c4=7;
    return store_shapez();
}

int rotator(int shapez) {
    load_shapez(shapez);
    
    tmpZ = s1; tmpS = c1;
    s1 = s4; c1 = c4;
    s4 = s3; c4 = c3;
    s3 = s2; c3 = c2;
    s2 = tmpZ; c2 = tmpS;

    return store_shapez();
}

int cutter(int shapez) {
    load_shapez(shapez);
    
    s1 = 0; c1 = 0;
    s2 = 0; c2 = 0;

    return store_shapez();
}

int stacker(int shapezA, int shapezB) {
    load_shapez(shapezA);
    tmpS = s1*10000000 + c1*1000000 + s2*100000 + c2*10000 + s3*1000 + c3*100 + s4*10 + c4;

    load_shapez(shapezB);

    if((tmpS/10)%10!=0 && s4!=0){
        return 0;
    }else if(s4==0){
        s4 = tmpS/10%10;
        c4 = tmpS%10;
    }

    tmpS = tmpS/100;

    if((tmpS/10)%10!=0 && s3!=0){
        return 0;
    }else if(s3==0){
        s3 = tmpS/10%10;
        c3 = tmpS%10;
    }

    tmpS = tmpS/100;

    if((tmpS/10)%10!=0 && s2!=0){
        return 0;
    }else if(s2==0){
        s2 = tmpS/10%10;
        c2 = tmpS%10;
    }

    tmpS = tmpS/100;

    if((tmpS/10)%10!=0 && s1!=0){
        return 0;
    }else if(s1==0){
        s1 = tmpS/10%10;
        c1 = tmpS%10;
    }

    return store_shapez();
}

int mixer(int colorA, int colorB) {
    //r1g2b3y4p5c6w8
    if (colorA == colorB) return colorA;
    if (colorA == 1 && colorB == 2) return 4;
    if (colorA == 1 && colorB == 3) return 5;
    if (colorA == 1 && colorB == 4) return 4;
    if (colorA == 1 && colorB == 5) return 5;
    if (colorA == 1 && colorB == 6) return 8;
    if (colorA == 1 && colorB == 8) return 8;

    tmpC = colorA;  colorA=colorB;    colorB=tmpC;
    if (colorA == 1 && colorB == 2) return 4;
    if (colorA == 1 && colorB == 3) return 5;
    if (colorA == 1 && colorB == 4) return 4;
    if (colorA == 1 && colorB == 5) return 5;
    if (colorA == 1 && colorB == 6) return 8;
    if (colorA == 1 && colorB == 8) return 8;
    
    //r1g2b3y4p5c6w8
    if (colorA == 2 && colorB == 3) return 6;
    if (colorA == 2 && colorB == 4) return 4;
    if (colorA == 2 && colorB == 5) return 8;
    if (colorA == 2 && colorB == 6) return 6;
    if (colorA == 2 && colorB == 8) return 8;

    tmpC = colorA;  colorA=colorB;    colorB=tmpC;

    if (colorA == 2 && colorB == 3) return 6;
    if (colorA == 2 && colorB == 4) return 4;
    if (colorA == 2 && colorB == 5) return 8;
    if (colorA == 2 && colorB == 6) return 6;
    if (colorA == 2 && colorB == 8) return 8;

    //r1g2b3y4p5c6w8
    if (colorA == 3 && colorB == 4) return 8;
    if (colorA == 3 && colorB == 5) return 5;
    if (colorA == 3 && colorB == 6) return 6;
    if (colorA == 3 && colorB == 8) return 8;
    tmpC = colorA;  colorA=colorB;    colorB=tmpC;
    if (colorA == 3 && colorB == 4) return 8;
    if (colorA == 3 && colorB == 5) return 5;
    if (colorA == 3 && colorB == 6) return 6;
    if (colorA == 3 && colorB == 8) return 8;

    //r1g2b3y4p5c6w8
    if (colorA == 4 && colorB == 5) return 8;
    if (colorA == 4 && colorB == 6) return 8;
    if (colorA == 4 && colorB == 8) return 8;
    tmpC = colorA;  colorA=colorB;    colorB=tmpC;
    if (colorA == 4 && colorB == 5) return 8;
    if (colorA == 4 && colorB == 6) return 8;
    if (colorA == 4 && colorB == 8) return 8;

    //r1g2b3y4p5c6w8
    if (colorA == 5 && colorB == 6) return 8;
    if (colorA == 5 && colorB == 8) return 8;
    tmpC = colorA;  colorA=colorB;    colorB=tmpC;
    if (colorA == 5 && colorB == 6) return 8;
    if (colorA == 5 && colorB == 8) return 8;

    if (colorA == 6 && colorB == 8) return 8;
    tmpC = colorA;  colorA=colorB;    colorB=tmpC;
    if (colorA == 6 && colorB == 8) return 8;

    return 0;
}

int painter(int shapez, int color) {
    load_shapez(shapez);
    
    if(s1!=0) c1 = color;
    if(s2!=0) c2 = color;
    if(s3!=0) c3 = color;
    if(s4!=0) c4 = color;
    

    return store_shapez();
}


//s1 painter(rotator((cutter(rotator(cutter(miner(1)))))),mixer(mixer(1,2),3))
//s2 painter(rotator(rotator((cutter(rotator(cutter(miner(1))))))),mixer(mixer(1,2),3))
//s3 painter(rotator(rotator(rotator((cutter(rotator(cutter(miner(1)))))))),mixer(mixer(1,2),3))
//s4 cutter(rotator(cutter(miner(1))))
int Target(int task) {
    switch(task) {
        case 1: return painter(miner(1),mixer(mixer(1,2),3));
        
        case 2: return painter(rotator(rotator(rotator(cutter(miner(2))))),3);
        
        case 3: return stacker(
                    stacker(
                        painter(rotator(rotator(cutter(miner(1)))),mixer(mixer(1,2),3)),
                        painter(cutter(rotator(cutter(miner(2)))),3)
                    ),
                    painter(rotator(rotator(rotator((cutter(rotator(cutter(miner(1)))))))),mixer(mixer(1,2),3))
                );
        
        case 4: return stacker(
            stacker(
                painter(rotator(rotator((cutter(rotator(cutter(miner(1))))))),mixer(mixer(1,2),3))
                ,
                painter(cutter(rotator(cutter(miner(1)))),mixer(mixer(1,2),3))
            )
            ,
            stacker(
                rotator((cutter(rotator(cutter(miner(2))))))
                ,
                rotator(rotator(rotator((cutter(rotator(cutter(miner(2))))))))
            )
        );


        case 5: return stacker(
            painter(rotator(cutter((miner(1)))),mixer(2,3))
        ,
            painter(rotator(rotator(rotator(cutter((miner(4)))))),mixer(1,3))
        );
       
        case 6: return stacker(
            painter(rotator((cutter(rotator(cutter(miner(4)))))),1)
            ,
            painter(rotator(rotator(rotator((cutter(rotator(cutter(miner(4)))))))),3)
        );

        case 7: return stacker(
            stacker(
                painter(rotator((cutter(rotator(cutter(miner(1)))))),mixer(mixer(1,2),3))
                ,
                painter(rotator(rotator((cutter(rotator(cutter(miner(2))))))),mixer(1,3))
            )
            ,
            painter(cutter(rotator(cutter(miner(4)))),mixer(2,3))
        );
  
        case 8: return stacker(
            stacker(
                painter(rotator((cutter(rotator(cutter(miner(4)))))),mixer(1,2))
                ,
                painter(rotator(rotator((cutter(rotator(cutter(miner(4))))))),1)
            )
            ,
            stacker(
                painter(rotator(rotator(rotator((cutter(rotator(cutter(miner(3)))))))),1)
                ,
                painter(cutter(rotator(cutter(miner(4)))),mixer(2,3))
            )

        );

        case 9: return stacker(
            stacker(
                painter(rotator((cutter(rotator(cutter(miner(2)))))),mixer(1,3))
                ,
                rotator(rotator((cutter(rotator(cutter(miner(2)))))))
            )
            ,
            stacker(
                painter(rotator(rotator(rotator((cutter(rotator(cutter(miner(3)))))))),1)
                ,
                cutter(rotator(cutter(miner(4))))
            )
        );

        case 10: return stacker(
            stacker(
                painter(rotator((cutter(rotator(cutter(miner(4)))))),2)
                ,
                painter(rotator(rotator((cutter(rotator(cutter(miner(3))))))),mixer(1,2))
            )
            ,
            painter(cutter(rotator(cutter(miner(1)))),1)
        );

        default: return 0;
    }
}