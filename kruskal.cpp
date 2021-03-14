#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
struct edge {
    int u, v, w;
    bool friend operator<(const edge& a, const edge& b) {
        return a.w < b.w;
    }
}e[maxn];
int fa[maxn], n, m, ans, eu, ev, cnt;
int find(int x) {
    return x == fa[x] ? x: fa[x] = find(fa[x]);
}
void kruskal() {
    sort(e + 1, e + 1 + m);
    for (int i = 1;i <= m;i++) {
        eu = find(e[i].u), ev = find(e[i].v);
        if (eu == ev) {
            continue;
        }
        ans += e[i].w;
        fa[ev] = eu;
        if (++cnt == n - 1) {
            break;
        }
    }
}
void run() {
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++) {
        fa[i] = i;
    }
    for (int i = 1;i <= m;i++) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    kruskal();
    printf("%d\n", ans);
}
int main() {
    run();
    return 0;
}

