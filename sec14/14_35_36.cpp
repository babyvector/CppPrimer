#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PrintString{

public:
    string operator()(istream& os){
        string tmp;
        os>>tmp;
        return tmp;
    }
private:

};

int main(){

    PrintString ps;
    vector<string> svec;
    string tmp_s;
    cout<<"test class PrintString:"<<endl;
    while( (tmp_s = ps(cin) ) != "")
        svec.push_back( tmp_s );

    for(auto item:svec)
        cout<<item<<endl;
    return 0;
}