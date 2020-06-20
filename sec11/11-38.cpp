#include<iostream>
#include<fstream>
#include<sstream>
#include<unordered_map>
#include<string>
using namespace std;

void word_transform(ifstream &map_file, ifstream &input){
	unordered_map<string, string>mapping;
	string line;
	string word_s;
	string word_p;
	while(getline(map_file, line)){
		stringstream words_line(line);
		while(words_line>>word_s && words_line>>word_p){
			mapping[word_s] = word_p;
		}
	}
	while(getline(input,line)){
		stringstream words_line(line);
		while(words_line>>word_s){
			if(mapping.find(word_s) != mapping.end()){
				word_s = mapping[word_s];
			}
			cout<<word_s<<" ";
		}
		cout<<endl;
	}
	
	
}
int main(){
	
	unordered_map<string, size_t> word_count;
	string word;
	while(cin>>word){
		if(word == "exit")
			break;
		++word_count[word];
	}
	for(const auto &w : word_count){
		cout<< w.first <<" occurs "<<w.second
			<<(w.second >1 ? " times" :" time")<<endl;
	}
	ifstream map_file("map_file.txt");
	ifstream input("input.txt");
	word_transform(map_file, input);
	return 0;
}
