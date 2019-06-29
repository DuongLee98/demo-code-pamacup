#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
struct Location
{
    int y, x;
};

int r, c;
char pmap[50][50];
Location pacman;
Location ghost[5];
vector<Location> tunnel;

void read()
{
    cin>>r>>c;
    for (int i=1; i<=r; i++)
    {
        for (int j=1; j<=c; j++)
        {
            cin>>pmap[i][j];
            if (pmap[i][j] == 'o')
            {
                Location tmp;
                tmp.y = i;
                tmp.x = j;
                tunnel.push_back(tmp);
            }
        }
    }
    cin>>pacman.y>>pacman.x;
    for (int i=1; i<=3; i++)
    {
        cin>>ghost[i].y>>ghost[i].x;
    }
}

bool check(int y, int x)
{
    if (x>=1 && x<=c && y>=1 && y<=r && pmap[y][x] != '#')
        return true;
    return false;
}

int xe[] = {-1, +0, +1, +0};
int ye[] = {+0, +1, +0, -1};
vector<Location> rd;
void process()
{
    for (int k=0; k<4; k++)
    {
        int ym = pacman.y+ye[k];
        int xm = pacman.x+xe[k];
        if (check(ym, xm))
        {
            Location tmp;
            tmp.y = ym;
            tmp.x = xm;
            rd.push_back(tmp);
        }
    }
}

void sol()
{
    // cout<<rd.size();
    Location rs;
    rs = rd[rand()%rd.size()];
    cout<<rs.y<<" "<<rs.x;
}

int main()
{
    srand (time(NULL));
    read();
    process();
    sol();
    return 0;
}
