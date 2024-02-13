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
    cout<<"Irasykite varda"<<endl;
    cin>>mokinys[j].vard;
    cout<<"Irasykite pavarde"<<endl;
    cin>>mokinys[j].pav;
    while(true){
        cout<<"Irasykite namu darbu skaiciu"<<endl;
        if(cin>>mokinys[j].n) break;
        else{
            cin.clear();
            cin.ignore();
            cout<<"Klaidingai ivesti duomenys"<<endl;
        }
    }
    if(mokinys[j].n!=0){
        cout<<"Irasykite nd rezultatus po kiekvieno spaudziant enter"<<endl;
        for(int i=0; i<mokinys[j].n; i++){
            while(true){
                if(cin>>mokinys[j].ndrez[i]) break;
                else{
                    cin.clear();
                    cin.ignore();
                    cout<<"Klaidingai ivesti duomenys, iveskite sveika skaiciu"<<endl;
                }
            }
            while(mokinys[j].ndrez[i]<0||mokinys[j].ndrez[i]>10){
                cout<<"Ivertinimas turi buti desimtbaleje sistemoje, pabandykite dar karta"<<endl;
                while(true){
                    if(cin>>mokinys[j].ndrez[i]) break;
                    else{
                        cin.clear();
                        cin.ignore();
                        cout<<"Klaidingai ivesti duomenys, iveskite sveika skaiciu"<<endl;
                    }
                }
            }
        }
        sort(mokinys, j);
    }
    while(true){
        cout<<"Irasykite egzamino rezultata"<<endl;
        if(cin>>mokinys[j].egzrez) break;
        else{
            cin.clear();
            cin.ignore();
            cout<<"Klaidingai ivesti duomenys"<<endl;
        }
    }
    while(mokinys[j].egzrez<0||mokinys[j].egzrez>10){
        cout<<"Ivertinimas turi buti desimtbaleje sistemoje, pabandykite dar karta"<<endl;
        while(true){
            if(cin>>mokinys[j].egzrez) break;
            else{
                cin.clear();
                cin.ignore();
                cout<<"Klaidingai ivesti duomenys, iveskite sveika skaiciu"<<endl;
            }
        }
    }

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

    while(true){
        cout<<"Irasykite mokiniu skaiciu"<<endl;
        if(cin>>x) break;
        else{
            cin.clear();
            cin.ignore();
            cout<<"Klaidingai ivesti duomenys"<<endl;
        }
    }

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