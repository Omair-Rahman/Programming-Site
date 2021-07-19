#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

char Map[100][100];
int a,b,I,K,next[10][10]= {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

void BFS(int x,int y,int xmax,int ymax)
{
    int px,py,nx,ny,land;
    queue<int>q;
    Map[x][y]='w';
    q.push(x);
    q.push(y);
    while(!q.empty())
    {
        px=q.front();
        q.pop();
        py=q.front();
        q.pop();
        for(int i=0; i<8; i++)
        {
            nx=px+next[i][0];
            ny=py+next[i][1];
          //  cout<<nx<<' '<<ny<<endl;
            if(x<=xmax&&nx>=0&&ny>=0&&ny<=ymax&&Map[nx][ny]=='l')
            {
                Map[nx][ny]='w';
                q.push(nx);
                q.push(ny);
            }
        }

//    for(I=0; I<a; I++)
//    {
//        for(K=0; K<b; K++)
//        {
//            cout<<Map[I][K];
//        }
//        cout<<endl;
//    }
}
}

int main()
{
    int land=0;
    cin>>a>>b;
    for(I=0; I<a; I++)
    {
        for(K=0; K<b; K++)
        {
            cin>>Map[I][K];
        }
    }
     for(I=0; I<a; I++)
    {
        for(K=0; K<b; K++)
        {

            if(Map[I][K]=='l')
            {
                BFS(I,K,a,b);
                land++;
            }
        }
    }

   cout<<land<<endl;

    return 0;
}
