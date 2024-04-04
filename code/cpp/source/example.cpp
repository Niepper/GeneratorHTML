#include <iostream>

#ifdef _WIN32
#define def __declspec(dllexport)
#else
#define def
#endif


extern "C"
{
    def int add(int a, int b){
        return (a + b);
    }
    def int substract(int a, int b){
        return (a - b);
    }

}