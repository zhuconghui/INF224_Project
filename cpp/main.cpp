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

/**
 * Main function for VERSION_1.
 * Contains tests and demonstrations for various functionalities of the multimedia classes.
 */

int main(int argc, const char *argv[]) {
    /* Test for class de base Multimedia */
    // Multimedia *movie = new Multimedia("a", "b");

    // movie->displayInfo(cout);

    /* Test for class Photo */
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
    // MultimediaManager *manager = new MultimediaManager();
    // shared_ptr<Multimedia> photo(manager->createPhoto("C++ Logo", "test_files/C++_Logo.png", 20, 15));
    // shared_ptr<Multimedia> video(manager->createVideo("test_video", "test_files/test_video.mp4", 50));
    // shared_ptr<GroupMultimedia> groupMultimedia(manager->createGroupMultimedia("groupMultimedia"));

    // groupMultimedia->push_back(photo);
    // groupMultimedia->push_back(video);

    // manager->displayMultimedia("C++ Logo", cout);
    // manager->displayMultimedia("test_video", cout);
    // manager->displayGroupMultimedia("groupMultimedia", cout);
    // manager->playMultimedia("C++ Logo");
    // manager->playMultimedia("test_video");

    return 0;
}
#endif

#ifdef VERSION_2

#include <sstream>
#include "tcpserver.h"


const int PORT = 3331;

/**
 * Enumeration of available commands for server interaction.
 */
enum command {play, searchObj, searchGrp, noSuchCommand};

/**
 * Map to associate string commands with their corresponding enum values.
 */
map<string, command> tableCommand {
    {"play", play},
    {"searchObj", searchObj},
    {"searchGrp", searchGrp}
};

/**
 * Helper function to convert string to command enum.
 * 
 * @param command The command as a string.
 * @return The corresponding command enum, or noSuchCommand if not found.
 */
command getCommand(string command){
    auto it = tableCommand.find(command);
    if(it != tableCommand.end()) {
        return it->second;
    }
    else {
        return noSuchCommand;
    }
}

/**
 * Main function for VERSION_2.
 * Sets up a MultimediaManager and a TCPServer to handle multimedia requests.
 */
int main() {
    MultimediaManager *manager = new MultimediaManager();
    shared_ptr<Multimedia> photo(manager->createPhoto("C++_Logo", "test_files/C++_Logo.png", 20, 15));
    shared_ptr<Multimedia> video(manager->createVideo("test_video", "test_files/test_video.mp4", 50));
    shared_ptr<GroupMultimedia> groupMultimedia(manager->createGroupMultimedia("groupMultimedia"));
    groupMultimedia->push_back(photo);
    groupMultimedia->push_back(video);

    // groupMultimedia->displayAllObjects(cout);
    auto* server = new TCPServer([&](string const& request, string& response) {
        string action{};
        string name{};
        istringstream iss(request);
        iss >> action; // get the action

        stringstream res_stream = stringstream();

        switch (getCommand(action))
        {
        case play:
            iss >> name;
            res_stream.str("");
            res_stream.clear();
            manager->playMultimedia(name);  
            res_stream << name << " is playing...\n";   
            response = res_stream.str();
            break;
        
        case searchObj:
            iss >> name;
            res_stream.str("");
            res_stream.clear();
            manager->displayMultimedia(name, res_stream);
            // response = "The request received is search mutimedia object " + name;
            response = res_stream.str();
            cout << response << endl;
            break;

        case searchGrp:
            iss >> name;
            res_stream.str("");
            res_stream.clear();
            manager->displayGroupMultimedia(name, res_stream);
            // response = "The request received is search mutimedia group " + name;
            response = res_stream.str();
            cout << response << endl;
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