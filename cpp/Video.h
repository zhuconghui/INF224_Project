#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include "Multimedia.h"

using namespace std;

/**
 * @class Video
 * @brief A class representing a video, derived from Multimedia.
 * 
 * The Video class extends the Multimedia class, providing additional
 * functionality specific to videos, such as length in seconds.
 */
class Video : public Multimedia {
   private:
    unsigned int length{}; ///< Length of the video in seconds

   public:
    /**
     * Default constructor for Video.
     */
    Video() {};

    /**
     * Parametrized constructor for Video.
     * 
     * @param name The name of the video.
     * @param fileName The file name of the video.
     * @param length The length of the video in seconds.
     */
    Video(string name, string fileName, unsigned int length) {
        this->setName(name);
        this->setFileName(fileName);
        this->length = length;
    };

    /**
     * Destructor for Video.
     * 
     * Outputs a message when a Video object is destroyed.
     */
    ~Video() override {
        cout << "Video " << this->getName() << " is destroyed" << "\n";
    }

    /**
     * Sets the length of the video.
     * 
     * @param length The length of the video in seconds.
     */
    inline void setLength(unsigned int length) { this->length = length; };

    /**
     * Gets the length of the video.
     * 
     * @return The length of the video in seconds.
     */
    inline double getLength() const { return this->length; };

    /**
     * Displays the video information.
     * 
     * @param s Reference to the output stream.
     */
    void displayInfo(ostream &s) const override {
        s << "Name of video : " << this->getName() << "; ";
        s << "Filename : " << this->getFileName() << "; ";
        s << "Length = " << this->getLength() << "; ";
    };

    /**
     * Plays the video.
     * 
     * Uses system call to open the video file with an external player.
     */
    void play() const override {
        string str = "mpv " + this->getFileName() + " &";
        system(str.data());
    };
};

#endif
