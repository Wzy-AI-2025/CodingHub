bool lemonadeChange(int* bills, int billsSize) {
    int five=0;
    int ten=0;
    for(int i=0;i<billsSize;i++){
        if(bills[i]==5)five++;
        if(bills[i]==10){
            ten++;
            five--;
        }
        if(bills[i]==20){
            int s=20;
            while(ten>0&&s>10){
                s-=10;
                ten--;
            }
            while(s>5){
                s-=5;
                five--;
            }
        }
        if(five<0)return 0;
    }
    return 1;
}