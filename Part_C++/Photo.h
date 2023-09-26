#ifndef PHOTO_H
#define PHOTO_H

#include <string>

#include "Multimedia.h"

class Photo : public Multimedia {
   protected:
    double latitude{};
    double longitude{};

   public:
    Photo(){};
    Photo(std::string name, std::string fileName, double latitude,
          double longitude) {
        this->name = name;
        this->fileName = fileName;
        this->latitude = latitude;
        this->longitude = longitude;
    };

    inline void setLatitude(double latitude) { this->latitude = latitude; };
    inline void setLongitude(double longitude) { this->longitude = longitude; };

    inline double getLatitude() const { return this->latitude; };
    inline double getLongitude() const { return this->longitude; };

    void displayInfo(std::ostream &s) const override {
        s << "Name of photo : " << this->getName() << std::endl;
        s << "Filename : " << this->getFileName() << std::endl;
        s << "Latitude = " << this->getLatitude() << std::endl;
        s << "Longitude = " << this->getLongitude() << std::endl;
        s << "----------------------------------------" << std::endl;
    };
    void display() const override {
        std::string str{};

        str = "imagej " + this->fileName + " &";

        // std::cout << str.data() << std::endl;
        system(str.data());
    };
};

#endif