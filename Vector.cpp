#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>

using namespace std;
using std::setw;
using std::left;

struct duom{
    string vard;
    string pav;
    int n=-1;
    vector<int> ndrez;
    int egzrez;
};

vector<duom> mok;

void sort(int k){
    for(int i=0; i<mok[k].n+1; i++){
        for(int j=i+1; j<mok[k].n+1; j++){
            if(mok[k].ndrez[i]>mok[k].ndrez[j]) swap(mok[k].ndrez[i], mok[k].ndrez[j]);
        }
    }
}

void input(int &kiek){
    mok.push_back(duom());
    kiek++;

    cout<<"Irasykite varda"<<endl;
    cin>>mok[kiek].vard;
    cout<<"Irasykite pavarde"<<endl;
    cin>>mok[kiek].pav;

    cout<<"Irasykite nd rezultatus po kiekvieno spaudziant enter, jei baigete parasykite skaiciu netelpanti i desimtbales sistemos intervala"<<endl;
    while(true){
        mok[kiek].ndrez.push_back(0);
        mok[kiek].n++;
        while(true){
            if(cin>>mok[kiek].ndrez[mok[kiek].n]) break;
            else{
                cin.clear();
                cin.ignore();
                cout<<"Klaidingai ivesti duomenys, iveskite sveika skaiciu"<<endl;
            }
        }
        if(mok[kiek].ndrez[mok[kiek].n]<0||mok[kiek].ndrez[mok[kiek].n]>10){
            mok[kiek].ndrez.pop_back();
            mok[kiek].n--;
            break;
        }
    }

    sort(kiek);

    for(int i=0; i<mok[kiek].n+2; i++){
        cout<<mok[kiek].ndrez[i]<<" ";
    }
    cout<<endl;

    while(true){
        cout<<"Irasykite egzamino rezultata"<<endl;
        if(cin>>mok[kiek].egzrez) break;
        else{
            cin.clear();
            cin.ignore();
            cout<<"Klaidingai ivesti duomenys"<<endl;
        }
    }
    while(mok[kiek].egzrez<0||mok[kiek].egzrez>10){
        cout<<"Ivertinimas turi buti desimtbaleje sistemoje, pabandykite dar karta"<<endl;
        while(true){
            if(cin>>mok[kiek].egzrez) break;
            else{
                cin.clear();
                cin.ignore();
                cout<<"Klaidingai ivesti duomenys, iveskite sveika skaiciu"<<endl;
            }
        }
    }

    cout<<"Jei norite prideti daugiau mokiniu spauskite 1, jei baigete, spauskite bet koki kita skaiciu"<<endl;
    int a;

    while(true){
        if(cin>>a) break;
        else{
            cin.clear();
            cin.ignore();
            cout<<"Klaidingai ivesti duomenys"<<endl;
        }
    }
    if(a==1) input(kiek);

    return;
}

void calc(int j){
    mok[j].n++;
    double sum=0;
    double egz=0;
    double med=0;
    if(mok[j].n!=0){
        for(int i=0; i<(mok[j].n); i++){
            sum+=mok[j].ndrez[i];
        }
        sum=sum/(mok[j].n);
        if((mok[j].n)%2==0){
            med=mok[j].ndrez[(mok[j].n/2)-1]+mok[j].ndrez[(mok[j].n/2)];
            med/=2;
        }
        else{
            med=mok[j].ndrez[((mok[j].n+1)/2)-1];
        }
        cout<<med<<"<-------mediana"<<endl;
    }
    egz=mok[j].egzrez;
    cout<<setw(17)<<left<<mok[j].vard<<setw(17)<<left<<mok[j].pav<<setw(17)<<left<<fixed<<setprecision(2)<<(sum*0.4+egz*0.6)<<setw(17)<<left<<fixed<<setprecision(2)<<(med*0.4+egz*0.6)<<endl;
}

int main(){    
    int kiek=-1;

    input(kiek);

    cout<<setw(17)<<left<<"Vardas"<<setw(17)<<left<<"Pavarde"<<setw(17)<<left<<"Galutinis (Vid.)"<<setw(17)<<left<<"Galutinis (Med.)"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

    for(int i=0; i<kiek+1; i++){
        calc(i);
    }
    
    return 0;
}