#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#define M 4
#define N 4
using namespace std;

class Trie{
private:
	class Node{
	public:
		char az;
		bool word;
		Node* c26[26];
		Node(){
			az = 0;
			for (int i = 0; i < 26; i++)
				c26[i] = NULL;
			word = false;
		}
		void Add_char(char c, Node* node, int i){
			int pos = c - i;
			if (node->c26[pos] != NULL)
				return;
			Node* temp = new Node();
			temp->az = c;
			node->c26[pos] = temp;
		}
	};
	Node* Head;
public:
	Trie(){
		Head = new Node();
	}
	int define_word(char c){
		int i;
		if (c >= 65 && c <= 90)
			i = 65;
		if (c >= 97 && c <= 122)
			i = 97;
		return i;
	}
	void Word_FInd(const string& s){
		Node* current;
		int t;
		const char *s1 = s.c_str();
		current = Head;
		for (unsigned int i = 0; i < s.size(); i++){
			t = define_word(s1[i]);
			current->Add_char(s1[i], current, t);
			current = current->c26[s1[i] - t];
		}
		current->word = true;
	}
	bool word(const string& s){
		Node* current;
		int t;
		const char *s1 = s.c_str();
		current = Head;
		for (unsigned int i = 0; i < s.size(); i++){
			t = define_word(s1[i]);
			if (current->c26[s1[i] - t] == NULL)
				return false;
			current = current->c26[s1[i] - t];
		}
		if (current->word)
			return true;
		else
			return false;
	}

	void findWords_Print(char boggle[M][N], bool visited[M][N], int i, int j, string &str){
		visited[i][j] = true;
		str = str+ boggle[i][j];
		if (word(str)){
			if(str.size()>2 ) {
			cout << str << endl;
			 }
		}
		for (int row=i-1; row<=i+1 && row<M; row++)
		  for (int col=j-1; col<=j+1 && col<N; col++)
			if (row>=0 && col>=0 && !visited[row][col])
			  findWords_Print(boggle,visited, row, col, str);

		str.erase(str.length()-1);
		visited[i][j] = false;
	}
	void findWords(char boggle[M][N]){
		bool visited[M][N] = {{false}};
		string str = "";
		for (int i=0; i<M; i++)
		   for (int j=0; j<N; j++)
				 findWords_Print(boggle, visited, i, j, str);
	}
};
int main(){
	Trie word;
	string line;
	fstream file;
	file.open("dictionary.txt", ios::in);
	if (!file.is_open()) {
		cout << "Unable to open Dictionay :) \n" << endl;
	}
		while (getline(file, line)) {
	   word.Word_FInd(line);
	}
	file.close();
    char boggle[M][N] = {{'a','e','t','m'},
                         {'s','n','i','a'},
                         {'e','r','f','o'},
                         {'b','a','t','i'}};

    cout << "Following words are present in dictionary\n";
    word.findWords(boggle);
    return 0;
}
