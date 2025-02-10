#include <iostream>
using namespace std;
int main(){
    int num = 12;
    int *ptr = &num;
    int **dptr = &ptr;

    int &ref = num;
    int *(&pref) = ptr;
    int **(&dpef) = dptr;

    cout<<ref<<endl;
    cout<<*pref<<endl;
    cout<<**dpef<<endl;
    return 0;
}   