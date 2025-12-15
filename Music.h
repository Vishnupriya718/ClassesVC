#ifndef MUSIC_H
#define MUSIC_H

#include "DigitalMedia.h"

class Music : public DigitalMedia {
private:
    char artist[100];
    int duration;
    char publisher[100];

public:
    Music(const char* t, const char* a, int y, int d, const char* p);
    ~Music();

    const char* getArtist() const;
    int getDuration() const;
    const char* getPublisher() const;

    void print() const override;
};

#endif
