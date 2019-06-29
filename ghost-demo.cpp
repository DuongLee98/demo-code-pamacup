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
Location ghost[5];
vector<Location> tunnel;
char seePacman;
Location pacman;
char seeMarkPacman;
int iMarkPacman;
Location markpacman;

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
    for (int i=1; i<=3; i++)
    {
        cin>>ghost[i].y>>ghost[i].x;
    }
    cin>>seePacman;
    if (seePacman == 'Y')
        cin>>pacman.y>>pacman.x;
    cin>>seeMarkPacman;
    if (seeMarkPacman == 'Y')
        cin>>iMarkPacman>>markpacman.y>>markpacman.x;
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
        int ym = ghost[1].y+ye[k];
        int xm = ghost[1].x+xe[k];
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
    srand(time(NULL));
    read();
    process();
    sol();
    return 0;
}
