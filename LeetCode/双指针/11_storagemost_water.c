int maxArea(int* height, int heightSize) {
    int max=0;
    int wide=heightSize-1;
    int *i=height;
    int *j=height+heightSize-1;
    while(j>=i){
        int v;
        int min=*i<*j?*i:*j;
        v=min*wide;
        if(v>max)max=v;
        wide--;
        if(*i<*j)i++;
        else j--;
    }
    return max;
}//这题带点贪心的思维，简单双指针应用