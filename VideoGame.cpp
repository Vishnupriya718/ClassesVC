#include "VideoGame.h"
#include <iostream>
#include <cstring>
using namespace std;

VideoGame::VideoGame(const char* t, int y, const char* p, const char* r)
    : DigitalMedia(t, y) {
    strcpy(publisher, p);
    strcpy(rating, r);
}

VideoGame::~VideoGame() {}

const char* VideoGame::getPublisher() const { return publisher; }
const char* VideoGame::getRating() const { return rating; }

void VideoGame::print() const {
    cout << "VideoGame: " << title << ", Year: " << year
         << ", Publisher: " << publisher
         << ", Rating: " << rating << endl;
}
