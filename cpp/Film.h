#ifndef FILM_H
#define FILM_H

#include <string>
#include "Video.h"

using namespace std;

/**
 * @class Film
 * @brief The Film class extends the Video class with specific attributes for films.
 *
 * This class represents a film with attributes like the number of chapters
 * and their respective lengths. It provides functionalities to set and get these
 * attributes, display film information, and play the film.
 */
class Film : public Video {
   private:
    unsigned int nbChapter{};
    unsigned int *lengthOfChapters = nullptr;

   public:
    /**
     * Default constructor for Film.
     */
    Film(){};

    /**
     * Parameterized constructor for Film.
     * 
     * @param name The name of the film.
     * @param fileName The file name of the film.
     * @param length The total length of the film.
     * @param nbChapter The number of chapters in the film.
     * @param lengthOfChapters A pointer to an array containing the length of each chapter.
     */
    Film(string name, string fileName, unsigned int length,
         unsigned int nbChapter, unsigned int *lengthOfChapters) {
        this->setName(name);
        this->setFileName(fileName);
        this->setLength(length);
        this->nbChapter = nbChapter;
        this->lengthOfChapters = lengthOfChapters;
    };

    /**
     * Destructor for Film.
     * 
     * Frees the memory allocated for lengthOfChapters.
     */
    ~Film() override {
        delete[] lengthOfChapters;
        cout << "Film " << this->getName() << " is destroyed" << endl;
    }

    /**
     * Sets the number of chapters in the film.
     * 
     * @param nbChapter The number of chapters to set.
     */
    inline void setNbChapter(unsigned int nbChapter) {
        this->nbChapter = nbChapter;
    };

    /**
     * Sets the lengths of the chapters.
     * 
     * @param lengthOfChapters A pointer to an array containing the lengths of the chapters.
     */
    inline void setLengthOfChapters(unsigned int *lengthOfChapters) {
        this->lengthOfChapters = lengthOfChapters;
    };

    /**
     * Gets the number of chapters in the film.
     * 
     * @return The number of chapters.
     */
    inline double getNbChapter() const { return this->nbChapter; };

    /**
     * Gets the lengths of the chapters in the film.
     * 
     * @return A pointer to an array containing the lengths of the chapters.
     */
    inline unsigned int *getLengthOfChapters() const {
        return this->lengthOfChapters;
    };

    /**
     * Displays information about the film.
     * 
     * @param s The output stream to which the information is written.
     */
    void displayInfo(ostream &s) const override {
        s << "Name of film : " << this->getName() << "; ";
        s << "Filename : " << this->getFileName() << "; ";
        s << "Length = " << this->getLength() << "; ";
        s << "Number of chapter = " << this->getNbChapter() << "; ";
        for (unsigned int i = 0; i < getNbChapter(); i++) {
            s << "Length of chapter " << i << " = "
              << this->getLengthOfChapters()[i] << "; ";
        }
    };

    /**
     * Plays the film using an external player.
     * 
     * Utilizes the 'mpv' player to play the film. This method builds the command
     * and executes it using the system call.
     */
    void play() const override {
        string str{};
        str = "mpv " + this->getFileName() + " &";
        system(str.data());
    };
};

#endif
