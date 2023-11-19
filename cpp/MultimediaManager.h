#ifndef MULTIMEDIAMANAGER_H
#define MULTIMEDIAMANAGER_H

#include <map>
#include <memory>
#include "Photo.h"
#include "Film.h"
#include "Video.h"
#include "Multimedia.h"
#include "GroupMultimedia.h"

using namespace std;

/**
 * @class MultimediaManager
 * @brief Manages multimedia objects and groups.
 *
 * This class is responsible for creating, storing, and managing various multimedia
 * objects (like Photos, Videos, and Films) and groups of multimedia objects. It uses
 * std::map to associate names with multimedia objects and groups for easy retrieval.
 */
class MultimediaManager {
    private: 
        std::map<string, shared_ptr<Multimedia>> dictMultimediaObj{};         ///< Map to store multimedia objects.
        std::map<string, shared_ptr<GroupMultimedia>> dictMultimediaGrp{};   ///< Map to store groups of multimedia objects.

    public:
        /**
         * Creates a Photo object and stores it in the multimedia dictionary.
         * 
         * @param name The name of the photo.
         * @param fileName The file name of the photo.
         * @param latitude The latitude coordinate of the photo.
         * @param longitude The longitude coordinate of the photo.
         * @return A shared_ptr to the created Photo object.
         */
        shared_ptr<Photo> createPhoto(string name, string fileName, double latitude, double longitude);

        /**
         * Creates a Video object and stores it in the multimedia dictionary.
         * 
         * @param name The name of the video.
         * @param fileName The file name of the video.
         * @param length The length of the video.
         * @return A shared_ptr to the created Video object.
         */
        shared_ptr<Video> createVideo(string name, string fileName, unsigned int length);

        /**
         * Creates a Film object and stores it in the multimedia dictionary.
         * 
         * @param name The name of the film.
         * @param fileName The file name of the film.
         * @param length The total length of the film.
         * @param nbChapter The number of chapters in the film.
         * @param lengthOfChapters A pointer to an array containing the length of each chapter.
         * @return A shared_ptr to the created Film object.
         */
        shared_ptr<Film> createFilm(string name, string fileName, unsigned int length,
                                    unsigned int nbChapter, unsigned int *lengthOfChapters);

        /**
         * Creates a GroupMultimedia object and stores it in the group multimedia dictionary.
         * 
         * @param groupName The name of the multimedia group.
         * @return A shared_ptr to the created GroupMultimedia object.
         */
        shared_ptr<GroupMultimedia> createGroupMultimedia(string groupName);

        /**
         * Displays information about a multimedia object.
         * 
         * @param name The name of the multimedia object.
         * @param s The output stream to which the information is written.
         */
        void displayMultimedia(string name, ostream &s);

        /**
         * Displays information about all multimedia objects in a group.
         * 
         * @param name The name of the multimedia group.
         * @param s The output stream to which the information is written.
         */
        void displayGroupMultimedia(string name, ostream &s);

        /**
         * Plays a multimedia object.
         * 
         * @param name The name of the multimedia object to play.
         */
        void playMultimedia(string name);

        // Additional functionalities like deleting multimedia objects and groups can be added here.
};

#endif
