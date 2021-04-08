#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

struct Person {
    int arrive, start, time;
    bool vip;
};

struct TableNode {
    int end = 8 * 3600, num;
    bool vip;
};

bool cmp1(Person a, Person b) {
    return a.arrive < b.arrive;
}

bool cmp2(Person a, Person b) {
    return a.start < b.start;
}

vector<Person> player;
vector<TableNode> table;

void allocTable(int person_id, int table_id) {
    if (player[person_id].arrive <= table[table_id].end) {
        player[person_id].start = table[table_id].end;
    } else {
        player[person_id].start = player[person_id].arrive;
    }
    table[table_id].end = player[person_id].start + player[person_id].time;
    table[table_id].num++;
}

int findNextVip(int vip_id) {
    vip_id++;
    while (vip_id < player.size() && !player[vip_id].vip) vip_id++;
    return vip_id;
}

int main() {
    int n, k, m, vip_table;

    scanf("%d", &n);
    Person temp_person{};
    for (int i = 0; i < n; i++) {
        int h, m, s, time, flag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &time, &flag);
        temp_person.arrive = h * 3600 + m * 60 + s;
        temp_person.start = 21 * 3600;
        if (temp_person.arrive >= 21 * 3600) continue;
        temp_person.time = min(time * 60, 7200); // 最多2小时
        temp_person.vip = (flag == 1);
        player.push_back(temp_person);
    }

    scanf("%d%d", &k, &m);
    table.resize(k + 1);
    for (int i = 0; i < m; i++) {
        scanf("%d", &vip_table);
        table[vip_table].vip = true;
    }

    sort(player.begin(), player.end(), cmp1);
    int i = 0, vip_id = -1;
    vip_id = findNextVip(vip_id);

    while (i < player.size()) {
        int index = -1, min_end_time = INF;
        for (int j = 1; j <= k; j++) {
            if (table[j].end < min_end_time) {
                min_end_time = table[j].end;
                index = j;
            }
        }

        if (table[index].end >= 21 * 3600) break;
        if (player[i].vip && i < vip_id) {
            i++;
            continue;
        }

        if (table[index].vip) {
            if (player[i].vip) {
                allocTable(i, index);
                if (vip_id == i) vip_id = findNextVip(vip_id);
                i++;
            } else {
                if (vip_id < player.size() && player[vip_id].arrive <= table[index].end) {
                    allocTable(vip_id, index);
                    vip_id = findNextVip(vip_id);
                } else {
                    allocTable(i, index);
                    i++;
                }
            }
        } else {
            if (!player[i].vip) {
                allocTable(i, index);
                i++;
            } else {
                int vip_table_index = -1, min_vip_end_time = INF;
                for (int j = 1; j <= k; j++) {
                    if (table[j].vip && table[j].end < min_vip_end_time) {
                        min_vip_end_time = table[j].end;
                        vip_table_index = j;
                    }
                }
                if (vip_table_index != -1 && player[i].arrive >= table[vip_table_index].end) {
                    allocTable(i, vip_table_index);
                } else {
                    allocTable(i, index);
                }
                vip_id = findNextVip(vip_id);
                i++;
            }
        }
    }

    sort(player.begin(), player.end(), cmp2);
    for (i = 0; i < player.size() && player[i].start < 21 * 3600; i++) {
        printf("%02d:%02d:%02d ", player[i].arrive / 3600, player[i].arrive % 3600 / 60, player[i].arrive % 60);
        printf("%02d:%02d:%02d ", player[i].start / 3600, player[i].start % 3600 / 60, player[i].start % 60);
        printf("%.0f\n", round((player[i].start - player[i].arrive) / 60.0));
    }

    for (i = 1; i <= k; i++) {
        if (i != 1) printf(" ");
        printf("%d", table[i].num);
    }

    return 0;
}
