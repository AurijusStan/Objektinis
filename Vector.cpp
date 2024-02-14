#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <random>
//#include <cstdlib>

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

    srand(time(nullptr));

    int x;

    while(true){
        cout<<"1-ranka; 2-generuoti pazymius; 3-generuoti pazymius ir varda/pavarde; 4-baigti darba"<<endl;
        if(cin>>x) break;
        else{
            cin.clear();
            cin.ignore();
            cout<<"Klaidingai ivesti duomenys"<<endl;
        }
    }
    while(x<1||x>4){
        cout<<"Pasirinkite viena is duotu variantu"<<endl;
        while(true){
            if(cin>>x) break;
            else{
                cin.clear();
                cin.ignore();
                cout<<"Klaidingai ivesti duomenys"<<endl;
            }
        }
    }

    if(x==4) exit(0);

    mok.push_back(duom());
    kiek++;

    if(x==3){
        for(int i=0; i<4+rand()%6; i++){
            if(i==0) mok[kiek].vard+=(char) (65+rand()%25);
            else mok[kiek].vard+=(char) (97+rand()%25);
        }
        for(int i=0; i<4+rand()%8; i++){
            if(i==0) mok[kiek].pav+=(char) (65+rand()%25);
            else mok[kiek].pav+=(char) (97+rand()%25);
        }
    }
    else{
        cout<<"Irasykite varda"<<endl;
        cin>>mok[kiek].vard;
        cout<<"Irasykite pavarde"<<endl;
        cin>>mok[kiek].pav;
    }
    
    if(x==2||x==3){
        for(int i=0; i<1+rand()%10; i++){
            mok[kiek].ndrez.push_back(rand()%11);
            mok[kiek].n++;
        }
    }
    else{
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
    }
    sort(kiek);

    if(x==2||x==3){
        mok[kiek].egzrez=rand()%11;
    }
    else{
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
    }
    egz=mok[j].egzrez;
    cout<<setw(19)<<left<<mok[j].vard<<setw(19)<<left<<mok[j].pav<<setw(19)<<left<<setprecision(2)<<(sum*0.4+egz*0.6)<<setw(19)<<left<<setprecision(2)<<(med*0.4+egz*0.6)<<endl;
}

int main(){    
    int kiek=-1;



    input(kiek);

    cout<<setw(19)<<left<<"Vardas"<<setw(19)<<left<<"Pavarde"<<setw(19)<<left<<"Galutinis (Vid.)"<<setw(19)<<left<<"Galutinis (Med.)"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

    for(int i=0; i<kiek+1; i++){
        calc(i);
    }
    
    return 0;
}