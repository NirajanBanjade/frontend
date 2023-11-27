#include "Movestack.h"
#include <iostream>

using namespace std;

int main(){

    Movestack tik;
    tik.push(Move(1,2));
    tik.push(Move(4,5));
    
    
    tik.pop();
    Move topE=tik.top();
    cout<<topE.x<<" "<<topE.y<<endl;

    cout<<tik.getSize()<<endl;


    return 0;
}