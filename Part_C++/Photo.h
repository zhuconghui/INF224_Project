#ifndef PHOTO_H
#define PHOTO_H

#include <string>

#include "Multimedia.h"

using namespace std;

class Photo : public Multimedia {
   private:
    double latitude{};
    double longitude{};

   public:
    Photo(){};
    Photo(string name, string fileName, double latitude, double longitude) {
        this->setName(name);
        this->setFileName(fileName);
        this->latitude = latitude;
        this->longitude = longitude;
    };

    ~Photo() override {
        cout << "Photo " << this->getName() << " is destroyed" << endl;
    }

    inline void setLatitude(double latitude) { this->latitude = latitude; };
    inline void setLongitude(double longitude) { this->longitude = longitude; };

    inline double getLatitude() const { return this->latitude; };
    inline double getLongitude() const { return this->longitude; };

    void displayInfo(ostream &s) const override {
        s << "Name of photo : " << this->getName() << endl;
        s << "Filename : " << this->getFileName() << endl;
        s << "Latitude = " << this->getLatitude() << endl;
        s << "Longitude = " << this->getLongitude() << endl;
        s << "----------------------------------------" << endl;
    };
    void play() const override {
        string str{};

        str = "imagej " + this->getFileName() + " &";

        // cout << str.data() << endl;
        system(str.data());
    };
};

#endif