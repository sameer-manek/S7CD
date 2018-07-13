#include "iostream"
#include "string"

using namespace std;

string validator(string s){
	string l[] = {"&&", "||", "!"};
	string A[] = {"+", "-", "/", "*", "%", "^"};
	for(int i=0; i<sizeof(l); i++){
		if(l[0] == s){
			return "logical";
		}
	}
	for(int i=0; i<sizeof(A); i++){
		if(A[0] == s){
			return "Arithmatic";
		}
	}
	return "sorry, that operator is not in our list";
}

int main(){
	cout<<"please give any operator: ";
	string s;
	cin>>s;
	cout<<validator(s)<<endl;
	return 0;
}
