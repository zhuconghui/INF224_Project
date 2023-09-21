#include <iostream>

#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"

using namespace std;

int main(int argc, const char *argv[]) {
    /* Test for class de base Multimedia */
    Multimedia *movie = new Multimedia("a", "b");

    movie->displayInfo(std::cout);

    /* Test for class Photo */
    Photo *pic = new Photo("C++ Logo",
                           "/home/zhuconghui/Documents/INF224/INF224_Project/"
                           "Part_C++/test_files/C++_Logo.png",
                           20, 15);

    pic->displayInfo(std::cout);
    pic->display();

    /* Test for class Video */
    Video *video = new Video("test_video",
                             "/home/zhuconghui/Documents/INF224/INF224_Project/"
                             "Part_C++/test_files/test_video.mp4",
                             50);

    video->displayInfo(std::cout);
    video->display();

    return 0;
}