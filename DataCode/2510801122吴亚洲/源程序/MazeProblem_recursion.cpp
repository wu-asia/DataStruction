
#include<iostream>
#include<vector>

using namespace std;

struct node
{
    int x, y;
};
const int N = 105;
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int maze[N][N];
int st[N][N];
vector<node> path;
bool dfs(int x, int y)
{
    if(x == n && y == m)
    {
        for(auto e : path)
        {
            cout << "(" << e.x << ", " << e.y << ")" << endl;
        }
        return true;
    }
    for(int i = 0; i < 4; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if(a < 1 || b < 1 || a > n || b > m || st[a][b] || maze[a][b] == 1)
            continue;
        st[a][b] = true;
        path.push_back({a, b});
        if(dfs(a, b)) return true;
        st[a][b] = false;
        path.pop_back();
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> maze[i][j];
    if(!dfs(1, 1))
        cout << "false" << endl;
    return 0;
}