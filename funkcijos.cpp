#include "funkcijos.h"

using namespace std;

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
    while(!(cin>>moksk)||moksk<0){
        try{
            throw runtime_error("Klaidingai ivesti duomenys\n");
        }
        catch(const runtime_error &e){
            cin.clear();
            cin.ignore();
            cout<<e.what();
        }
    }

    int x;
    int t;

    cout<<"Rusiuoti pagal: 1-varda; 2-pavarde; 3-galutini(vid); 4-galutini(med)"<<endl;
    while(!(cin>>x)||x<1||x>4){
        try{
            throw runtime_error("Klaidingai ivesti duomenys\n");
        }
        catch(const runtime_error &e){
            cin.clear();
            cin.ignore();
            cout<<e.what();
        }
    }

    cout<<"Tvarka: 1-didejimo; 2-mazejimo"<<endl;
    while(!(cin>>t)||t<1||t>2){
        try{
            throw runtime_error("Klaidingai ivesti duomenys\n");
        }
        catch(const runtime_error &e){
            cin.clear();
            cin.ignore();
            cout<<e.what();
            cout<<"Pasirinkite viena is variantu"<<endl;
        }
    }

    string failas;

    while(true){
        cout<<"Iveskite faila is kurio imti duomenis"<<endl;
        cin>>failas;

        FILE *file=freopen((failas+".txt").c_str(), "r", stdin);

        if(file==nullptr){
            try{
                throw runtime_error("Klaidingai ivesti duomenys\n"); 
            }
            catch(const runtime_error &e){
                cout<<e.what();
                cin.clear();
                fclose(stdin);
                // while (cin.get()!='\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else break;
    }

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

    mok.reserve(moksk);

    for(int i=0; i<moksk; i++){
        duom m;

        string vardas;

        cin>>m.vard>>m.pav;

        m.ndrez.reserve(ndsk);

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
            cout<<"1-ranka; 2-generuoti pazymius; 3-generuoti pazymius ir varda/pavarde; 4-skaityti duomenis is failo; 5-baigti darba"<<endl;
            if(!(cin>>x)||x<1||x>5){
                try{
                    throw runtime_error("Klaidingai ivesti duomenys\n");
                }
                catch(const runtime_error &e){
                    cin.clear();
                    cin.ignore();
                    cout<<e.what();
                }
            }
            else break;
        }
    }
    else{
        while(true){
            cout<<"1-ranka; 2-generuoti pazymius; 3-generuoti pazymius ir varda/pavarde; 5-baigti darba"<<endl;
            if(!(cin>>x)||x<1||x>5||x==4){
                try{
                    throw runtime_error("Klaidingai ivesti duomenys\n");
                }
                catch(const runtime_error &e){
                    cin.clear();
                    cin.ignore();
                    cout<<e.what();
                }
            }
            else break;
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
            while(!(cin>>m.vard)){
                try{
                    throw runtime_error("Klaidingai ivesti duomenys\n");
                }
                catch(const runtime_error &e){
                    cin.clear();
                    cin.ignore();
                    cout<<e.what();
                }
            }
            cout<<"Irasykite pavarde"<<endl;
            while(!(cin>>m.pav)){
                try{
                    throw runtime_error("Klaidingai ivesti duomenys\n");
                }
                catch(const runtime_error &e){
                    cin.clear();
                    cin.ignore();
                    cout<<e.what();
                }
            }
        }
        
        if(x==2||x==3){
            for(int i=0; i<1+rand()%15; i++){
                m.ndrez.push_back(rand()%11);
            }
        }
        else{
            cout<<"Irasykite nd rezultatus po kiekvieno spaudziant enter, jei baigete parasykite skaiciu netelpanti i desimtbales sistemos intervala"<<endl;
            int h;
            while(true){
                while(!(cin>>h)){
                    try{
                        throw runtime_error("Klaidingai ivesti duomenys\n");
                    }
                    catch(const runtime_error &e){
                        cin.clear();
                        cin.ignore();
                        cout<<e.what();
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
            cout<<"Irasykite egzamino rezultata"<<endl;
            while(!(cin>>m.egzrez)||m.egzrez<0||m.egzrez>10){
                try{
                    throw runtime_error("Klaidingai ivesti duomenys\n");
                }
                catch(const runtime_error &e){
                    cin.clear();
                    cin.ignore();
                    cout<<e.what();
                }
            }
        }

        calc(m);
        
        cout<<"Jei norite prideti daugiau mokiniu spauskite 1, jei baigete, spauskite bet koki kita svaika skaiciu"<<endl;
        int a;

        while(!(cin>>a)){
            try{
                throw runtime_error("Klaidingai ivesti duomenys\n");
            }
            catch(const runtime_error &e){
                cin.clear();
                cin.ignore();
                cout<<e.what();
            }
        }

        mok.push_back(m);

        if(a==1) input(moksk, mok, duration);

        moksk++;
    }

    return;
}