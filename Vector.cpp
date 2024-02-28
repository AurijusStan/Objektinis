// #include <iostream>
// #include <iomanip>
// #include <numeric>
// #include <vector>
// #include <random>
// #include <string>
// #include <chrono>

#include "funkcijos.h"

using namespace std;
using std::setw;
using std::left;

int main(){    
    vector<duom> mok;

    double duration=0;

    int moksk=-1;

    input(moksk, mok, duration);

    cout<<setw(19)<<left<<"Vardas"<<setw(19)<<left<<"Pavarde"<<setw(19)<<left<<"Galutinis (Vid.)"<<setw(19)<<left<<"Galutinis (Med.)"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

    for(int i=0; i<moksk; i++){
        cout<<setw(19)<<left<<mok[i].vard<<setw(19)<<left<<mok[i].pav<<setw(19)<<left<<setprecision(3)<<mok[i].galvid<<setw(19)<<left<<setprecision(3)<<mok[i].galmed<<endl;
    }

    cout<<duration;
    
    return 0;
}