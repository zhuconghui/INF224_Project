#include <iostream>

#include "Film.h"
#include "GroupMultimedia.h"
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"

using namespace std;

int main(int argc, const char *argv[]) {
    // /* Test for class de base Multimedia */
    // Multimedia *movie = new Multimedia("a", "b");

    // movie->displayInfo(cout);

    // /* Test for class Photo */
    // unique_ptr<Photo> pic(new Photo("C++ Logo", "test_files/C++_Logo.png",
    // 20, 15));

    // pic->displayInfo(cout);
    // pic->display();

    // /* Test for class Video */
    // unique_ptr<Video> video(new Video("test_video",
    // "test_files/test_video.mp4", 50));

    // video->displayInfo(cout);
    // video->display();

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
    // film->display();
    // film->displayInfo(cout);

    /* Test for Q8, Q9*/
    GroupMultimedia *group1 = new GroupMultimedia("group1");
    GroupMultimedia *group2 = new GroupMultimedia("group2");

    shared_ptr<Multimedia> sharedPhoto(new Photo("C++ Logo",
    "test_files/C++_Logo.png", 20, 15)); shared_ptr<Multimedia>
    sharedVideo(new Video("test_video", "test_files/test_video.mp4", 50));

    group1->push_back(sharedVideo);
    group1->push_back(sharedPhoto);
    group2->push_back(sharedVideo);

    group1->displayAllObjects(cout);
    group2->displayAllObjects(cout);

    group1->pop_back();
    group1->pop_back();
    group2->pop_back();

    // group1->displayAllObjects(cout);
    group2->displayAllObjects(cout);

    delete group1;
    delete group2;

    // Demander au prof si on doit ajouter virtual au destrcteur
    return 0;
}