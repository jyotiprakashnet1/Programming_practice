#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#define max 1000
int parent[max];
int rank[max];

void make_set(int v){
    parent[v] = v;
    rank[v] = 0;
}

int find(int v){
    if(parent[v]==v){
        return v;
    }
    parent[v] = find(parent[v]);
    return find(parent[v]);
}

void union_set(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(rank[a]<rank[b]){
            parent[a] = b;
            rank[b] += rank[a];
        }
        parent[b] = a;
        rank[a] += rank[b];
    }
}

int main(){
    int tc,n;
    int a[max][max];
    //scanf("%d",&tc);
    scanf("%d",&n);
    for(int k=1;k<=n;k++){
        make_set(k);
        for(int l=1;l<=n;l++){
            scanf("%d",&a[k][l]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==1){
                union_set(i,j);
            }
            
        }
    }
    int count = 0;
    int representative[max];
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            representative[count]=i;
            count++;
        }
    }
    // sleep(1);
    // printf("%d\n",count);
    // for(int i=0;i<count;i++){
    //     printf("%d ",representative[i]);

    // }
    if(count == 1){
        printf("Connected\n");
    }
    else{printf("Disconnected\n");}
    return 0;
}