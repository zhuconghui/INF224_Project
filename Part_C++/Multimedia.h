#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>

using namespace std;


class Multimedia {
   protected:
    string name{};
    string fileName{};

   public:
    Multimedia();
    Multimedia(string name, string fileName);

    void setName(string name);
    void setFileName(string fileName);

    string getName() const;
    string getFileName() const;

    virtual void displayInfo(ostream &s) const  = 0;
    virtual void display() const = 0;

    virtual ~Multimedia();
};

#endif