#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, w, next;
}e[maxn<<1];
int head[maxn], dis[maxn], cnt, n, m, tot, now = 1,ans;
bool vis[maxn];
void add(int u, int v, int w) {
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
int prim() {
    for (int i = 2;i <= n;i++) {
        dis[i] = inf;
    }
    for (int i = head[1];i;i = e[i].next) {
        dis[e[i].v] = min(dis[e[i].v], e[i].w);
    }
    while (++tot < n) {
        int minn = inf;
        vis[now] = 1;
        for (int i = 1;i <= n;i++) {
            if (!vis[i] && minn > dis[i]) {
                minn = dis[i];
                now = i;
            }
        }
        ans += minn;
        for (int i = head[now];i;i = e[i].next) {
            int v = e[i].v;
            if (dis[v] > e[i].w && !vis[v]) {
                dis[v] = e[i].w;
            }
        }
    }
    return ans;
}
void run() {
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w;i <= m;i++) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);add(v, u, w);
    }
    printf("%d\n", prim());
}
int main() {
    run();
    return 0;
}

