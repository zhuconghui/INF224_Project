#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include "Multimedia.h"

using namespace std;

/**
 * @class Video
 * @brief A class representing a video, extending the Multimedia class.
 *
 * This class adds an attribute to store the length of a video. It includes
 * methods to set and get this length, display video information, and play
 * the video using an external application.
 */
class Video : public Multimedia {
   private:
    unsigned int length;  ///< Length of the video in seconds.

   public:
    /**
     * Default constructor for Video.
     */
    Video(){};

    /**
     * Parameterized constructor for Video.
     * 
     * @param name The name of the video.
     * @param fileName The file name of the video.
     * @param length The length of the video in seconds.
     */
    Video(string name, string fileName, unsigned int length);

    /**
     * Destructor for Video.
     * Outputs a message upon destruction of the object.
     */
    ~Video() override;

    /**
     * Sets the length of the video.
     * 
     * @param length The length of the video in seconds.
     */
    inline void setLength(unsigned int length);

    /**
     * Gets the length of the video.
     * 
     * @return The length of the video in seconds.
     */
    inline double getLength() const;

    /**
     * Displays information about the video.
     * 
     * @param s The output stream to which the information is written.
     */
    void displayInfo(ostream &s) const override;

    /**
     * Plays the video using an external application.
     * The method builds and executes a system command to play the video.
     */
    void play() const override;
};

#endif
