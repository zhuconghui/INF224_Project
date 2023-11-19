#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include "Multimedia.h"

using namespace std;

/**
 * @class Photo
 * @brief A class representing a photo, derived from Multimedia.
 * 
 * The Photo class extends the Multimedia class, providing additional
 * functionality specific to photos, such as geographic location coordinates.
 */
class Photo : public Multimedia {
   private:
    double latitude{};  ///< Latitude of the photo's location
    double longitude{}; ///< Longitude of the photo's location

   public:
    /**
     * Default constructor for Photo.
     */
    Photo(){};

    /**
     * Parametrized constructor for Photo.
     * 
     * @param name The name of the photo.
     * @param fileName The file name of the photo.
     * @param latitude The latitude of the photo's location.
     * @param longitude The longitude of the photo's location.
     */
    Photo(string name, string fileName, double latitude, double longitude) {
        this->setName(name);
        this->setFileName(fileName);
        this->latitude = latitude;
        this->longitude = longitude;
    };

    /**
     * Destructor for Photo.
     * 
     * Outputs a message when a Photo object is destroyed.
     */
    ~Photo() override {
        cout << "Photo " << this->getName() << " is destroyed" << "\n";
    }

    /**
     * Sets the latitude of the photo's location.
     * 
     * @param latitude The latitude to be set.
     */
    inline void setLatitude(double latitude) { this->latitude = latitude; };

    /**
     * Sets the longitude of the photo's location.
     * 
     * @param longitude The longitude to be set.
     */
    inline void setLongitude(double longitude) { this->longitude = longitude; };

    /**
     * Gets the latitude of the photo's location.
     * 
     * @return The latitude of the photo's location.
     */
    inline double getLatitude() const { return this->latitude; };

    /**
     * Gets the longitude of the photo's location.
     * 
     * @return The longitude of the photo's location.
     */
    inline double getLongitude() const { return this->longitude; };

    /**
     * Displays the photo information.
     * 
     * @param s Reference to the output stream.
     */
    void displayInfo(ostream &s) const override {
        s << "Name of photo : " << this->getName() << "; ";
        s << "Filename : " << this->getFileName() << "; ";
        s << "Latitude = " << this->getLatitude() << "; ";
        s << "Longitude = " << this->getLongitude() << "; ";
    };

    /**
     * Displays the photo.
     * 
     * Uses system call to open the photo file with an external viewer.
     */
    void play() const override {
        string str = "imagej " + this->getFileName() + " &";
        system(str.data());
    };
};

#endif
