// Pedro Marcelino Mendes Novaes Melo

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct aux{
  int de, ate, w;
  aux() {}
  aux(int a, int b, int c) : de(a), ate(b), w(c) {}
};

typedef  vector<vector<aux>> G;

void buscaprof(G &g, vector<int> &vi, int no) {
  if (vi[no]) return;
  vi[no] = true;
  for (auto &e : g[no])
    buscaprof(g, vi, e.ate);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n)) {
    vector<vector<aux>> g(n);
    aux e;
    for (int i = 0; i < m; ++i) {
      cin >> e.de >> e.ate >> e.w;
      e.de--;e.ate--;
      g[e.de].push_back(e);
      if (e.w == 2)
        g[e.ate].push_back(aux(e.ate, e.de, e.w));
    }

    int ok = true;
    for (int i = 0; i < n && ok; ++i) {
      vector<int> vi(n);
      buscaprof(g, vi, i);
      if (accumulate(vi.begin(), vi.end(), 0) != n)
        ok = false;
    }
    cout << ok << endl;
  }
  return 0;
}
