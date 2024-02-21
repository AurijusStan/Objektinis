#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <random>
#include <string>

using namespace std;
using std::setw;
using std::left;

struct duom{
    string vard;
    string pav;
    int n=-1;
    vector<int> ndrez;
    int egzrez;
    double galvid, galmed;
};

vector<duom> mok;

void sort(int k){
    for(int i=0; i<mok[k].n; i++){
        for(int j=i+1; j<mok[k].n+1; j++){
            if(mok[k].ndrez[i]>mok[k].ndrez[j]) swap(mok[k].ndrez[i], mok[k].ndrez[j]);
        }
    }
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

    mok[j].galvid=sum*0.4+egz*0.6;
    mok[j].galmed=med*0.4+egz*0.6;
}

void isfailo(){
    int moksk;
    int ndsk=0;

    cout<<"Kiek asmenu nuskaityti nuo duoto failo?"<<endl;
    while(true){
        if(cin>>moksk) break;
        else{
            cin.clear();
            cin.ignore();
            cout<<"Klaidingai ivesti duomenys"<<endl;
        }
    }
    while(moksk<0){
        cout<<"Negali buti neigiamas skaicius mokiniu"<<endl;
        while(true){
            if(cin>>moksk) break;
            else{
                cin.clear();
                cin.ignore();
                cout<<"Klaidingai ivesti duomenys, iveskite teigiama skaiciu"<<endl;
            }
        }
    }

    // cout<<"Kiek namu darbu buvo skirta asmenims?"<<endl;
    // while(true){
    //     if(cin>>ndsk) break;
    //     else{
    //         cin.clear();
    //         cin.ignore();
    //         cout<<"Klaidingai ivesti duomenys"<<endl;
    //     }
    // }
    // while(ndsk<0){
    //     cout<<"Negali buti neigiamas skaicius namu darbu"<<endl;
    //     while(true){
    //         if(cin>>ndsk) break;
    //         else{
    //             cin.clear();
    //             cin.ignore();
    //             cout<<"Klaidingai ivesti duomenys, iveskite teigiama skaiciu"<<endl;
    //         }
    //     }
    // }

    int x;
    int t;

    while(true){
        cout<<"Rusiuoti pagal: 1-varda; 2-pavarde; 3-galutini(vid); 4-galutini(med)"<<endl;
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

    while(true){
        cout<<"Tvarka: 1-didejimo; 2-mazejimo"<<endl;
        if(cin>>t) break;
        else{
            cin.clear();
            cin.ignore();
            cout<<"Klaidingai ivesti duomenys"<<endl;
        }
    }
    while(t<1||t>2){
        cout<<"Pasirinkite viena is duotu variantu"<<endl;
        while(true){
            if(cin>>t) break;
            else{
                cin.clear();
                cin.ignore();
                cout<<"Klaidingai ivesti duomenys"<<endl;
            }
        }
    }

    freopen("studentai10000.txt", "r", stdin);

    string temp;

    getline(cin, temp, ' ');

    while(true){
        char c;
        cin>>c;
        if(c!=' '){
            getline(cin, temp, ' ');
            break;
        }
    }

    while(true){
        char c;
        cin>>c;
        if(c!=' '){
            if(c=='E'){
                getline(cin, temp);
                break;
            }
            else{
                ndsk++;
                getline(cin, temp, ' ');
            }
        }
    }


    for(int i=0; i<moksk; i++){
        string vardas;
        mok.push_back(duom());

        getline(cin, vardas, ' ');
        mok[i].pav=vardas;

        while(true){
            char c;
            cin>>c;
            if(c!=' '){
                getline(cin, vardas, ' ');
                mok[i].vard=c+vardas;
                break;
            }
        }

        for(int j=0; j<ndsk; j++){
            int a;
            cin>>a;
            mok[i].ndrez.push_back(a);
        }

        cin>>mok[i].egzrez;

        mok[i].n=ndsk-1;

        sort(i);

        calc(i);

        cin.ignore(255, '\n');
    }

    if(x==1){
        for(int i=0; i<moksk; i++){
            for(int j=i+1; j<moksk; j++){
                if(t==1){
                    if(mok[i].vard>mok[j].vard) swap(mok[i], mok[j]);
                }
                else if(mok[i].vard<mok[j].vard) swap(mok[i], mok[j]);
            }
        }
    }
    if(x==2){
        for(int i=0; i<moksk; i++){
            for(int j=i+1; j<moksk; j++){
                if(t==1){
                    if(mok[i].pav>mok[j].pav) swap(mok[i], mok[j]);
                }
                else if(mok[i].pav<mok[j].pav) swap(mok[i], mok[j]);
            }
        }
    }
    if(x==3){
        for(int i=0; i<moksk; i++){
            for(int j=i+1; j<moksk; j++){
                if(t==1){
                    if(mok[i].galvid>mok[j].galvid) swap(mok[i], mok[j]);
                }
                else if(mok[i].galvid<mok[j].galvid) swap(mok[i], mok[j]);
            }
        }
    }
    if(x==4){
        for(int i=0; i<moksk; i++){
            for(int j=i+1; j<moksk; j++){
                if(t==1){
                    if(mok[i].galmed>mok[j].galmed) swap(mok[i], mok[j]);
                }
                else if(mok[i].galmed<mok[j].galmed) swap(mok[i], mok[j]);
            }
        }
    }
    
    cout<<setw(19)<<left<<"Vardas"<<setw(19)<<left<<"Pavarde"<<setw(19)<<left<<"Galutinis (Vid.)"<<setw(19)<<left<<"Galutinis (Med.)"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

    for(int i=0; i<moksk; i++){
        cout<<setw(19)<<left<<mok[i].vard<<setw(19)<<left<<mok[i].pav<<setw(19)<<left<<setprecision(2)<<mok[i].galvid<<setw(19)<<left<<setprecision(2)<<mok[i].galmed<<endl;
    }

    exit(0);
}

void input(int &kiek){

    srand(time(nullptr));

    int x;

    if(kiek==-1){
        while(true){
        cout<<"1-ranka; 2-generuoti pazymius; 3-generuoti pazymius ir varda/pavarde; 4-skaityti duomenis is failo kursiokai.txt; 5-baigti darba"<<endl;
        if(cin>>x) break;
        else{
            cin.clear();
            cin.ignore();
            cout<<"Klaidingai ivesti duomenys"<<endl;
        }
        }
        while(x<1||x>5){
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
    }
    else{
        while(true){
        cout<<"1-ranka; 2-generuoti pazymius; 3-generuoti pazymius ir varda/pavarde; 5-baigti darba"<<endl;
        if(cin>>x) break;
        else{
            cin.clear();
            cin.ignore();
            cout<<"Klaidingai ivesti duomenys"<<endl;
        }
        }
        while(x<1||x>5||x==4){
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
    }

    if(x==5) exit(0);

    if(x==4){
        isfailo();
        return;
    }

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

int main(){    
    int kiek=-1;

    input(kiek);

    cout<<setw(19)<<left<<"Vardas"<<setw(19)<<left<<"Pavarde"<<setw(19)<<left<<"Galutinis (Vid.)"<<setw(19)<<left<<"Galutinis (Med.)"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

    for(int i=0; i<kiek+1; i++){
        calc(i);
        cout<<setw(19)<<left<<mok[i].vard<<setw(19)<<left<<mok[i].pav<<setw(19)<<left<<setprecision(2)<<mok[i].galvid<<setw(19)<<left<<setprecision(2)<<mok[i].galmed<<endl;
    }
    
    return 0;
}