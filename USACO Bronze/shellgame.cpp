#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  freopen("shell.in","r",stdin);
  freopen("shell.out","w",stdout);
  int n;
  cin>>n;
  int z=n;
  int a[3] = {1,2,3};
  vector<int>p;
  int x,y,pos;
  int guess1=0;
  int guess2=0;
  int guess3=0;
  while(z--){
    cin>>x>>y>>pos;
    swap(a[x-1],a[y-1]);
    p.push_back(a[pos-1]);
  }
  while(n--){
    if(p[n]==1){
      guess1++;
    }
    else if(p[n]==2){
      guess2++;
    }
    else{
      guess3++;
    }
  }
  int guesses[3] = {guess1,guess2,guess3};
  sort(guesses,guesses+3);
  cout<<guesses[2]<<"\n";
  return 0;
}