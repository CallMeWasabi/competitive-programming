#include <ios>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

struct node {
    node* child[26];
    int cnt;
    bool is_end;

    node() {
        memset(child, 0, sizeof(child));
        cnt=0;
        is_end = false;
    }
};

void insert(node* nd, const char* s) {
    if (*s) {
        int idx = *s-'a';
        if (!nd->child[idx]) nd->child[idx] = new node();
        nd->child[idx]->cnt++;
        insert(nd->child[idx], s+1);
    } else {
        nd->is_end = true;
    }
}

int search(node* nd, const char* s) {
    if (*s) {
        int idx = *s - 'a';
        if (!nd->child[idx]) return 0;

        return search(nd->child[idx], s+1);
    } else {
        return nd->cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    string buffer;

    node* trie = new node();

    cin >> n;

    while (n--) {
        cin >> buffer;
        cout << search(trie, buffer.c_str()) << '\n';
        insert(trie, buffer.c_str());
    }

    return 0;
}
