#include "15_42_NewQuery_b.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream infile("pride-and-prejudice.txt");
    cout<<"Step into NewQuery."<<endl;
    Query q = ( Query("that") & Query("you") | Query("howw"));
    Query_history history;
    history.add_query(q);
    cout<<"the history 0 is:"<<history[0]<<endl;
    Query x = history[0] & Query("are");

    history.add_query(x);
    cout<<"the history 1 is:"<<history[1]<<endl;
    print(cout, x.eval(TextQuery(infile)))<<endl;
    cout<<"Step out NewQuery."<<endl;

    int * s = 0;
    int *ss = 0;
    int*& p = s;
    int*& qq = ss;
    qq = p;
    
    /*
        注意这个题在实现
     */

    return 0;
}

