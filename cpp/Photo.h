#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include "Multimedia.h"

using namespace std;

/**
 * @class Photo
 * @brief A class representing a photo, extending the Multimedia class.
 *
 * This class adds geographical information (latitude and longitude) to the basic
 * multimedia structure. It provides functionalities to set and get these geographic
 * coordinates and to display and open the photo.
 */
class Photo : public Multimedia {
   private:
    double latitude;   ///< Latitude coordinate of the photo.
    double longitude;  ///< Longitude coordinate of the photo.

   public:
    /**
     * Default constructor for Photo.
     */
    Photo(){};

    /**
     * Parameterized constructor for Photo.
     * 
     * @param name The name of the photo.
     * @param fileName The file name of the photo.
     * @param latitude The latitude coordinate of the photo.
     * @param longitude The longitude coordinate of the photo.
     */
    Photo(string name, string fileName, double latitude, double longitude);

    /**
     * Destructor for Photo.
     * Outputs a message upon destruction of the object.
     */
    ~Photo() override;

    /**
     * Sets the latitude coordinate of the photo.
     * 
     * @param latitude The latitude coordinate to set.
     */
    inline void setLatitude(double latitude);

    /**
     * Sets the longitude coordinate of the photo.
     * 
     * @param longitude The longitude coordinate to set.
     */
    inline void setLongitude(double longitude);

    /**
     * Gets the latitude coordinate of the photo.
     * 
     * @return The latitude coordinate of the photo.
     */
    inline double getLatitude() const;

    /**
     * Gets the longitude coordinate of the photo.
     * 
     * @return The longitude coordinate of the photo.
     */
    inline double getLongitude() const;

    /**
     * Displays information about the photo.
     * 
     * @param s The output stream to which the information is written.
     */
    void displayInfo(ostream &s) const override;

    /**
     * Opens the photo using an external application.
     * The method builds and executes a system command to open the photo.
     */
    void play() const override;
};

#endif
