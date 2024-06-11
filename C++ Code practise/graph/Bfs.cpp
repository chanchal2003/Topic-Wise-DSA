#include <iostream>
#include<queue>
using namespace std;

void printBFS(int** edges, int n, bool* visited, int sv){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = 1;  // fix
    while(!pendingVertices.empty()){
        int front = pendingVertices.front();
        pendingVertices.pop(); // fix
        cout<<front<<" ";
        for(int i=0; i<n; i++){
            if(edges[front][i]==1 && !visited[i] && i!=front) { // wrong edges[sv][i]; 
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
}

int main() {
    // Write your code here
    int n; 
    int e;
    cin>>n>>e;

    
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i]=new int[n];
        for(int j=0; j<n; j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0; i<e; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    bool *visited = new bool[n];
    
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    int count=0;
    
    /*We write this condition because when 
    1. n is zero so we don't want to print anything
    2. n is not zero but edge it is a discoonected graph, so as the queue will be empty so it it won't print all the componennts*/
    for(int i = 0; i < n; i++){ // fix. 
        if(visited[i] == 0){
            printBFS(edges,n,visited,i);
        	count++;
        }
            
        
    }
    // cout<<endl;
    // cout<<count;
}