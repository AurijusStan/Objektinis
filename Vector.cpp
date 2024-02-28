// #include <iostream>
// #include <iomanip>
// #include <numeric>
// #include <vector>
// #include <random>
// #include <string>
// #include <chrono>

#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
using std::setw;
using std::left;

struct duom{
    string vard;
    string pav;
    vector<int> ndrez;
    int egzrez;
    double galvid, galmed;
};

bool sort1(const duom &a, const duom &b){
    return(a.vard<b.vard);
}
bool sort2(const duom &a, const duom &b){
    return(a.pav<b.pav);
}
bool sort3(const duom &a, const duom &b){
    return(a.galvid<b.galvid);
}
bool sort4(const duom &a, const duom &b){
    return(a.galmed<b.galmed);
}
bool sort1u(const duom &a, const duom &b){
    return(a.vard>b.vard);
}
bool sort2u(const duom &a, const duom &b){
    return(a.pav>b.pav);
}
bool sort3u(const duom &a, const duom &b){
    return(a.galvid>b.galvid);
}
bool sort4u(const duom &a, const duom &b){
    return(a.galmed>b.galmed);
}

void rusiuoti(int x, int t, vector<duom>& mok){
    if(t==1){
        if(x==1) sort(mok.begin(), mok.end(), sort1);
        if(x==2) sort(mok.begin(), mok.end(), sort2);
        if(x==3) sort(mok.begin(), mok.end(), sort3);
        if(x==4) sort(mok.begin(), mok.end(), sort4);
    }
    else{
        if(x==1) sort(mok.begin(), mok.end(), sort1u);
        if(x==2) sort(mok.begin(), mok.end(), sort2u);
        if(x==3) sort(mok.begin(), mok.end(), sort3u);
        if(x==4) sort(mok.begin(), mok.end(), sort4u);
    }
}

void calc(duom &m){
    int a=accumulate(m.ndrez.begin(), m.ndrez.end(), 0);
    double sum=a;
    double egz=0;
    double med=0;

    sort(m.ndrez.begin(), m.ndrez.end());

    for(int i=0; i<m.ndrez.size(); i++){
        cout<<m.ndrez[i]<<" ";
    }
    cout<<endl;

    if(m.ndrez.size()!=0){
        sum=sum/(m.ndrez.size());
        if((m.ndrez.size())%2==0){
            med=m.ndrez[(m.ndrez.size()/2)-1]+m.ndrez[(m.ndrez.size()/2)];
            med/=2;
        }
        else{
            med=m.ndrez[((m.ndrez.size()+1)/2)-1];
        }
    }
    egz=m.egzrez;

    m.galvid=sum*0.4+egz*0.6;
    m.galmed=med*0.4+egz*0.6;
}

double isfailo(int &moksk, vector<duom> &mok){
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

    auto start = high_resolution_clock::now();

    cin>>temp;
    cin>>temp;

    while(true){
        cin>>temp;
        if(temp.back()>='0'&&temp.back()<='9'){
            ndsk++;
        }
        else{
            getline(cin, temp);
            break;
        }
    }

    for(int i=0; i<moksk; i++){
        duom m;

        string vardas;

        cin>>m.vard>>m.pav;

        for(int j=0; j<ndsk; j++){
            int a;
            cin>>a;
            m.ndrez.push_back(a);
        }

        cin>>m.egzrez;

        calc(m);

        mok.push_back(m);

        cin.ignore(255, '\n');
    }

    rusiuoti(x, t, mok);
    
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    return(duration.count());
}

void input(int &moksk, vector<duom>& mok, double &duration){

    srand(time(nullptr));

    int x;

    if(moksk==-1){
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
        duration=isfailo(moksk, mok);
        return;
    }
    else{
        duom m;
        moksk++;

        if(x==3){
            for(int i=0; i<4+rand()%6; i++){
                if(i==0) m.vard+=(char) (65+rand()%25);
                else m.vard+=(char) (97+rand()%25);
            }
            for(int i=0; i<4+rand()%8; i++){
                if(i==0) m.pav+=(char) (65+rand()%25);
                else m.pav+=(char) (97+rand()%25);
            }
        }
        else{
            cout<<"Irasykite varda"<<endl;
            cin>>m.vard;
            cout<<"Irasykite pavarde"<<endl;
            cin>>m.pav;
        }
        
        if(x==2||x==3){
            for(int i=0; i<1+rand()%10; i++){
                m.ndrez.push_back(rand()%11);
            }
        }
        else{
            cout<<"Irasykite nd rezultatus po kiekvieno spaudziant enter, jei baigete parasykite skaiciu netelpanti i desimtbales sistemos intervala"<<endl;
            int h;
            while(true){
                while(true){
                    if(cin>>h) break;
                    else{
                        cin.clear();
                        cin.ignore();
                        cout<<"Klaidingai ivesti duomenys, iveskite sveika skaiciu"<<endl;
                    }
                }
                if(h<0||h>10){
                    break;
                }
                m.ndrez.push_back(h);
            }
        }

        if(x==2||x==3){
            m.egzrez=rand()%11;
        }
        else{
            while(true){
                cout<<"Irasykite egzamino rezultata"<<endl;
                if(cin>>m.egzrez) break;
                else{
                    cin.clear();
                    cin.ignore();
                    cout<<"Klaidingai ivesti duomenys"<<endl;
                }
            }
            while(m.egzrez<0||m.egzrez>10){
                cout<<"Ivertinimas turi buti desimtbaleje sistemoje, pabandykite dar karta"<<endl;
                while(true){
                    if(cin>>m.egzrez) break;
                    else{
                        cin.clear();
                        cin.ignore();
                        cout<<"Klaidingai ivesti duomenys, iveskite sveika skaiciu"<<endl;
                    }
                }
            }
        }

        calc(m);
        
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

        mok.push_back(m);

        if(a==1) input(moksk, mok, duration);

        moksk++;
    }

    return;
}

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