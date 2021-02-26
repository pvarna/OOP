#include <iostream>
#include <new>
using std::nothrow;

int main(){
    long long int n = 100000000000;
    long long* test=new (nothrow) long long [n];
    if(!test){
        std::cout<< "oops!" << std::endl;
    }

    //test[0] = 1;

    delete[] test;
    return 0;
}