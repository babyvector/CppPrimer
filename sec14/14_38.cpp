#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class LenCompare{

public:
    int operator()(const string& lhs){
        return lhs.length();
    }

};

int main(){

    fstream infile("english_articles.txt");
    string line_string;
    vector< vector<string> > sorted_string_vec;
    for(int i = 0; i< 11; i++)
    {
        sorted_string_vec.push_back( *(new vector<string>()) );

    }

    LenCompare str_cmp;
    int short_string = 0;
    int long_string = 0;

    while(getline(infile, line_string))
    {
        stringstream sstring(line_string);
        string tmp;
        while(sstring >> tmp){
            int ret = str_cmp(tmp);
            if(ret < 11)
            {
                sorted_string_vec[ret].push_back(tmp);
                short_string++;
            }else
            {
                long_string++;
            }
            
                
        }
    }

    cout<<"ans for 14.38:"<<endl;
    for(auto item:sorted_string_vec)
    {
        cout<<item.size()<<endl;
    }
    cout<<"ans for 14.39:"<<endl;
    cout<<"string len less or equal 10 is:"<<short_string<<endl;
    cout<<"string len bigger 10 is:"<<long_string<<endl;
    return 0;
}