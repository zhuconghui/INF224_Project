#ifndef FILM_H
#define FILM_H

#include <string>

#include "Video.h"

using namespace std;


class Film : public Video {
   protected:
    unsigned int nbChapter{};
    unsigned int *lengthOfChapters = nullptr;

   public:
    Film(){};
    Film(string name, string fileName, unsigned int length,
         unsigned int nbChapter, unsigned int *lengthOfChapters) {
        this->name = name;
        this->fileName = fileName;
        this->length = length;
        this->nbChapter = nbChapter;
        this->lengthOfChapters = lengthOfChapters;
    };

    ~Film() override{
        delete []lengthOfChapters;
        cout << "Film " << this->getName() << " is destroyed" << endl; 
    }

    inline void setNbChapter(unsigned int nbChapter) {
        this->nbChapter = nbChapter;
    };

    inline void setLengthOfChapters(unsigned int *lengthOfChapters) {
        this->lengthOfChapters = lengthOfChapters;
    };

    inline double getNbChapter() const { return this->nbChapter; };

    inline unsigned int *getLengthOfChapters() const {
        return this->lengthOfChapters;
    };

    void displayInfo(ostream &s) const override {
        s << "Name of film : " << this->getName() << endl;
        s << "Filename : " << this->getFileName() << endl;
        s << "Length = " << this->getLength() << endl;
        s << "Number of chapter = " << this->getNbChapter() << endl;        
        for (unsigned int i = 0; i < getNbChapter(); i++) {
            s << "Length of chapter " << i << " = " << this->getLengthOfChapters()[i]
              << endl;
        }
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