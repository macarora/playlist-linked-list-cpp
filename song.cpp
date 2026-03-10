/*
* Song.cpp
* Written by : SENG1120 Staff (c1234567)
* Modified   : 03/08/2023
*
* This class represents the implementation for a Song class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 


#include "song.h"

Song::Song()
{
    //empty constructor
}

Song::Song(int _id)
{
    id = _id;
}

Song::Song(int _id, std::string _artist, std::string _title, int _year)
{
    id = _id;
    title = _title;
    year = _year;
    artist = _artist;
    favourite = false;
}

Song::~Song()
{ 
    //empty destructor
}


int Song::get_id() const
{
    return id;
}

int Song::get_year() const
{
    return year;
}

const std::string& Song::get_title() const
{
    return title;
}

const std::string& Song::get_artist() const
{
    return artist;
}

bool Song::get_favourite() const
{
    return favourite;
}

void Song::flip_favourite()
{
    favourite = !favourite;
}

bool Song::operator==(const Song& other) const
{
    return id == other.id;
}
