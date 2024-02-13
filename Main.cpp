#include <iostream>
#include <iomanip>
#include <numeric>

using namespace std;
using std::setw;
using std::left;

struct duom{
    string vard;
    string pav;
    int n;
    int ndrez[20];
    int egzrez;
};

void input(duom mokinys[], int j){
    // freopen("duota.txt", "r", stdin);

    cout<<"Irasykite varda"<<endl;
    cin>>mokinys[j].vard;
    cout<<"Irasykite pavarde"<<endl;
    cin>>mokinys[j].pav;
    cout<<"Irasykite namu darbu skaiciu"<<endl;
    cin>>mokinys[j].n;
    if(mokinys[j].n!=0){
        cout<<"Irasykite nd rezultatus po kiekvieno spaudziant enter"<<endl;
        for(int i=0; i<mokinys[j].n; i++){
            cin>>mokinys[j].ndrez[i];
        }
    }
    cout<<"Irasykite egzamino rezultata"<<endl;
    cin>>mokinys[j].egzrez;

    return;
}

void calc(duom mokinys[], int j){
    double sum=0;
    double egz=0;
    if(mokinys[j].n!=0){
        for(int i=0; i<mokinys[j].n; i++){
            sum+=mokinys[j].ndrez[i];
        }
        sum=sum/mokinys[j].n;
    }
    egz=mokinys[j].egzrez;
    cout<<setw(17)<<left<<mokinys[j].vard<<setw(17)<<left<<mokinys[j].pav<<setw(17)<<left<<(sum*0.4+egz*0.6)<<endl;
}

int main(){    
    int x;

    cout<<"Irasykite mokiniu skaiciu"<<endl;
    cin>>x;

    duom mokinys[x+1];

    for(int i=0; i<x; i++){
        input(mokinys, i);
    }

    cout<<setw(17)<<left<<"Vardas"<<setw(17)<<left<<"Pavarde"<<setw(17)<<left<<"Galutinis (Vid.)"<<endl;
    cout<<"-------------------------------------------------------"<<endl;

    for(int i=0; i<x; i++){
        calc(mokinys, i);
    }

    return 0;
}