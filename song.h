/*
* Song.h
* Written by : SENG1120 Staff (c1234567)
* Modified   : 03/08/2023
*
* This class represents the header for a Song class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 

#ifndef SENG1120_SONG_H
#define SENG1120_SONG_H

#include <string>

class Song
{
public:

    /*
    * Precondition:    None
    * Postcondition:   A new Song is created, with all variables initialised to their default values.
    */
    Song();

    /*
    * Precondition:    None
    * Postcondition:   A new Song is created, with the specified ID, and all other variables initialised to their default values.
    */
    Song(int _id);

    /*
    * Precondition:    None
    * Postcondition:   A new Song is created, with the specified attributes, and all other variables initialised to their default values.
    */
    Song(int _id, std::string _artist, std::string _title,  int _year);

    /*
    * Precondition:    None
    * Postcondition:   The Song is destroyed and all associated memory is freed.
    */
    ~Song();

    /*
    * Precondition:    The id has been initialised.
    * Postcondition:   The value of the id is returned.
    */
    int get_id() const;

    /*
    * Precondition:    The year has been initialised.
    * Postcondition:   The value of the year is returned.
    */
    int get_year() const;

    /*
    * Precondition:    The title has been initialised.
    * Postcondition:   A const reference to the title is returned.
    */
    const std::string& get_title() const;

    /*
    * Precondition:    The artist has been initialised.
    * Postcondition:   A const reference to the artist is returned.
    */
    const std::string& get_artist() const;

    /*
    * Precondition:    The favourite status has been initialised.
    * Postcondition:   The favourite status is returned.
    */
    bool get_favourite() const;

    /*
    * Precondition:    The favourite status has been initialised.
    * Postcondition:   Flips the favourite status from true to false, or false to true.
    */
    void flip_favourite();

    /*
    * Precondition:    The song is initialised and the other song is valid.
    * Postcondition:   Returns true if the two songs have the same ID, false otherwise.
    */
    bool operator== (const Song& other) const;

private:
    int id;             // A unique identifier
    std::string title;  // The name of the song
    int year;           // The year the song was released
    std::string artist; // The artist
    bool favourite;     // The favourite status -> true if the song is a favourite of the user
};

#endif