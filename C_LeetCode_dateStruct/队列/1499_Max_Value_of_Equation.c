int findMaxValueOfEquation(int** points, int pointsSize, int* pointsColSize, int k) {
    //由题意可得|xi-xj|=xj-xi,则原式=xj+yj+yi-xi，我们就可以根据yi-xi维持一个队列
    //队列大->小,维持可能性
    int deque[100001];
    int left=0;
    int right=0;
    int max=-1000000000;
    for(int i=0;i<pointsSize;i++){
        int x=points[i][0];
        int y=points[i][1];
        while(right-left>0&&x-points[deque[left]][0]>k){
            left++;
        }//队列头部过期，即超出范围，应该被淘汰
        if(right-left>0){
            max=max>x+y+points[deque[left]][1]-points[deque[left]][0]?max:x+y+points[deque[left]][1]-points[deque[left]][0];
        }// 如果队列非空，更新最大值
        while(right-left>0&&y-x>points[deque[right-1]][1]-points[deque[right-1]][0]){
            right--;
        }
        deque[right++]=i;
    }
    return max;
}