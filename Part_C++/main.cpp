#define VERSION_2

#include <iostream>

#include "Film.h"
#include "GroupMultimedia.h"
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "MultimediaManager.h"

using namespace std;


#ifdef VERSION_1

int main(int argc, const char *argv[]) {
    // /* Test for class de base Multimedia */
    // Multimedia *movie = new Multimedia("a", "b");

    // movie->displayInfo(cout);

    // /* Test for class Photo */
    // unique_ptr<Photo> pic(new Photo("C++ Logo", "test_files/C++_Logo.png",
    // 20, 15));

    // pic->displayInfo(cout);
    // pic->play();

    // /* Test for class Video */
    // unique_ptr<Video> video(new Video("test_video",
    // "test_files/test_video.mp4", 50));

    // video->displayInfo(cout);
    // video->play();

    // /* Test for Q5 */
    // Multimedia **multimedias = new Multimedia *[10];
    // for(unsigned int i = 0; i < 10; i++){
    //     if(i < 5){
    //         multimedias[i] =  new Photo();
    //         multimedias[i]->displayInfo(cout);
    //     }
    //     else{
    //         multimedias[i] = new Video();
    //         multimedias[i]->displayInfo(cout);
    //     }
    // }

    /* Test for Q6 */
    // unsigned int *lengthOfChapters = new unsigned int[5]{1, 2, 3, 4, 5};
    // unique_ptr<Film> film(new Film("test_video", "test_files/test_video.mp4",
    //                                50, 5, lengthOfChapters));
    // film->play();
    // film->displayInfo(cout);

    /* Test for Q8, Q9*/
    // GroupMultimedia *group1 = new GroupMultimedia("group1");
    // GroupMultimedia *group2 = new GroupMultimedia("group2");

    // shared_ptr<Multimedia> sharedPhoto(
    //     new Photo("C++ Logo", "test_files/C++_Logo.png", 20, 15));
    // shared_ptr<Multimedia> sharedVideo(
    //     new Video("test_video", "test_files/test_video.mp4", 50));

    // group1->push_back(sharedVideo);
    // group1->push_back(sharedPhoto);
    // group2->push_back(sharedVideo);

    // group1->displayAllObjects(cout);
    // group2->displayAllObjects(cout);

    // group1->pop_back();
    // group1->pop_back();
    // group2->pop_back();

    // // group1->displayAllObjects(cout);
    // group2->displayAllObjects(cout);

    // delete group1;
    // delete group2;

    /* Test for Q10 */
    MultimediaManager *manager = new MultimediaManager();
    shared_ptr<Multimedia> photo(manager->createPhoto("C++ Logo", "test_files/C++_Logo.png", 20, 15));
    shared_ptr<Multimedia> video(manager->createVideo("test_video", "test_files/test_video.mp4", 50));
    shared_ptr<GroupMultimedia> groupMultimedia(manager->createGroupMultimedia("groupMultimedia"));

    groupMultimedia->push_back(photo);
    groupMultimedia->push_back(video);

    manager->displayMultimedia("C++ Logo", cout);
    manager->displayMultimedia("test_video", cout);
    manager->displayGroupMultimedia("groupMultimedia", cout);
    manager->playMultimedia("C++ Logo");
    manager->playMultimedia("test_video");

    
    return 0;
}
#endif

#ifdef VERSION_2

#include <sstream>
#include "tcpserver.h"


const int PORT = 3331;

enum command {play, searchObj, searchGrp, noSuchCommand};

map<string, command> tableCommand {
    {"play", play},
    {"searchObj", searchObj},
    {"searchGrp", searchGrp}
};

command getCommand(string command){
    auto it = tableCommand.find(command);
    if(it != tableCommand.end()) {
        return it->second;
    }
    else {
        return noSuchCommand;
    }
}

int main() {
    MultimediaManager *manager = new MultimediaManager();
    shared_ptr<Multimedia> photo(manager->createPhoto("C++_Logo", "test_files/C++_Logo.png", 20, 15));
    shared_ptr<Multimedia> video(manager->createVideo("test_video", "test_files/test_video.mp4", 50));
    shared_ptr<GroupMultimedia> groupMultimedia(manager->createGroupMultimedia("groupMultimedia"));

    groupMultimedia->push_back(photo);
    groupMultimedia->push_back(video);

    auto* server = new TCPServer([&](string const& request, string& response) {
        string action{};
        string name{};
        stringstream ss(request);
        ss >> action; // get the action

        switch (getCommand(action))
        {
        case play:
            ss >> name;
            manager->playMultimedia(name);     
            response = "The request received is play " + name;
            break;
        
        case searchObj:
            ss >> name;
            manager->displayMultimedia(name, cout);
            response = "The request received is search mutimedia object " + name;
            break;

        case searchGrp:
            ss >> name;
            manager->displayGroupMultimedia(name, cout);
            response = "The request received is search mutimedia group " + name;
            break;

        case noSuchCommand:
            response = "The request is illegal";
            break;
        }

        return true;
    });

    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;


}


#endif