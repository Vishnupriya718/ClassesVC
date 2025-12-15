#include "Movie.h"
#include <iostream>
#include <cstring>
using namespace std;

Movie::Movie(const char* t, const char* d, int y, int dur, const char* r)
    : DigitalMedia(t, y) {
    strcpy(director, d);
    duration = dur;
    strcpy(rating, r);
}

Movie::~Movie() {}

const char* Movie::getDirector() const { return director; }
int Movie::getDuration() const { return duration; }
const char* Movie::getRating() const { return rating; }

void Movie::print() const {
    cout << "Movie: " << title << ", Director: " << director
         << ", Year: " << year
         << ", Duration: " << duration << " mins"
         << ", Rating: " << rating << endl;
}






















