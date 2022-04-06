#include<iostream>
#include<algorithm>
#include<string>
#include<map> 

using namespace std;
const int MAXN=11;

int main(){
	string hexs[MAXN];
	string bins[MAXN];
	string octs[MAXN];
	int n;
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>hexs[i];
	} 
	//map
	string htob[16]={"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
	"1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
	map<string, string> bin_oct;
	bin_oct["000"]="0";
	bin_oct["001"]="1";
	bin_oct["010"]="2";
	bin_oct["011"]="3";
	bin_oct["100"]="4";
	bin_oct["101"]="5";
	bin_oct["110"]="6";
	bin_oct["111"]="7";
	for (int i=0; i<n; ++i){
		//hex to bin
		string bin="";
		for (int j=0; j<hexs[i].length(); ++j){
			if (hexs[i][j]>'9') bin+=htob[hexs[i][j]-'A'+10];
			else bin+=htob[hexs[i][j]-'0'];
		}
		if (bin.length()%3==1) bin="00"+bin;
		else if (bin.length()%3==2) bin="0"+bin;
		//bin to oct
		string oct="";
		int start=0;
		if (bin.substr(start,3)=="000") start+=3;
		while(start+2<bin.length()){
			oct+=bin_oct[bin.substr(start,3)];
			start+=3;
		}
		cout<<oct<<endl;
	}
	
	return 0;
}
	
	
	
	
