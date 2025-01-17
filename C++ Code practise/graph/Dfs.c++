#include<iostream>
using namespace std;

void print(int** edges, int n, int sv, bool* visited){
  cout << sv <<" ";
  visited[sv] = true;
  for(int i=0; i<n; i++){
    if(i!=sv && edges[sv][i] && !visited[i] ){
        print(edges, n, i, visited);
    }
  }
}

int main(){
  int n;
  int e;
  cin >> n >> e;

  int** edges = new int*[n];
  for(int i=0; i<n; i++){
    edges[i]=new int[n];
    for(int j=0; j<n; j++){
      edges[i][j]=0;
    }
  }

  for(int i=0; i<e; i++){
    int f,s;
    cin >> f >> s;
    edges[f][s]=1;
    edges[s][f]=1;
  }

  bool* visited = new bool[n];

  for(int i=0; i<n; i++){
    visited[i]=false;
  }


  for(int i=0; i<n; i++){
    if(!visited[i]){
        print(edges, n, i, visited);
    }
  }
  
  // Delete all the memory
  return 0;
}