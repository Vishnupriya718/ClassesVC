#include <iostream>
#include <vector>
#include <cstring>

#include "DigitalMedia.h"
#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

void addMedia(vector<DigitalMedia*>& db);
void searchMedia(vector<DigitalMedia*>& db);
void deleteMedia(vector<DigitalMedia*>& db);

int main() {
    vector<DigitalMedia*> db;
    char command[20];

    while (true) {
        cout << "\nEnter a command (ADD, SEARCH, DELETE, QUIT): ";
        cin >> command;

        if (strcmp(command, "ADD") == 0) addMedia(db);
        else if (strcmp(command, "SEARCH") == 0) searchMedia(db);
        else if (strcmp(command, "DELETE") == 0) deleteMedia(db);
        else if (strcmp(command, "QUIT") == 0) break;
        else cout << "Invalid command.\n";
    }

    // Cleanup
    for (auto m : db) delete m;

    return 0;
}

void addMedia(vector<DigitalMedia*>& db) {
    char type[20];
    cout << "Type? (Videogame, Music, Movie): ";
    cin >> type;

    char title[100];
    int year;

    if (strcmp(type, "Videogame") == 0) {
        char publisher[100], rating[50];

        cin.ignore();
        cout << "Title: "; cin.getline(title, 100);
        cout << "Year: "; cin >> year; cin.ignore();
        cout << "Publisher: "; cin.getline(publisher, 100);
        cout << "Rating: "; cin.getline(rating, 50);

        db.push_back(new VideoGame(title, year, publisher, rating));
    }

    else if (strcmp(type, "Music") == 0) {
        char artist[100], publisher[100];
        int duration;

        cin.ignore();
        cout << "Title: "; cin.getline(title, 100);
        cout << "Artist: "; cin.getline(artist, 100);
        cout << "Year: "; cin >> year;
        cout << "Duration: "; cin >> duration; cin.ignore();
        cout << "Publisher: "; cin.getline(publisher, 100);

        db.push_back(new Music(title, artist, year, duration, publisher));
    }

    else if (strcmp(type, "Movie") == 0) {
        char director[100], rating[50];
        int duration;

        cin.ignore();
        cout << "Title: "; cin.getline(title, 100);
        cout << "Director: "; cin.getline(director, 100);
        cout << "Year: "; cin >> year;
        cout << "Duration: "; cin >> duration; cin.ignore();
        cout << "Rating: "; cin.getline(rating, 50);

        db.push_back(new Movie(title, director, year, duration, rating));
    }
}

void searchMedia(vector<DigitalMedia*>& db) {
    char type[20];
    cout << "Search by TITLE or YEAR: ";
    cin >> type;

    if (strcmp(type, "TITLE") == 0) {
        char t[100];
        cin.ignore();
        cout << "Enter title: ";
        cin.getline(t, 100);

        for (auto m : db)
            if (strcmp(m->getTitle(), t) == 0)
                m->print();
    }

    else if (strcmp(type, "YEAR") == 0) {
        int y;
        cout << "Enter year: ";
        cin >> y;

        for (auto m : db)
            if (m->getYear() == y)
                m->print();
    }
}

void deleteMedia(vector<DigitalMedia*>& db) {
    char type[20];
    cout << "Delete by TITLE or YEAR: ";
    cin >> type;

    if (strcmp(type, "TITLE") == 0) {
        char t[100];
        cin.ignore();
        cout << "Enter title: ";
        cin.getline(t, 100);

        for (int i = 0; i < db.size(); i++) {
            if (strcmp(db[i]->getTitle(), t) == 0) {
                cout << "Deleting...\n";
                delete db[i];
                db.erase(db.begin() + i);
                i--;
            }
        }
    }

    else if (strcmp(type, "YEAR") == 0) {
        int y;
        cout << "Enter year: ";
        cin >> y;

        for (int i = 0; i < db.size(); i++) {
            if (db[i]->getYear() == y) {
                cout << "Deleting...\n";
                delete db[i];
                db.erase(db.begin() + i);
                i--;
            }
        }
    }
}
