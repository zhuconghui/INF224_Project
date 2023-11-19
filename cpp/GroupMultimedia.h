#ifndef GROUPMULTIMEDIA_H
#define GROUPMULTIMEDIA_H

#include <iostream>
#include <list>
#include <memory>
#include "Multimedia.h"

using namespace std;

/**
 * @class GroupMultimedia
 * @brief This class represents a group of multimedia objects.
 *
 * GroupMultimedia extends the standard list class to hold a collection of multimedia objects.
 * Each multimedia object is managed through shared_ptr, facilitating automatic memory management.
 * The class provides functionalities to set and get the group's name and to display information about all objects in the group.
 */
class GroupMultimedia : public list<shared_ptr<Multimedia>> {
   private:
    string groupName{};

   public:
    /**
     * Default constructor for GroupMultimedia.
     */
    GroupMultimedia(){};

    /**
     * Parameterized constructor for GroupMultimedia.
     * 
     * @param groupName The name of the multimedia group.
     */
    GroupMultimedia(string groupName) {
        this->groupName = groupName;
    }

    /**
     * Destructor for GroupMultimedia.
     * 
     * Outputs a message upon destruction of the object.
     */
    ~GroupMultimedia() {
        cout << "GroupMultimedia " << this->getGroupName() << " is destroyed" << endl;
    }

    /**
     * Gets the name of the multimedia group.
     * 
     * @return The name of the group.
     */
    string getGroupName() const {
        return this->groupName;
    };

    /**
     * Sets the name of the multimedia group.
     * 
     * @param groupName The name to set for the group.
     */
    void setGroupName(string groupName) {
        this->groupName = groupName;
    }

    /**
     * Displays information about all multimedia objects in the group.
     * 
     * @param s The output stream to which the information is written.
     */
    void displayAllObjects(ostream &s) const {
        for (auto &it : *this) {
            it->displayInfo(s);
        }
    }
};

#endif
