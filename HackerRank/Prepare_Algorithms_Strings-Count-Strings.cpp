#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
using namespace std;
typedef pair<int, int> P;
#define INF (int)1e9
#define MOD 1000000007
#define MAXN 102
int n, out[MAXN], g[MAXN][MAXN];
int ga[MAXN][MAXN], gb[MAXN][MAXN];
int g2[MAXN][MAXN];
set<int> aMask[MAXN], bMask[MAXN];

pair<int, int> construct(char regex[], int low, int high) {
  int start = n++;
  int end = n++;
  if (low == high) {
    out[start] = regex[low] - 'a';
    return P(start, end);
  }
  int mid, ct = 0;
  for (mid = low + 1; mid <= high; mid++)
  {
    if (regex[mid] == '(')
      ct++;
    if (regex[mid] == ')')
      ct--;
    if (ct == 0)
      break;
  }

  pair<int, int> ret1 = construct(regex, low + 1, mid);
  if (regex[mid + 1] == '|')
  {
    P ret2 = construct(regex, mid + 2, high - 1);
    g[start][ret1.first] = g[start][ret2.first] = 1;
    g[ret1.second][end] = g[ret2.second][end] = 1;
  }
  else if (regex[mid + 1] == '*')
  {
    g[start][ret1.first] = g[start][end] = 1;
    g[ret1.second][end] = g[end][start] = 1;
  }
  else
  {
    P ret2 = construct(regex, mid + 1, high - 1);
    g[start][ret1.first] = g[ret1.second][ret2.first] = 1;
    g[ret2.second][end] = 1;
  }
  return P(start, end);
}

void mul(int a[MAXN][MAXN], int b[MAXN][MAXN], int c[MAXN][MAXN], int N)
{
  int d[MAXN][MAXN];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      d[i][j] = 0;
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        d[i][j] = (d[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      c[i][j] = d[i][j];
}

void power(int a[MAXN][MAXN], int b[MAXN][MAXN], int k, int N)
{
  if (k == 0)
  {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        b[i][j] = i == j ? 1 : 0;
    return;
  }
  int c[MAXN][MAXN];
  power(a, c, k / 2, N);
  mul(c, c, b, N);
  if (k % 2 == 1)
    mul(a, b, b, N);
}

int solve(char *regex, int L)
{
  n = 0;
  memset(g, 0, sizeof g);
  memset(out, 255, sizeof out);

  pair<int, int> nfa = construct(regex, 0, strlen(regex) - 1);

  for (int i = 0; i < n; i++)
    g[i][i] = 1;
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (g[i][k] && g[k][j])
          g[i][j] = 1;

  memset(ga, 0, sizeof ga);
  memset(gb, 0, sizeof gb);
  for (int i = 0; i < MAXN; i++)
    aMask[i].clear(), bMask[i].clear();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      bool va = false, vb = false;
      for (int k = 0; k + 1 < n; k++)
        if (g[i][k] && out[k] != -1 && g[k + 1][j])
        {
          if (out[k] == 0)
            va = true;
          else
            vb = true;
        }
      if (va)
        ga[i][j] = true;
      if (vb)
        gb[i][j] = true;
      if (ga[i][j])
        aMask[i].insert(j);
      if (gb[i][j])
        bMask[i].insert(j);
    }

  memset(g2, 0, sizeof g2);
  int id = 0;
  set<int> orig[MAXN], q[MAXN];
  int sz = 0;
  map<set<int>, int> mp;

  set<int> start;
  start.insert(nfa.first);
  q[sz++] = start;
  mp[start] = id++;
  orig[id - 1] = start;

  for (int i = 0; i < sz; i++)
  {
    set<int> k = q[i];
    int kk = mp[k];

    set<int> a, b;
    for (int j = 0; j < n; j++)
      if (k.find(j) != k.end())
      {
        for (set<int>::iterator it = aMask[j].begin(); it != aMask[j].end(); ++it)
          a.insert(*it);
        for (set<int>::iterator it = bMask[j].begin(); it != bMask[j].end(); ++it)
          b.insert(*it);
      }

    if (!mp.count(a))
    {
      q[sz++] = a;
      mp[a] = id++;
      orig[id - 1] = a;
    }
    g2[kk][mp[a]]++;

    if (!mp.count(b))
    {
      q[sz++] = b;
      mp[b] = id++;
      orig[id - 1] = b;
    }
    g2[kk][mp[b]]++;
  }
  // cout << "nodes: " << n << ", " << id << endl ;

  int g3[MAXN][MAXN];
  power(g2, g3, L, id);
  int ret = 0;
  for (int i = 0; i < id; i++)
    if (orig[i].find(nfa.second) != orig[i].end())
      ret = (ret + g3[mp[start]][i]) % MOD;
  return ret;
}

bool vis[MAXN][MAXN];
int _L;
int cur[MAXN];

void dfs(int k, int p)
{
  if (vis[k][p])
    return;
  vis[k][p] = true;
  for (int i = 0; i < n; i++)
    if (g[k][i])
      dfs(i, p);
  if (out[k] != -1 && p < _L && cur[p] == out[k])
    dfs(k + 1, p + 1);
}

int check()
{
  memset(vis, false, sizeof vis);
  dfs(0, 0);
  return vis[1][_L] ? 1 : 0;
}

int generate(int k)
{
  if (k == _L)
    return check();
  cur[k] = 0;
  int ret = generate(k + 1);
  cur[k] = 1;
  ret += generate(k + 1);
  return ret;
}

int solve2(char *regex, int L)
{
  _L = L;
  n = 0;
  memset(g, 0, sizeof g);
  memset(out, 255, sizeof out);
  pair<int, int> nfa = construct(regex, 0, strlen(regex) - 1);
  return generate(0);
}

string genRegex(int k)
{
  if (k == 1)
  {
    string s;
    if (rand() % 2 == 0)
      s.push_back('a');
    else
      s.push_back('b');
    return s;
  }

  string s;
  int x = rand() % 3;
  if (x == 0)
  {
    s = genRegex(k - 1);
    s = "(" + s + "*)";
  }
  else
  {
    int f = 1 + rand() % (k - 1);
    int se = k - f;
    string s1 = genRegex(f);
    string s2 = genRegex(se);
    if (x == 1)
      s = "(" + s1 + s2 + ")";
    else
      s = "(" + s1 + "|" + s2 + ")";
  }
  return s;
}

void generate2()
{
  char in[10] = "in .txt";
  for (int test = 1; test < 10; test++)
  {
    in[2] = test + '0';
    FILE *fout = fopen(in, "w");

    int runs = 50;

    fprintf(fout, "%d\n", runs);
    for (int t = 0; t < runs; t++)
    {
      int k = 28 - rand() % 10;
      string s = genRegex(k);
      if (s.size() > 100)
        while (1)
          ;
      int L = rand() % 1000000000 + 1;
      fprintf(fout, "%s %d\n", s.c_str(), L);
    }
  }
}

void test()
{
  for (int t = 0; t < 100; t++)
  {
    string s = genRegex(15);
    cout << s << endl;
    int L = rand() % 12 + 5;
    char reg[MAXN] = {};
    for (int i = 0; i < s.size(); i++)
      reg[i] = s[i];
    int ret1 = solve(reg, L);
    int ret2 = solve2(reg, L);
    cout << ret1 << " " << ret2 << endl;
    if (ret1 != ret2)
    {
      cout << "Failed on: " << s << endl;
      while (1)
        ;
    }
  }
}

int pow2(int k)
{
  if (k == 0)
    return 1;
  int ret = pow2(k / 2);
  ret = 1LL * ret * ret % MOD;
  if (k & 1)
    ret = 1LL * ret * 2 % MOD;
  return ret;
}

int countStrings(string r, int l)
{
  int n = r.length();
  char a[n];
  for (int i = 0; i < n; i++)
    a[i] = r[i];
  return solve(a, l);
}

int main()
{
  vector<char *> r = {
      "((ab)|(ba))", "((a|b)*)", "((a*)(b(a*)))"};

  vector<int> l = {2, 5, 100};
  // char test_1[13] ="((ab)|(ba)) 2"
  // char test_2[10] ="((a|b)*) 5"
  // char test_3[17] ="((a*)(b(a*))) 100"
  cout << "test case (1 ~ 3): ";
  int t;
  cin >> t;
  cout << solve(r[t], l[t]);
  return 0;
}
