#include<bits/stdc++.h>
using namespace std;
int solve(int s){
if(s==0)
return 0;
int ans = 1000;
if(s>=1){
cout<<"in 1"<<"\n";
ans = std::min(ans,1+solve(s-1));

}
if(s>=3){
cout<<"in 3"<<"\n";
ans = std::min(ans,1+solve(s-3));

}
if(s>=4){
cout<<"in 4"<<"\n";
ans = std::min(ans,1+solve(s-4));

}
if(s>=5){
cout<<"in 5"<<"\n";
ans = std::min(ans,1+solve(s-5));

}
return ans;
}
int main(){
printf("%d",solve(7));
return 0;
}


