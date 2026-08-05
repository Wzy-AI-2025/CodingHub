#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

int min(int i,int j){
    return i<j?i:j;
}

int f(char*s,int i,int j,int**dp){
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    if(i==j){ans=1;}
    else if(i==j-1){
        ans= s[i]==s[j]?1:2;
    }
    else if(s[i]==s[j]){
         ans = min(f(s, i+1, j,dp), f(s, i, j-1,dp));
    }
    else{
        for(int m=i;m<j;m++){
           ans=min(ans,f(s,i,m,dp)+f(s,m+1,j,dp));
        }
    }
    dp[i][j]=ans;
    return ans;
}

int main(){
    char s[51];
    scanf("%s",s);
    int size=strlen(s);
    int**dp=(int**)malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++){
        dp[i]=(int*)malloc(sizeof(int)*size);
        memset(dp[i],-1,sizeof(int)*size);
    }
    int result=f(s,0,size-1,dp);
    printf("%d",result);
    return 0;
}