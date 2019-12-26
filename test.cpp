#include<bits/stdc++.h>
using namespace std;
#define x 'x'
#define o 'o'
#define e ' '
string instruction = "This is a simple tic-tac-toe game.\nThe grid is indexed as follows to fill in a grid simply provide the box number and 'x' or 'o'\n";
string howtoplay = "To play your turn simply provide index of the square tile to fill. First player will take X and second player will get O";
string error="Already filled! Please chose another tile.";
vector<int> r,c;
int diag1=0;
int diag2=0;
int turns=0;
int player=1;
vector<char> grid(9, ' ');

void toggle(){
    player+=9;
    player%=18;
}

void print(){
    for(int i=0; i<3; i++){
        for(int j=0; j<7; j+=3){
            if(j==6){cout<<" "<<grid[i+j]; continue;}
            cout<<" "<<grid[i+j]<<" |";
        }
        cout<<endl;
        if(i==2) continue;
        for(int k=0; k<3; k++){
            cout<<"---"<<" ";
        }
        cout<<endl;
    }
}

void print(vector<char> &grid){
    for(int i=0; i<3; i++){
        for(int j=0; j<7; j+=3){
            if(j==6){cout<<" "<<grid[i+j]; continue;}
            cout<<" "<<grid[i+j]<<" |";
        }
        cout<<endl;
        if(i==2) continue;
        for(int k=0; k<3; k++){
            cout<<"---"<<" ";
        }
        cout<<endl;
    }
}

void begin(){
    turns=0;
    grid.resize(0);
    grid.resize(9,' ');
    r.resize(0);
    r.resize(3,0);
    c.resize(0);
    c.resize(3,0);
    diag1=0;
    diag2=0;
    player=1;

    vector<char> k(9);
    //instructions 
    cout<<instruction<<endl<<howtoplay<<endl;
    for(int i=0; i<9; i++){
        k[i]=i+'0';
    }
    print(k);
    cout<<endl;
    return;
}

void play_turn(int index){
    int k=index%3;
    int l=index-k;
    l/=3;
    r[k]+=player;
    c[l]+=player;
    if(index%2==0){
        if(l+k==2) diag1+=player;
        if(l==k) diag2+=player;
    }
    grid[index]=player+110;
    cout<<endl;
    print();
    cout<<endl;
    turns++;
}

bool checkcell(int index){
    int k=index%3;
    int l=index-k;
    l/=3;
    int val=3*player;
    if(r[k]==val) return true;
    if(c[l]==val) return true;
    if(index%2==0){
        if(l==k && diag2==val) return true;
        if(l+k==2 && diag1==val) return true;
    } 
    return false;
}

int main(){
    char keep_playing = 'y';
    while(keep_playing == 'y'){
        begin();
        int i=9;
        while(turns<9){
        cout<<"Player "<<char(player+110)<<": ";
            cin>>i;
            while(grid[i]!=e){
                cout<<error<<endl;
                cout<<"Player "<<char(player+110)<<": ";
                cin>>i;
            }
            play_turn(i);
            if(checkcell(i)) {cout<<"Player "<<char(player+110)<<" wins!!!\n"; break;}
            toggle();
        }
        cout<<"Do you still want to continue?(y/n)"<<endl;
        cin>>keep_playing;
    }

}
