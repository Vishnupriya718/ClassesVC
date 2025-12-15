#ifndef MOVIE_H
#define MOVIE_H

#include "DigitalMedia.h"

class Movie : public DigitalMedia {
private:
    char director[100];
    int duration;
    char rating[50];

public:
    Movie(const char* t, const char* d, int y, int dur, const char* r);
    ~Movie();

    const char* getDirector() const;
    int getDuration() const;
    const char* getRating() const;

    void print() const override;
};

#endif
