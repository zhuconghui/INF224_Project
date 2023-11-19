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
 * This class manages multimedia objects such as photos, videos, and films,
 * as well as groups of multimedia objects. It allows creation, display,
 * and playback of these objects.
 */

class MultimediaManager {
    private: 
        std::map<string, shared_ptr<Multimedia>> dictMultimediaObj{};
        std::map<string, shared_ptr<GroupMultimedia>> dictMultimediaGrp{};

    public:
        /**
         * Creates and adds a photo to the multimedia collection.
         * 
         * @param name The name of the photo.
         * @param fileName The file name of the photo.
         * @param latitude The latitude where the photo was taken.
         * @param longitude The longitude where the photo was taken.
         * @return A shared pointer to the created photo.
         */
        shared_ptr<Photo> createPhoto(string name, string fileName, double latitude, double longitude){
            shared_ptr<Photo> photo(new Photo(name, fileName, latitude, longitude));

            dictMultimediaObj[name] = photo;

            return photo;
        }
        
        /**
         * Creates and adds a video to the multimedia collection.
         * 
         * @param name The name of the video.
         * @param fileName The file name of the video.
         * @param length The length of the video in seconds.
         * @return A shared pointer to the created video.
         */
        shared_ptr<Video> createVideo(string name, string fileName, unsigned int length){
            shared_ptr<Video> video(new Video(name, fileName, length));

            dictMultimediaObj[name] = video;

            return video;
        }

        /**
         * Creates and adds a film to the multimedia collection.
         * 
         * @param name The name of the film.
         * @param fileName The file name of the film.
         * @param length The total length of the film in seconds.
         * @param nbChapter The number of chapters in the film.
         * @param lengthOfChapters An array with the lengths of each chapter.
         * @return A shared pointer to the created film.
         */
        shared_ptr<Film> createFilm(string name, string fileName, unsigned int length,
                                    unsigned int nbChapter, unsigned int *lengthOfChapters){
            shared_ptr<Film> film(new Film(name, fileName, length, nbChapter, lengthOfChapters));

            dictMultimediaObj[name] = film;

            return film;
        }

         /**
         * Creates and adds a multimedia group to the collection.
         * 
         * @param groupName The name of the multimedia group.
         * @return A shared pointer to the created multimedia group.
         */
        shared_ptr<GroupMultimedia> createGroupMultimedia(string groupName){
            shared_ptr<GroupMultimedia> grpMultimedia(new GroupMultimedia(groupName));

            dictMultimediaGrp[groupName] = grpMultimedia;

            return grpMultimedia;
        }

        /**
         * Displays information about a specific multimedia object.
         * 
         * @param name The name of the multimedia object.
         * @param s The output stream to display the information.
         */
        void displayMultimedia(string name, ostream &s) {
            auto it = dictMultimediaObj.find(name);

            if(it != dictMultimediaObj.end()) {
                it->second->displayInfo(s);
            }
            else {
                cout << "Multimedia " << name << " not found "<< endl;
            }
        }

        /**
         * Displays information about a specific multimedia group.
         * 
         * @param name The name of the multimedia group.
         * @param s The output stream to display the information.
         */
        void displayGroupMultimedia(string name, ostream &s) {
            auto it = dictMultimediaGrp.find(name);

            if(it != dictMultimediaGrp.end()) {
                it->second->displayAllObjects(s);
            }
            else {
                cout << "Group Multimedia " << name << " not found " << endl;
            }
        }

        /**
         * Plays a specific multimedia object.
         * 
         * @param name The name of the multimedia object to play.
         */
        void playMultimedia(string name) {
            auto it = dictMultimediaObj.find(name);

            if(it != dictMultimediaObj.end()) {
                it->second->play();
            }
            else {
                cout << "Multimedia " << name << " not found "<< endl;
            }

        }

        // void deleteMultimediaObj(string name) {
        //     dictMultimediaObj.erase(name);
        // }

        // void deleteMultimediaGrp(string groupName) {

        // }

};

#endif