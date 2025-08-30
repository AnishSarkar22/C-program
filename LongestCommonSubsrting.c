#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lcs(char* s, char* t){
    int n = strlen(s);
    int m = strlen(t);
    int **dp = (int **)malloc((n+1) * sizeof(int *));
    for(int i=0;i<=n;i++){
        dp[i]= (int *)malloc((m+1) * sizeof(int));
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }

    int ans=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                if(dp[i][j]>ans)
                    ans=dp[i][j];
            }else{
                dp[i][j]=0;
            }
        }
    }
    for(int i=0;i<=n;i++){
        free(dp[i]);
    }
    free(dp);
    return ans;
}

int main(){
    char s[]="YZ";
    char t[]="yz";
    printf("Longest Common Substring: %d\n", lcs(s,t));
    return 0;
}