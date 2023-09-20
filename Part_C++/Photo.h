#ifndef PHOTO_H
#define PHOTO_H

#include <string>

#include "Multimedia.h"

class Photo : public Multimedia {
   private:
    double latitude{};
    double longitude{};

   public:
    Photo();
    Photo(std::string name, std::string fileName, double latitude,
          double longitude);

    void setLatitude(double latitude);
    void setLongitude(double longitude);

    double getLatitude();
    double getLongitude();

    void displayVar(std::ostream &s) override;
    void display() override;
};

#endif