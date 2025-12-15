#include "DigitalMedia.h"

DigitalMedia::DigitalMedia(const char* t, int y) {
    strcpy(title, t);
    year = y;
}

DigitalMedia::~DigitalMedia() {}

const char* DigitalMedia::getTitle() const { return title; }
int DigitalMedia::getYear() const { return year; }




















