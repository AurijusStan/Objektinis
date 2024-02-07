#include <iostream>
#include <iomanip>
#include <numeric>

using namespace std;
using std::setw;
using std::left;

struct duom{
    string vard;
    int n;
    int ndrez[20];
    int egzrez;
};

void input(duom mokinys[], int j){
    // freopen("duota.txt", "r", stdin);

    cout<<"Įrašykite vardą ir pavardę";
    cin>>mokinys[j].vard;
    cout<<"Įrašykite namų darbų skaičių";
    cin>>mokinys[j].n;
    cout<<"Įrašykite nd rezultatus po kiekvieno spaudžiant enter";
    for(int i=0; i<mokinys[j].n; i++){
        cin>>mokinys[j].ndrez[i];
    }
    cout<<"Įrašykite egzamino rezultatą";
    cin>>mokinys[j].egzrez;

    return;
}

void calc(duom mokinys[], int j){
    if(mokinys[j].n!=0){
        std::accumulate
    }

}

int main(){    
    int x;

    cout<<"Įrašykite mokinių skaičių";
    cin>>x;

    duom mokinys[x+1];

    for(int i=0; i<x; i++){
        input(mokinys, i);
    }

    cout<<setw(7)<<left<<"Vardas"<<"Pavardė"<<"Galutinis (Vid.)"<<endl;
    cout<<"------------------------------------------------";

    for(int i=0; i<x; i++){
        calc(mokinys, i);
    }

    return 0;
}