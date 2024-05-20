#include<bits/stdc++.h>
using namespace std;
int w,b;
string s="";
int main(){
	cin>>w>>b;
	for(int i=1;i<=20;i++) s+="wbwbwwbwbwbw";
	for(int i=0;i<240;i++){
		for(int j=i;j<240;j++){
			int numw=0,numb=0;
			for(int k=i;k<=j;k++){
				if(s[k]=='w') numw++;
				else numb++;
			}
			if(numw==w&&numb==b){
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}