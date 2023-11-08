#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "priority_queue.h"

using namespace std;

class Song {
public:
    std::string artist, title;
    int count;

    Song() {
    }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) {
    }
    Song(std::string artist, std::string title, int count)
        : artist(artist), title(title), count(count) {
    }

    friend std::ostream &operator<<(std::ostream &out, const Song &s) {
        return out << "Artist: " << s.artist << " Title: " << s.title
                   << " count: " << s.count;
    }
};

typedef bool (*Comp)(const Song &s1, const Song &s2);

bool comp1(const Song &l, const Song &r) {
    if (l.artist != r.artist)
        return l.artist > r.artist;
    if (l.title != r.title)
        return l.title > r.title;
    return l.count > r.count;
}

bool comp2(const Song &l, const Song &r) {
    if (l.count != r.count)
        return l.count < r.count;
    if (l.artist != r.artist)
        return l.artist > r.artist;
    return l.title > r.title;
}

//  you have to write something below this line
//  you *MIGHT* have to change the declaration of pq1 and pq2
CP::priority_queue<Song, Comp> pq1(comp1);
CP::priority_queue<Song, Comp> pq2(comp2);

#endif
