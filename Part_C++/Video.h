#ifndef VIDEO_H
#define VIDEO_H

#include <string>

#include "Multimedia.h"

class Video : public Multimedia {
   private:
    unsigned int length{};

   public:
    Video();
    Video(std::string name, std::string fileName, unsigned int length);

    void setLength(unsigned int length);

    double getLength();

    void displayVar(std::ostream &s) override;
    void display() override;
};

#endif