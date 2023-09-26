#include <iostream>

#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"


using namespace std;

int main(int argc, const char *argv[]) {
    /* Test for class de base Multimedia */
    // Multimedia *movie = new Multimedia("a", "b");

    // movie->displayInfo(std::cout);

    // /* Test for class Photo */
    // Photo *pic = new Photo("C++ Logo",
    //                        "/home/zhuconghui/Documents/INF224/INF224_Project/"
    //                        "Part_C++/test_files/C++_Logo.png",
    //                        20, 15);

    // pic->displayInfo(std::cout);
    // pic->display();

    // /* Test for class Video */
    // Video *video = new Video("test_video",
    //                          "/home/zhuconghui/Documents/INF224/INF224_Project/"
    //                          "Part_C++/test_files/test_video.mp4",
    //                          50);

    // video->displayInfo(std::cout);
    // video->display();

    // /* Test for Q5 */
    // Multimedia **multimedias = new Multimedia *[10];
    // for(unsigned int i = 0; i < 10; i++){
    //     if(i < 5){
    //         multimedias[i] =  new Photo();
    //         multimedias[i]->displayInfo(std::cout);
    //     }
    //     else{
    //         multimedias[i] = new Video();
    //         multimedias[i]->displayInfo(std::cout);
    //     }
    // }

    /* Test for Q6*/
    unsigned int *lengthOfChapters = new unsigned int[5]{1, 2, 3, 4, 5};
    Film *film = new Film("test_video",
                          "/home/zhuconghui/Documents/INF224/INF224_Project/"
                          "Part_C++/test_files/test_video.mp4",
                          50, 5, lengthOfChapters);
    film->displayInfo(std::cout);
    delete []lengthOfChapters;

    return 0;
}