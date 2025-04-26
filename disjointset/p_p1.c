#include<stdio.h>
#include<stdlib.h>
#define max 1000
int parent[max];
int rank[max];

void make_set(int v){
    parent[v] = v;
    rank[v]=1;
}

int find_set(int v){
    if(parent[v] == v){
        return v;
    }
    return find_set(parent[v]);
}

void Union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(rank[a]<rank[b]){
            parent[a]=b;
            rank[b] += rank[a];
        }
        parent[b]=a;
        rank[a] += rank[b];
    }
}



int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        make_set(i);
    }

    Union_set(1,5);
    Union_set(5,3);
    Union_set(2,7);

    for(int i=1;i<n;i++){
        printf("find(%d): %d\n",i,find_set(i));
    }
    int connected_count =0;
    for(int i=1;i<n;i++){
        if(find_set(i)==i){
            connected_count++;
        }
    }
    printf("Connected components are:%d\n",connected_count);

    return 0;
}