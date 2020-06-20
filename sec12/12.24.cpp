#include<iostream>
#include<vector>
#include<memory>
#include<string>

using namespace std;
#define STEP_SIZE 10

pair<char*, int> realloc(char* old_src, size_t old_size){
    
    char* tmp = new char[old_size+STEP_SIZE+1];
    memmove(tmp, old_src, old_size);
    delete [] old_src;
    return {tmp, old_size+STEP_SIZE};

}

int main(){
    /*getchar是从缓冲区中一个一个读取字符串*/
    int size = STEP_SIZE;
    char *cont = new char[size];
    char c;
    int cnt = 0;
    while( (c = cin.get()) != EOF){

        if(cnt >= size){
            
            auto rval = realloc(cont, size);
            cont = rval.first;
            size = rval.second;
            
            //make_pair(&cont,size) = realloc(&cont, size);
        }
        cont[cnt] = c;
        cnt++;
    
    }
    cont[cnt] = '\0';
    cout<<"the final output string is:"<<cont<<endl;
    return 0;
}