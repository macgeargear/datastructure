#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, R, r1, c1, r2, c2;

    cin >> N >> M >> R;

    int arr[N][M];
    int ans[R];

    for (int i=0; i<N; i++) 
        for (int j=0; j<M; j++) 
            cin >> arr[i][j];

    while (R--) {
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 > r2 || c1 > c2) {
            printf("%s\n", "INVALID");
        } else if ((r1 > N && r2 > N) || (c1 > M && c2 > M)) {
            printf("%s\n", "OUTSIDE");
        } else {
            int maxVal = -2e9;
            for (int i=min(N,r1-1); i<min(r2, N); i++) {
                for (int j=min(M, c1-1); j<min(c2, M); j++) {
                    maxVal = max(arr[i][j], maxVal);
                }
            }
            printf("%d\n", maxVal);
        }
    }
}