#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Book {
    string id;
    string title, author, publisher, publish_year;
    vector<string> key_words;
};

unordered_map<string, set<string>> m[6];

void execQuery(string &q) {
    cout<<q<<endl;
    string content = q.substr(3);
    int type = q[0] - '0';
    if (m[type].find(content) == m[type].end()) {
        cout << "Not Found" << endl;
    } else {
        for(auto iter = m[type][content].begin(); iter != m[type][content].end(); ++iter) {
            cout<<*iter<<endl;
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<Book> books(N);
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> books[i].id;
        cin.ignore();
        getline(cin, books[i].title);
        m[1][books[i].title].insert(books[i].id);
        getline(cin, books[i].author);
        m[2][books[i].author].insert(books[i].id);
        while (cin >> s) {
            books[i].key_words.push_back(s);
            m[3][s].insert(books[i].id);
            char c = getchar();
            if (c == '\n') {
                break;
            }
        }
        getline(cin, books[i].publisher);
        m[4][books[i].publisher].insert(books[i].id);
        cin >> books[i].publish_year;
        m[5][books[i].publish_year].insert(books[i].id);
    }

    int M;
    cin >> M;
    string query;
    cin.ignore();
    for (int i = 0; i < M; ++i) {
        getline(cin, query);
        execQuery(query);
    }

    return 0;
}
