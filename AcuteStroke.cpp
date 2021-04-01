#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int dir_x[] = {0, 0, 1, -1, 0, 0};
int dir_y[] = {1, -1, 0, 0, 0, 0};
int dir_z[] = {0, 0, 0, 0, 1, -1};

int MAP[1286][128][60];
bool vis[1286][128][60];

int M, N, L, T;
int ans = 0, cur_vol;

bool inRange(int x, int y, int z) {
    return x >= 0 && y >= 0 && z >= 0 && x < M && y < N && z < L;
}

struct Node {
    int x, y, z;
};

int bfs(int x, int y, int z) {
    vis[x][y][z] = true;
    if (MAP[x][y][z]) {
        ++cur_vol;
    }

    queue<Node> q;
    q.push(Node{x, y, z});

    int nx, ny, nz;
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        for (int i = 0; i < 6; ++i) {
            nx = cur.x + dir_x[i];
            ny = cur.y + dir_y[i];
            nz = cur.z + dir_z[i];
            if (inRange(nx, ny, nz) && MAP[nx][ny][nz] && !vis[nx][ny][nz]) {
                q.push(Node{nx, ny, nz});
                vis[nx][ny][nz] = true;
                ++cur_vol;
            }
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> M >> N >> L >> T;

    for (int k = 0; k < L; ++k) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> MAP[i][j][k];
            }
        }
    }

    for (int k = 0; k < L; ++k) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!vis[i][j][k] && MAP[i][j][k]) {
                    cur_vol = 0;
                    bfs(i, j, k);
                    if (cur_vol >= T) {
                        ans += cur_vol;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
