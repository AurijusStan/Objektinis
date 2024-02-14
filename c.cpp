#include <iostream>
#include <iomanip>
#include <numeric>
#include <random>

using namespace std;
using std::setw;
using std::left;

struct duom{
    string vard;
    string pav;
    int uzimta;
    int skirta;
    int* ndrez;
    int egzrez;
};

vector<duom> mok;

void sort(duom* mok, int k){
    for(int i=0; i<mok[k].uzimta+1; i++){
        for(int j=i+1; j<mok[k].uzimta+1; j++){
            if(mok[k].ndrez[i]>mok[k].ndrez[j]) swap(mok[k].ndrez[i], mok[k].ndrez[j]);
        }
    }
}

void input(duom* mok, int &uzimta, int &skirta){

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

    if(x==3){
        for(int i=0; i<4+rand()%6; i++){
            if(i==0) mok[uzimta].vard+=(char) (65+rand()%25);
            else mok[uzimta].vard+=(char) (97+rand()%25);
        }
        for(int i=0; i<4+rand()%8; i++){
            if(i==0) mok[uzimta].pav+=(char) (65+rand()%25);
            else mok[uzimta].pav+=(char) (97+rand()%25);
        }
    }
    else{
        cout<<"Irasykite varda"<<endl;
        cin>>mok[uzimta].vard;
        cout<<"Irasykite pavarde"<<endl;
        cin>>mok[uzimta].pav;
    }
    
    mok[uzimta].uzimta=0;
    mok[uzimta].skirta=1;
    mok[uzimta].ndrez = new int[mok[uzimta].skirta];

    if(x==2||x==3){
        for(int i=0; i<1+rand()%10; i++){
            if(mok[uzimta].uzimta==mok[uzimta].skirta){
                mok[uzimta].skirta+=5;
                int* temp = new int[mok[uzimta].skirta];
                for(int i=0; i<mok[uzimta].uzimta; i++){
                    temp[i]=mok[uzimta].ndrez[i];
                }
                delete[] mok[uzimta].ndrez;
                mok[uzimta].ndrez=temp;
            }
            mok[uzimta].ndrez[mok[uzimta].uzimta]=rand()%11;
            mok[uzimta].uzimta++;
        }
    }
    else{
        cout<<"Irasykite nd rezultatus po kiekvieno spaudziant enter, jei baigete parasykite skaiciu netelpanti i desimtbales sistemos intervala"<<endl;
        while(true){
            if(mok[uzimta].uzimta==mok[uzimta].skirta){
                mok[uzimta].skirta+=5;
                int* temp = new int[mok[uzimta].skirta];
                for(int i=0; i<mok[uzimta].uzimta; i++){
                    temp[i]=mok[uzimta].ndrez[i];
                }
                delete[] mok[uzimta].ndrez;
                mok[uzimta].ndrez=temp;
            }
            while(true){
                if(cin>>mok[uzimta].ndrez[mok[uzimta].uzimta]) break;
                else{
                    cin.clear();
                    cin.ignore();
                    cout<<"Klaidingai ivesti duomenys, iveskite sveika skaiciu"<<endl;
                }
            }
            
            if(mok[uzimta].ndrez[mok[uzimta].uzimta]<0||mok[uzimta].ndrez[mok[uzimta].uzimta]>10){
                break;
            }
            mok[uzimta].uzimta++;
        }
    }

    sort(mok, uzimta);

    if(x==2||x==3){
        mok[uzimta].egzrez=rand()%11;
    }
    else{
        while(true){
            cout<<"Irasykite egzamino rezultata"<<endl;
            if(cin>>mok[uzimta].egzrez) break;
            else{
                cin.clear();
                cin.ignore();
                cout<<"Klaidingai ivesti duomenys"<<endl;
            }
        }
        while(mok[uzimta].egzrez<0||mok[uzimta].egzrez>10){
            cout<<"Ivertinimas turi buti desimtbaleje sistemoje, pabandykite dar karta"<<endl;
            while(true){
                if(cin>>mok[uzimta].egzrez) break;
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
    if(a==1){
        uzimta++;
        if(uzimta==skirta){
            skirta+=5;
            duom* temp = new duom[skirta];
            for(int i=0; i<uzimta; i++){
                temp[i]=mok[i];
            }
            delete[] mok;
            mok=temp;
        }
        input(mok, uzimta, skirta);
    }
    return;
}

void calc(duom* mok, int j){
    double sum=0;
    double egz=0;
    double med=0;
    if(mok[j].uzimta!=0){
        for(int i=0; i<(mok[j].uzimta); i++){
            sum+=mok[j].ndrez[i];
        }
        sum=sum/(mok[j].uzimta);
        if((mok[j].uzimta)%2==0){
            med=mok[j].ndrez[mok[j].uzimta/2]+mok[j].ndrez[(mok[j].uzimta+1)/2];
            med/=2;
        }
        else{
            med=mok[j].ndrez[((mok[j].uzimta+1)/2)];
        }
    }
    egz=mok[j].egzrez;
    cout<<setw(19)<<left<<mok[j].vard<<setw(19)<<left<<mok[j].pav<<setw(19)<<left<<setprecision(2)<<(sum*0.4+egz*0.6)<<setw(19)<<left<<setprecision(2)<<(med*0.4+egz*0.6)<<endl;
}

int main(){    
    int uzimta=0, skirta=1;

    duom* mok = new duom[skirta];

    input(mok, uzimta, skirta);

    cout<<setw(19)<<left<<"Vardas"<<setw(19)<<left<<"Pavarde"<<setw(19)<<left<<"Galutinis (Vid.)"<<setw(19)<<left<<"Galutinis (Med.)"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

    for(int i=1; i<=uzimta+1; i++){
        calc(mok, i);
    }
    
    return 0;
}