#include "Multimedia.h"

using namespace std;

Multimedia::Multimedia() {}

Multimedia::Multimedia(string name, string fileName) {
    this->name = name;
    this->fileName = fileName;
}

void Multimedia::setName(string name) { this->name = name; }

void Multimedia::setFileName(string fileName) { this->fileName = fileName; }

string Multimedia::getName() const { return this->name; }

string Multimedia::getFileName() const { return this->fileName; }

void Multimedia::displayInfo(ostream &s) const {}

void Multimedia::play() const {}

Multimedia::~Multimedia() {
    cout << "Multimedia " << this->getName() << " is destroyed" << endl;
}