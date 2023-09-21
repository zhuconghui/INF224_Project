#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>

class Multimedia {
   protected:
    std::string name{};
    std::string fileName{};

   public:
    Multimedia();
    Multimedia(std::string name, std::string fileName);

    void setName(std::string name);
    void setFileName(std::string fileName);

    std::string getName() const;
    std::string getFileName() const;

    virtual void displayInfo(std::ostream &s);
    virtual void display();

    ~Multimedia();
};

#endif