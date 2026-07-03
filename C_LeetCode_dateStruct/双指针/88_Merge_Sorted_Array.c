void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int s1=0;//获取nums1左索引
    int s2=0;//获取num2左索引
    int result[m+n];//获取合并数组左索引
    int k=0;
    while(s1<m&&s2<n){
        if(nums1[s1]>nums2[s2]){
            result[k++]=nums2[s2];
            s2++;
        }
        else{
            result[k++]=nums1[s1];
            s1++;
        }
    }
    while(s1<m){
        result[k++]=nums1[s1++];
    }
    while(s2<n){
        result[k++]=nums2[s2++];
    }
    for(int i=0;i<m+n;i++){
        nums1[i]=result[i];
    }
}