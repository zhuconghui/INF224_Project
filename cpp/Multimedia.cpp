#include "Multimedia.h"

using namespace std;

/**
 * @class Multimedia
 * @brief Base class for multimedia content.
 *
 * This class represents a generic multimedia object, providing basic attributes
 * such as name and file name, along with functionalities to set/get these attributes,
 * display information about the multimedia object, and play it.
 */
Multimedia::Multimedia() {}

/**
 * Parameterized constructor for Multimedia.
 * 
 * @param name The name of the multimedia object.
 * @param fileName The filename associated with the multimedia object.
 */
Multimedia::Multimedia(string name, string fileName) {
    this->name = name;
    this->fileName = fileName;
}

/**
 * Sets the name of the multimedia object.
 * 
 * @param name The name to set for the multimedia object.
 */
void Multimedia::setName(string name) {
    this->name = name;
}

/**
 * Sets the filename of the multimedia object.
 * 
 * @param fileName The filename to set for the multimedia object.
 */
void Multimedia::setFileName(string fileName) {
    this->fileName = fileName;
}

/**
 * Gets the name of the multimedia object.
 * 
 * @return The name of the multimedia object.
 */
string Multimedia::getName() const {
    return this->name;
}

/**
 * Gets the filename of the multimedia object.
 * 
 * @return The filename of the multimedia object.
 */
string Multimedia::getFileName() const {
    return this->fileName;
}

/**
 * Displays information about the multimedia object.
 * 
 * @param s The output stream to which the information is written.
 * This method is intended to be overridden in derived classes.
 */
void Multimedia::displayInfo(ostream &s) const {}

/**
 * Plays the multimedia content.
 * This method is intended to be overridden in derived classes.
 */
void Multimedia::play() const {}

/**
 * Destructor for Multimedia.
 * Outputs a message upon destruction of the object.
 */
Multimedia::~Multimedia() {
    cout << "Multimedia " << this->getName() << " is destroyed" << endl;
}
