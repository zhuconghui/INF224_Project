#ifndef FILM_H
#define FILM_H

#include <string>

#include "Video.h"

class Film : public Video {
   protected:
    unsigned int nbChapter{};
    unsigned int *lengthOfChapters = nullptr;

   public:
    Film(){};
    Film(std::string name, std::string fileName, unsigned int length,
         unsigned int nbChapter, unsigned int *lengthOfChapters) {
        this->name = name;
        this->fileName = fileName;
        this->length = length;
        this->nbChapter = nbChapter;
        this->lengthOfChapters = lengthOfChapters;
    };

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

    void displayInfo(std::ostream &s) const override {
        s << "Name of film : " << this->getName() << std::endl;
        s << "Filename : " << this->getFileName() << std::endl;
        s << "Length = " << this->getLength() << std::endl;
        s << "Number of chapter = " << this->getNbChapter() << std::endl;        
        for (unsigned int i = 0; i < getNbChapter(); i++) {
            s << "Length of chapter " << i << " = " << this->getLengthOfChapters()[i]
              << std::endl;
        }
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