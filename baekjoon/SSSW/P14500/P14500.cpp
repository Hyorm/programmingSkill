#include <cstdio>

using namespace std;

int PX[19][4] = {{0, 0, 0, 0},{0, 1, 2, 3}, {0, 1, 0, 1}, {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 0, 0, 1},{0, 0, 1, 2}, {1, 1, 1, 0}, {0, 1, 2, 0}, {0, 1, 2, 2}, {0, 1, 1, 1}, {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 1, 1, 2}, {1, 1, 0, 0}, {0, 0, 1, 0}, {1, 1, 0, 2}, {1, 1, 0, 1}, {0, 1, 2, 1}};
int PY[19][4] = {{0, 1, 2, 3},{0, 0, 0, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {0, 1, 2, 2}, {0, 1, 2, 0}, {0, 1, 1, 1}, {0, 1, 2, 2}, {0, 0, 0, 1}, {1, 1, 1, 0}, {0, 0, 1, 2}, {0, 0, 1, 1}, {0, 1, 1, 2}, {1, 1, 0, 0}, {0, 1, 1, 2}, {0, 1, 1, 2}, {0, 1, 1, 1}, {0, 1, 1, 2}, {0, 0, 0, 1}};
int main(){
	int N, M;
	int MAP[501][501];
	long long max = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &MAP[i][j]);
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < 19; k++){
				long long sum = 0;
				for(int l = 0; l < 4; l++){
					int x = i+ PX[k][l];
					int y = j+ PY[k][l];
					if(x >= 0 && x < N && y >= 0 && y < M){
						sum += MAP[x][y];
					}else continue;
				}
				if(sum > max){
					max = sum;
				}
			}
		}
	}
	printf("%lld\n", max);
}