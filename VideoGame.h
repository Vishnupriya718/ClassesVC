#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "DigitalMedia.h"

class VideoGame : public DigitalMedia {
private:
    char publisher[100];
    char rating[50];

public:
    VideoGame(const char* t, int y, const char* p, const char* r);
    ~VideoGame();

    const char* getPublisher() const;
    const char* getRating() const;

    void print() const override;
};

#endif
