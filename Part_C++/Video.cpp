#include "Video.h"

Video::Video() {}

Video::Video(std::string name, std::string fileName, unsigned int length) {
    this->name = name;
    this->fileName = fileName;
    this->length = length;
}

void Video::setLength(unsigned int length) { this->length = length; }

double Video::getLength() { return this->length; }

void Video::displayVar(std::ostream &s) {
    s << "Name of video : " << this->getName() << std::endl;
    s << "Filename : " << this->getFileName() << std::endl;
    s << "Length = " << this->getLength() << std::endl;
    s << "----------------------------------------" << std::endl;
}

void Video::display() {
    std::string str{};

    str = "mpv " + this->fileName + " &";

    // std::cout << str.data() << std::endl;
    system(str.data());
}