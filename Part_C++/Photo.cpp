#include "Photo.h"

Photo::Photo() {}

Photo::Photo(std::string name, std::string fileName, double latitude,
             double longitude) {
    this->name = name;
    this->fileName = fileName;
    this->latitude = latitude;
    this->longitude = longitude;
}

void Photo::setLatitude(double latitude) { this->latitude = latitude; }

void Photo::setLongitude(double longitude) { this->longitude = longitude; }

double Photo::getLatitude() { return this->latitude; }

double Photo::getLongitude() { return this->longitude; }

void Photo::displayVar(std::ostream &s) {
    s << "Name of photo : " << this->getName() << std::endl;
    s << "Filename : " << this->getFileName() << std::endl;
    s << "Latitude = " << this->getLatitude() << std::endl;
    s << "Longitude = " << this->getLongitude() << std::endl;
    s << "----------------------------------------" << std::endl;
}
void Photo::display() {
    std::string str{};

    str = "imagej " + this->fileName + " &";

    // std::cout << str.data() << std::endl;
    system(str.data());
}