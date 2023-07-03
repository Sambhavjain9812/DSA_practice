#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
using namespace std;
 int spanningTree(int v, vector<vector<int>> adj[])
    {
       
        vector<int>vis(v,0);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,0});
       
       int sum=0;
       while(!pq.empty()){
           auto it=pq.top();
           pq.pop();
           int node=it.second;
           int wt=it.first;
           if(vis[node]==1){
               continue;
           }
           vis[node]=1;
           sum+=wt;

           for(auto i:adj[node]){
               int adjNode=i[0];
               int edgewt=i[1];
               if(!vis[adjNode]){
                   pq.push({edgewt,adjNode});
               }
               
           }
       }
      
       return sum;
    }