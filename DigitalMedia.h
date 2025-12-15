#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

#include <iostream>
#include <cstring>

class DigitalMedia {
protected:
    char title[100];
    int year;

public:
    DigitalMedia(const char* t, int y);
    virtual ~DigitalMedia();

    const char* getTitle() const;
    int getYear() const;

    virtual void print() const = 0; // pure virtual
};

#endif
