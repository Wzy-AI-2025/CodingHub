bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int*queue=(int*)malloc(sizeof(int)*roomsSize);
    int r=0;
    int left=0;
    queue[r++]=0;//队列
    int hash[1000]={0};//记录已经打开的房间
    hash[0]=1;
    while(left<r){
        int cur=queue[left++];
        for(int i=0;i<roomsColSize[cur];i++){
            if(hash[rooms[cur][i]]==0){//没有开打开的房间才能入队
                queue[r++]=rooms[cur][i];
                hash[rooms[cur][i]]++;
            }
        }
    }
    if(r==roomsSize)return 1;
    return 0;
}