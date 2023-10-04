#ifndef VIDEO_H
#define VIDEO_H

#include <string>

#include "Multimedia.h"

using namespace std;

class Video : public Multimedia {
   protected:
    unsigned int length{};

   public:
    Video(){};

    Video(string name, string fileName, unsigned int length) {
        this->name = name;
        this->fileName = fileName;
        this->length = length;
    };

    ~Video() override{
        cout << "Video " << this->getName() << " is destroyed" << endl;
    }

    inline void setLength(unsigned int length) { this->length = length; };

    inline double getLength() const { return this->length; };

    void displayInfo(ostream &s) const override {
        s << "Name of video : " << this->getName() << endl;
        s << "Filename : " << this->getFileName() << endl;
        s << "Length = " << this->getLength() << endl;
        s << "----------------------------------------" << endl;
    };

    void display() const override {
        string str{};

        str = "mpv " + this->fileName + " &";

        // cout << str.data() << endl;
        system(str.data());
    };
};

#endif