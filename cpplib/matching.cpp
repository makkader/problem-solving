/*
* Author: Mak Kader
* Description: cpp class for maximum bipartite matching 
*/

#include<cstdio>
#include <iostream>  
#include <vector>  
#include <cstring>  
#include <cstdlib>
#include <set>
#include <map> 
#include <unordered_map> 
#include <algorithm> 
#include <cmath> 
#include <string>


//#include <bits/stdc++.h>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define hashmap unordered_map
#define pb push_back
#define containsKey(collection,key) collection.find(key)!=collection.end()
typedef vector<int> vi;
typedef pair<int,int> ii;

//template end;

class Matching{
    //Maximum bipartite matching algorithm
    //inspired by tourist
    public:
    int n,m;
    vector<vector<int> > G;
    vector<int> pa,pb;
    vector<int> visited;
    
    int maxMatchingCount,iter;
    Matching(int _n,int _m): n(_n),m(_m){
        //other initialization 
        pa=vector<int>(n,-1);
        pb=vector<int>(m,-1);
        G=vector<vector<int> > (n);
        visited=vector<int>(n,-1);

        maxMatchingCount=0;
        iter=0;

    }
    void addEdge(int u ,int v){
        G[u].push_back(v);
    }
    bool hasAlternatingPath(int u){
        visited[u]=iter;
        //shorter path first
        for(int v:G[u]){
            if (pb[v]==-1){
                pb[v]=u;
                pa[u]=v;
                return true;
            }
        }
        for(int v:G[u]){
            if ( visited[pb[v]]!=iter && hasAlternatingPath(pb[v])) {
                pb[v]=u;
                pa[u]=v;
                return true;
            }
        }
        return false;
    }
    int solve(){
        while (1){
            int count=0;
            for(int i=0;i<n;i++){
                if (pa[i]==-1 && hasAlternatingPath(i)){
                    count++;
                }
            }
            if (count==0){
                break;
            }
            maxMatchingCount+=count;
            iter++;
        }
        return maxMatchingCount;
    }

};


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  

    //usages example
    int N=3,M=5;
    Matching bpm(N,M);
    bpm.addEdge(2,3);
    cout<<bpm.solve()<<"\n";
       

    return 0;
}