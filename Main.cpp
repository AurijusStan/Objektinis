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

void sort(duom mokinys [], int k){
    for(int i=0; i<mokinys[k].n-1; i++){
        for(int j=i+1; j<mokinys[k].n; j++){
            if(mokinys[k].ndrez[i]>mokinys[k].ndrez[j]) swap(mokinys[k].ndrez[i], mokinys[k].ndrez[j]);
        }
    }
}

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
        sort(mokinys, j);
    }
    cout<<"Irasykite egzamino rezultata"<<endl;
    cin>>mokinys[j].egzrez;

    return;
}

void calc(duom mokinys[], int j){
    double sum=0;
    double egz=0;
    double med=0;
    if(mokinys[j].n!=0){
        for(int i=0; i<mokinys[j].n; i++){
            sum+=mokinys[j].ndrez[i];
        }
        sum=sum/mokinys[j].n;
        if(mokinys[j].n%2==0){
            med=(mokinys[j].ndrez[mokinys[j].n/2]+mokinys[j].ndrez[(mokinys[j].n/2)+1])/2;
        }
        else{
            med=mokinys[j].ndrez[(mokinys[j].n+1)/2];
        }
    }
    egz=mokinys[j].egzrez;
    cout<<setw(17)<<left<<mokinys[j].vard<<setw(17)<<left<<mokinys[j].pav<<setw(17)<<left<<setprecision(3)<<(sum*0.4+egz*0.6)<<setw(17)<<left<<setprecision(3)<<(med*0.4+egz*0.6)<<endl;
}

int main(){    
    int x;

    cout<<"Irasykite mokiniu skaiciu"<<endl;
    cin>>x;

    duom mokinys[x+1];

    for(int i=0; i<x; i++){
        input(mokinys, i);
    }

    cout<<setw(17)<<left<<"Vardas"<<setw(17)<<left<<"Pavarde"<<setw(17)<<left<<"Galutinis (Vid.)"<<setw(17)<<left<<"Galutinis (Med.)"<<endl;
    cout<<"---------------------------------------------------------------"<<endl;

    for(int i=0; i<x; i++){
        calc(mokinys, i);
    }

    return 0;
}