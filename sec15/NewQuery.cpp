#include "15_35_NewQuery.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream infile("english_articles.txt");
    cout<<"Step into NewQuery."<<endl;
    Query q = ( Query("that") & Query("satisfy") | Query("howw"));
    
    //print(cout, q.eval(TextQuery(infile)))<<endl;
    cout<<q<<endl;
    cout<<"Step out NewQuery."<<endl;
    return 0;
}

