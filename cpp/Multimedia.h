#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @class Multimedia
 * @brief Abstract base class for multimedia objects.
 *
 * This class defines the basic structure and functionalities for different types of
 * multimedia content. It includes attributes for name and file name, along with
 * pure virtual functions for displaying information and playing the content, which
 * must be implemented by derived classes.
 */
class Multimedia {
   private:
    string name;      ///< Name of the multimedia object.
    string fileName;  ///< File name associated with the multimedia object.

   public:
    /**
     * Default constructor for Multimedia.
     */
    Multimedia();

    /**
     * Parameterized constructor for Multimedia.
     * 
     * @param name The name of the multimedia object.
     * @param fileName The filename associated with the multimedia object.
     */
    Multimedia(string name, string fileName);

    /**
     * Sets the name of the multimedia object.
     * 
     * @param name The name to set for the multimedia object.
     */
    void setName(string name);

    /**
     * Sets the filename of the multimedia object.
     * 
     * @param fileName The filename to set for the multimedia object.
     */
    void setFileName(string fileName);

    /**
     * Gets the name of the multimedia object.
     * 
     * @return The name of the multimedia object.
     */
    string getName() const;

    /**
     * Gets the filename of the multimedia object.
     * 
     * @return The filename of the multimedia object.
     */
    string getFileName() const;

    /**
     * Pure virtual function to display information about the multimedia object.
     * Must be implemented by derived classes.
     * 
     * @param s The output stream to which the information is written.
     */
    virtual void displayInfo(ostream &s) const = 0;

    /**
     * Pure virtual function to play the multimedia content.
     * Must be implemented by derived classes.
     */
    virtual void play() const = 0;

    /**
     * Virtual destructor for Multimedia.
     */
    virtual ~Multimedia();
};

#endif
