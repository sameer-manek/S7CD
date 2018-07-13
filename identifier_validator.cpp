#include "iostream"
#include "string"

using namespace std;

/*
	check if string entered is a valid identifier
	valid string starts with '_' or aphabet AND has no white spaces
*/

int validator(string s){
	char c = s[0];
	if(c == '_' || ((int)c > 96 && (int)c<123) || ((int)c > 64 && (int)c < 92)){
		// check for spaces
		for(int i = 0; i < sizeof(s); i++){
			if((int)s[i] == 32 ){
				cout<<s[i]<<endl;
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int main(){
	char s[100];
	cout<<"please provide a string: ";
	cin.getline(s, sizeof(s)); // to fetch complete strings (with space) as input
	if(validator(s) == 1){
		cout<<"valid identifier"<<endl;
	} else{
		cout<<"not valid"<<endl;
	}
	return 0;
}
