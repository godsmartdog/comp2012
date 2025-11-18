#include "Song.h"

Song::Song(int length, const std::string &name, const std::string &artist) : length(length), name(name), artist(artist) {}

std::string Song::to_string() const {
    return "Song: \"" + name + "\" by " + artist + "; Length: " + std::to_string(length) + " second(s)";
}