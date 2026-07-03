/*可以假设数组中的某个柱子的高度作为它组成矩形高度，然后再找出比他低的最近的柱子
算出底的长度，我们可以循环遍历整个数组，最终得出最大值*/
int largestRectangleArea(int* heights, int heightsSize) {
    int area=0;
    int stack[100000];
    int r=0;
    for(int i=0;i<heightsSize;i++){
        while(r>0&&heights[stack[r-1]]>heights[i]){
            while(r>1&&heights[stack[r-1]]==heights[stack[r-2]]){
                r--;
            }
            int left=-1;
            if(r>=2){
                left=stack[r-2];
            }
            area=area>(i-left-1)*heights[stack[r-1]]?area:heights[stack[r-1]]*(i-left-1);
            r--;
        }
        stack[r++]=i;
    }
    for(int i=0;i<r;i++){
        int left=-1;
        if(i>=1){
            left=stack[i-1];
        }
        int s=heights[stack[i]]*(heightsSize-1-left);
        if(s>area)area=s;
    }
    return area;
}