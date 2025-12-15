#include "Music.h"
#include <iostream>
#include <cstring>
using namespace std;

Music::Music(const char* t, const char* a, int y, int d, const char* p)
    : DigitalMedia(t, y) {
    strcpy(artist, a);
    duration = d;
    strcpy(publisher, p);
}

Music::~Music() {}

const char* Music::getArtist() const { return artist; }
int Music::getDuration() const { return duration; }
const char* Music::getPublisher() const { return publisher; }

void Music::print() const {
    cout << "Music: " << title << ", Artist: " << artist
         << ", Year: " << year
         << ", Duration: " << duration << " mins"
         << ", Publisher: " << publisher << endl;
}
