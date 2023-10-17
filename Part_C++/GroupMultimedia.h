#ifndef GROUPMULTIMEDIA_H
#define GROUPMULTIMEDIA_H

#include <iostream>
#include <list>
#include <memory>

#include "Multimedia.h"

using namespace std;

class GroupMultimedia : public list<shared_ptr<Multimedia>> {
   private:
    string groupName{};

   public:
    GroupMultimedia(){};

    GroupMultimedia(string groupName) { this->groupName = groupName; }

    ~GroupMultimedia() {
        cout << "GroupMultimedia " << this->getGroupName() << " is destroyed"
             << endl;
    }

    string getGroupName() const { return this->groupName; };

    void setGroupName(string groupName) { this->groupName = groupName; }

    void displayAllObjects(ostream &s) const {
        /* '&' is optionnal, more faster if '&' added*/
        for (auto &it : *this) it->displayInfo(s);
    }
};

#endif