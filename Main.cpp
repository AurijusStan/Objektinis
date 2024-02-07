#include <iostream>

using namespace std;

struct duom{
    string vard;
    int n;
    double ndrez[ndkiek];
    double egzrez;
};

int main(){
    freopen("duota.txt", "r", stdin);

    int x;

    cout<<"Įrašykite mokinių skaičių";
    cin>>x;

    duom mokinys[x+1];

    cout<<"Įrašykite vardą ir pavardę";
    cin>>mokinys.vard;
    cout<<"Įrašykite namų darbų skaičių";
    cin>>mokinys.n;
    cout<<"Įrašykite nd rezultatus po kiekvieno spaudžiant enter";
    for(int i=0; i<n; i++){
        cin>>mokinys.ndrez[i];
    }
    cout<<"Įrašykite egzamino rezultatą";
    cin>>mokinys.egzrez;
}