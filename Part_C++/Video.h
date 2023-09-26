#ifndef VIDEO_H
#define VIDEO_H

#include <string>

#include "Multimedia.h"

class Video : public Multimedia {
   protected:
    unsigned int length{};

   public:
    Video(){};
    Video(std::string name, std::string fileName, unsigned int length) {
        this->name = name;
        this->fileName = fileName;
        this->length = length;
    };

    inline void setLength(unsigned int length) { this->length = length; };

    inline double getLength() const { return this->length; };

    void displayInfo(std::ostream &s) const override {
        s << "Name of video : " << this->getName() << std::endl;
        s << "Filename : " << this->getFileName() << std::endl;
        s << "Length = " << this->getLength() << std::endl;
        s << "----------------------------------------" << std::endl;
    };
    void display() const override {
        std::string str{};

        str = "mpv " + this->fileName + " &";

        // std::cout << str.data() << std::endl;
        system(str.data());
    };
};

#endif