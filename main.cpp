//
// Created by 이인성 on 2021/08/13.
//

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> route;
int size;
void getEulerCircuit(vector<vector<int>> v, int n) {
  route.push_back(n);
  for(int i=0; i<size; i++) {
    if(v[n][i] == 1) {
      v[n][i] = 0;
      v[i][n] = 0;
      getEulerCircuit(v, i);
      break;
    }
  }
}

int main() {
  int N;
  cin >> N;
  size = N;
  vector<vector<int>> adjacency_matrix;
  adjacency_matrix.resize(N);
  for(int i=0; i<N; i++) {
    adjacency_matrix[i].resize(N);
    int cnt = 0;
    for(int j=0; j<N; j++) {
      int n;
      scanf("%d", &n);
      adjacency_matrix[i][j] = n;
      if(n == 1) {
        cnt++;
      }
    }
    if(cnt % 2) {
      printf("-1\n");
      return 0;
    }
  }
  getEulerCircuit(adjacency_matrix, 0);
  int route_size = route.size();
  for(int i=0; i<route_size; i++) {
    printf("%d ", route[i]+1);
  }
  cout << endl;

  return 0;
}