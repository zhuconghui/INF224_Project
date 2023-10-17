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

class MultimediaManager {
    private: 
        std::map<string, shared_ptr<Multimedia>> dictMultimediaObj{};
        std::map<string, shared_ptr<GroupMultimedia>> dictMultimediaGrp{};

    public:
        shared_ptr<Photo> createPhoto(string name, string fileName, double latitude, double longitude){
            shared_ptr<Photo> photo(new Photo(name, fileName, latitude, longitude));

            dictMultimediaObj[name] = photo;

            return photo;
        }

        shared_ptr<Video> createVideo(string name, string fileName, unsigned int length){
            shared_ptr<Video> video(new Video(name, fileName, length));

            dictMultimediaObj[name] = video;

            return video;
        }

        shared_ptr<Film> createFilm(string name, string fileName, unsigned int length,
                                    unsigned int nbChapter, unsigned int *lengthOfChapters){
            shared_ptr<Film> film(new Film(name, fileName, length, nbChapter, lengthOfChapters));

            dictMultimediaObj[name] = film;

            return film;
        }

        shared_ptr<GroupMultimedia> createGroupMultimedia(string groupName){
            shared_ptr<GroupMultimedia> grpMultimedia(new GroupMultimedia(groupName));

            dictMultimediaGrp[groupName] = grpMultimedia;

            return grpMultimedia;
        }

        void displayMultimedia(string name, ostream &s) {
            auto it = dictMultimediaObj.find(name);

            if(it != dictMultimediaObj.end()) {
                it->second->displayInfo(s);
            }
            else {
                cout << "Multimedia " << name << " not found "<< endl;
            }
        }

        void displayGroupMultimedia(string name, ostream &s) {
            auto it = dictMultimediaGrp.find(name);

            if(it != dictMultimediaGrp.end()) {
                it->second->displayAllObjects(s);
            }
            else {
                cout << "Group Multimedia " << name << " not found " << endl;
            }
        }

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