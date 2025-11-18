#ifndef SONG_H
#define SONG_H

#include <string>

struct Song {
    int length;
    std::string name;
    std::string artist;

    Song(int, const std::string&, const std::string&);
    std::string to_string() const;
};

#endif
