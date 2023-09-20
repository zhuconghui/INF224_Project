#include "Multimedia.h"

Multimedia::Multimedia() {}

Multimedia::Multimedia(std::string name, std::string fileName) {
    this->name = name;
    this->fileName = fileName;
}

void Multimedia::setName(std::string name) { this->name = name; }

void Multimedia::setFileName(std::string fileName) {
    this->fileName = fileName;
}

std::string Multimedia::getName() const { return this->name; }

std::string Multimedia::getFileName() const { return this->fileName; }

void Multimedia::displayVar(std::ostream &s) {
    s << "Name of multimedia : " << this->getName() << std::endl;
    s << "Filename : " << this->getFileName() << std::endl;
    s << "----------------------------------------" << std::endl;
}

void Multimedia::display() {}

Multimedia::~Multimedia() {}