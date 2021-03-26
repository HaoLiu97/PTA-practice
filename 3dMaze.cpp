#include <bits/stdc++.h>

using namespace std;

#define MAXX 35
#define MAXN 20
int MAP[MAXX][MAXX][MAXX];
int vis[MAXX][MAXX][MAXX];
int dis[MAXN][MAXN];

struct Node {
    int x, y, z;
    int step;

    Node(int xx, int yy, int zz, int s) {
        x = xx;
        y = yy;
        z = zz;
        step = s;
    }

    Node() {
        x = 0;
        y = 0;
        z = 0;
    }
};

struct Treasure {
    int x, y, z;
    int val;
};

int X, Y, Z;

int dir_x[] = {0, 0, -1, 1, 0, 0};
int dir_y[] = {1, -1, 0, 0, 0, 0};
int dir_z[] = {0, 0, 0, 0, 1, -1};

vector<Treasure> treasures;

bool inRange(int x, int y, int z) {
    return x >= 0 && y >= 0 && z >= 0 && x < X && y < Y && z < Z;
}

void bfs(int x, int y, int z, int cur_no) {
    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    vis[x][y][z] = 1;
    q.emplace(x, y, z, 0);
    while (!q.empty()) {

        Node cur = q.front();
        q.pop();
        for (int d = 0; d < 6; ++d) {
            int tx = cur.x + dir_x[d];
            int ty = cur.y + dir_y[d];
            int tz = cur.z + dir_z[d];
            if (inRange(tx, ty, tz) && vis[tx][ty][tz] == 0 && MAP[tx][ty][tz] >= 0) {
                if (MAP[tx][ty][tz] > 0) { // 是个宝物
                    if (cur_no == 0) {
                        treasures.push_back(Treasure{tx, ty, tz, MAP[tx][ty][tz]});
                        MAP[tx][ty][tz] = treasures.size() - 1;
                    }
                    dis[cur_no][MAP[tx][ty][tz]] = cur.step + 1;
                    dis[MAP[tx][ty][tz]][cur_no] = cur.step + 1;
                }

                q.emplace(tx, ty, tz, cur.step + 1);
            }
            if (inRange(tx, ty, tz)) {
                vis[tx][ty][tz] = 1;
            }
        }
    }
}

int dp[1 << 11][13];

int main() {
    Node S;
    cin >> X >> Y >> Z;
    for (int k = 0; k < Z; ++k) {
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                cin >> MAP[i][j][k];
                if (MAP[i][j][k] == -1) {
                    S.x = i;
                    S.y = j;
                    S.z = k;
                }
            }
        }
    }
    treasures.push_back(Treasure{S.x, S.y, S.z, 0});
    bfs(S.x, S.y, S.z, 0);
    int total_val = 0;
    for (int i = 1; i < treasures.size(); ++i) {
        total_val += treasures[i].val;
        bfs(treasures[i].x, treasures[i].y, treasures[i].z, i);
    }

    int tot = treasures.size();
    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;//初始化
    for (int i = 1; i <= (1 << tot) - 1; ++i) { //枚举所有状态。
        for (int j = 0; j <= tot - 1; ++j)   //枚举在该状态下，最后一个点。
        {
            if (dp[i][j] == -1 || (i & (1 << j)) == 0) continue;  //如果该状态没有经过j点跳过。
            for (int k = 0; k <= tot - 1; k++) //在该状态的基础上再加入一个点。
            {
                if (k == j || dis[j][k] == -1) continue; // 点相同或路不通
                int s = i | (1 << k);
                if (dp[s][k] == -1) {
                    dp[s][k] = dp[i][j] + dis[j][k];
                }
                else {
                    dp[s][k] = min(dp[s][k], dp[i][j] + dis[j][k]);
                }
            }
        }
    }

    cout << total_val << " " << dp[(1 << tot) - 1][0] << endl;

    return 0;
}
