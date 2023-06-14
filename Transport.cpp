//Metode i podaci vezani za rad sa Transport klasom koju svi drugi transporti nasledjuju
#include "Transport.h"


void Transport::setNaziv(string naziv) {
    int i = 0;
    while (naziv[i]) {
        if (!isalpha(naziv[i])) {

            throw NazivNijeValidan();
        }
        else {
            this->naziv = naziv;
        }
        i++;
    }
}

void Transport::setTip(string tip) {
    int i = 0;
    while (tip[i]) {
        if (!isalpha(tip[i])) {

            throw NazivNijeValidan();
        }
        else {
            this->tip = tip;
        }
        i++;
    }


}

void Transport::setId(int id) {
    if (id < 1) {
        throw IDNijeValidan();
    }
    this->id = id;
}

void Transport::search_transport() { //Metoda za pretragu transporta po nazivu


    ifstream read;
    read.open("transport.txt", ios::in);
    string line;
    string search;

    cout << "Unesite naziv transporta:  ";
    cin >> search;

    while (getline(read, line)) {
        if (line.find(search) != string::npos) {
            cout << line << endl;
        }
    }


    read.close();

}

void Transport::delete_transport() { //Metoda za brisanje transporta

    fstream stud;
    fstream temp;

    stud.open("transport.txt", ios::in);
    temp.open("temp.txt", ios::out);

    string line;
    string search;

    cin.ignore();
    cout << "Unesite id transporta koji brisete: ";
    getline(cin, search);
    while (getline(stud, line)) {


        if (line.find(search) != string::npos) {

            continue;
        }
        else {
            temp << line << endl;

        }


    }
    temp.close();
    stud.close();

    stud.open("transport.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (getline(temp, line)) {

        cout << line << endl;
        stud << line << endl;

    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout << "\n Uspesno ste izbrisali!!! \n";

}

void Transport::display_all_list() { //Metoda za prikaz svih postojecih transportnih sredstava

    vector<string> v;

    ifstream read;
    read.open("transport.txt", ios::in);
    string line;


    if (read.is_open()) {
        while (getline(read, line)) {
            v.push_back(line);
        }
        sort(v.begin(), v.end());

        for (auto s : v) {
            cout << "----------------------------" << endl;
            cout << s << endl;
        }
        cout << "----------------------------" << endl;


    }
    read.close();


}


