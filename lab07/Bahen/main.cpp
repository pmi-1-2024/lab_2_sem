
#include "functions.h"
using namespace std;

int main(){
    try{
        DefaultTransport ** list = new DefaultTransport*[1];
        read("data.txt",list);
        return 0;
    }
    catch(const char* exception){
        cerr << "Error: " << exception << endl;
    }
}