#include <iostream>

#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"

using namespace std;

int main(int argc, const char *argv[]) {
    /* Test for class de base Multimedia */
    Multimedia *movie = new Multimedia();

    movie->setName("Amelie a Paris");
    movie->setFileName("USA");

    movie->displayVar(std::cout);

    /* Test for class Photo */
    Photo *pic = new Photo(
        "C++ Logo",
        "/home/zhuconghui/Documents/INF224/TP/Part_C++/test_files/C++_Logo.png",
        20, 15);

    pic->displayVar(std::cout);
    pic->display();

    /* Test for class Video */
    Video *video = new Video("test_video",
                             "/home/zhuconghui/Documents/INF224/TP/Part_C++/"
                             "test_files/test_video.mp4",
                             50);

    video->displayVar(std::cout);
    video->display();

    return 0;
}