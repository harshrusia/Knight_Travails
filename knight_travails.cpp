#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
#define F first
#define S second

int dx[] = {2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,1,-1,2,2,-2,-2};

void grid(int x,int y){
    for(int i=1;i<=8;i++){
        cout<<"   ";
        for(int j=1;j<=8;j++)
            cout<<"+---";
        cout<<"+\n";
        cout<<9-i<<"  ";
    
        for(int j=1;j<=8;j++){
            if(x == i && y == j)
               cout<<"| • ";
            else
               cout<<"|   ";
        }
        cout<<"|\n";
    }
    cout<<"   ";
    for(int j=1;j<=8;j++)
        cout<<"+---";
    cout<<"+\n";
    cout<<"     A   B   C   D   E   F   G   H";
}

int dist[9][9];
vector<vector<pii>> par(9,vector<pii>(9));
vector<pii> ans;

bool check(int x,int y){
    if(x>=1 && x<9 && y>=1 && y<9)return 1;
    return 0;
}

void bfs(pii source){
    queue<pii> q;
    q.push(make_pair(source.F,source.S));
    dist[source.F][source.S] = 0;
    
    while(!q.empty()){
        pii curr = q.front();
        q.pop();
        
        for(int i=0;i<8;i++){
            int x = curr.F + dx[i];
            int y = curr.S + dy[i];
            
            if(check(x,y) && dist[x][y] > dist[curr.F][curr.S] + 1){
                par[x][y] = make_pair(curr.F,curr.S);
                dist[x][y] = dist[curr.F][curr.S] + 1;
                q.push(make_pair(x,y));
            }
        }
    }
}

int main(){
    string st,en;
    int stx,sty,enx,eny;
    cout<<"Enter the starting position of Knight ";
    cin>>st;
    cout<<"Enter the ending position of Knight: ";
    cin>>en;
    
    stx = 9 - st[1] + '0',sty = st[0]-'A'+1;
    enx = 9 - en[1] + '0',eny = en[0]-'A'+1;
    
    pii source = make_pair(stx,sty);
    
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            dist[i][j] = 1e9;
    
    bfs(source);
    
    while(dist[enx][eny]){
        ans.push_back(make_pair(enx,eny));
        int temp = enx;
        enx = par[enx][eny].F;
        eny = par[temp][eny].S;
    } 
    
    reverse(ans.begin(),ans.end());
    
    cout<<"First we start with "<<st<<"\n";
    grid(stx,sty);
    
    for(auto v:ans){
        char c = v.S + 'A' - 1;
        int temp = 9 - v.F;
        cout<<"Then we move to "<<c<<temp<<"\n";
        grid(v.F,v.S);
        cout<<"\n";
    } 
    
    return 0;
}