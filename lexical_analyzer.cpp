#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

struct Token
{
	string type;
	string value;
};

char operators[] = {'=', '-', '+', '*', '/'};

vector<Token> tokens;

// remove white space
string RWS(string s){
	char space = ' ';
	int x = sizeof(s);
	for(int i = 0; i < x; i++){
		if(s[i] == space){
			for(int j = i+1; j < x; j++){
				s[i] = s[j];
			}
			x--;
		}
	}

	return s;
}

// operation to seperate create string blocks
void distill(string s){
	string buf;
	// todo : Create tokens
	for(int i = 0; i < sizeof(s); i++){
		bool flag = true;
		for(int j = 0; j < sizeof(operators); j++){
			if(s[i] == operators[j]){
				flag = false;
			}
		}
		
		if(!flag){
			if(sizeof(buf) <= 0){
				throw "Unexpected token";
				break;
			} else{
				Token t;
				t.value = buf;
				t.type = "id";

				tokens.push_back(t);
				buf.empty();
			}
		}

		// add the s[i] to buf

		buf += buf + s[i];
	}
}

void scanner(string s){
	s = RWS(s);
	distill(s);
	cout<<endl;
	for(vector<Token>::iterator x = tokens.begin(); x != tokens.end(); ++x){
		cout<<x->value<<endl;
	}
}

int main(){
	string s;
	cout<<"enter an expression: ";
	getline(cin, s);
	scanner(s);
	return 0;
}