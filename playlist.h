/*
* playlist.h
* Written by : SENG1120 Staff (c1234567)
* Modified   : 03/08/2023
*
* This class represents the header for a playlist class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 

#ifndef SENG1120_Playlist_H
#define SENG1120_Playlist_H

#include <iostream>
#include "song.h"
#include "linked_list.h"

class Playlist
{
public:

    /*
    * Precondition:    None
    * Postcondition:   A new Playlist is created
    */
    Playlist();

    /*
    * Precondition:    None
    * Postcondition:   The Playlist is destroyed and all associated memory is freed.
    */ 
   ~Playlist();

    /*
    * Add a new Song to the end of the Playlist.
    * By default, the Song should not be a favourite.
    *
    * Assume that no two Song of the same ID will ever be input into the Playlist. 
    * You therefore do not need to handle this case.
    *
    * Precondition: The Playlist is initialised and the Song provided is valid.
    * Postcondition: When a Song is added to the Playlist, the currently selected Song becomes this Song.
    */
    void add_song(Song song);

    /*
    * Print out all the Songs in the Playlist, with an * at the end to denote a favourite:  <id>: <title> by <artist> *
    * This should be printed to std::cout
    * Example:
    * 
    *     #1: Happy_Birthday by Some_Artist *
    *     #4: fdkfjas by Some_Other_Artist
    *     #7: fda by Person
    *
    * The Song should be printed in the order that they were inserted
    * into the Playlist.
    * 
    * If the Playlist is empty, this function display "Playlist is empty".
    * 
    * Precondition: The Playlist is initialised and the Song provided is valid.
    * Postcondition: After this function has completed, the current song should be set to the first song in the playlist.
    */
    void print();

    /*
    * Print out the details of currently selected Song in the form:
    *
    *   ID: 1
    *   Title: Happy_Birthday
    *   Artist: Super_Cool_Singer
    *   Year: 1800
    *   Favourite: 1
    *
    * If the Playlist is empty, this function should display "Playlist is empty".
    * 
    * Precondition:  This function should not be called on an empty Playlist. Current is pointing to a valid Song.
    * Postcondition: Current has not changed.
    */
    void detail_current_song();

    /*
    * Get the currently selected Song.
    *
    * Precondition: This function should not be called on an empty Playlist. Current is pointing to a valid Song.
    * Postcondition: Current has not changed.
    */
    Song& get_current_song();

    /*
    * Change the currently selected Song to be the next in the Playlist.
    *
    * If there are no songs in the Playlist, this function does nothing.
    * 
    * Precondition: Current is pointing to a valid Song.
    * Postcondition: Current has moved to the next Song in the list.
    */
    void next_song();

    /*
    * Change the currently selected song to be the previous in the
    * Playlist.
    *
    * If there are no songs in the Playlist, this function does nothing.
    * 
    * Precondition: Current is pointing to a valid Song.
    * Postcondition: Current has moved to the previous Song in the list
    */
    void prev_song();

    /*
    * "Locate" the song with the specified ID, setting current to this song
    *
    * If there is no song with the specified ID, this function prints:
    * "Could not find a Song with that ID" and the current song is set to 
    * the first Song in the Playlist.
    * 
    * Precondition: None.
    * Postcondition: Current has moved to the Song with the supplied ID, or 
    * is pointing to the first Song, if the ID was not found.
    * 
    */
    void locate_song(int song_id);

    /*
    * Flip the currently selected song's "favourite" status.
    * 
    * If there is no currently selected song, this function does nothing.
    * 
    * Precondition: None.
    * Postcondition: The favourite status of the current song, if any, is flipped.
    */
    void flip_current_favourite();

    /*
    * Inserts a new Song before the currently selected Song in Playlist.
    *
    * If the Playlist is empty, you should insert the Song as the first element 
    * in the Playlist.
    *
    * Assume that no two songs of the same ID will ever be input into the Playlist. 
    * You therefore do not need to handle this case.
    *
    * Precondition:  Current is pointing to a valid Song and the Song provided is valid.
    * Postcondition: The favourite status of the current song, if any, is flipped.
    */
    void insert_song_before_current(Song song);

    /*
    * Remove the currently selected Song from the Playlist.
    *
    * If there are no Song in the Playlist, this function does nothing.
    * 
    * Precondition:  Current is pointing to a valid Song and the Song provided is valid.
    * Postcondition: The current song should then be set to the first song in the playlist.
    */
    void remove_song();

    /*
    * Return the number of songs in the playlist that are favourites.
    *
    * After this function has completed, the current song should be the first in the playlist.
    * 
    * Precondition: None.
    * Postcondition: The current song should then be set to the first song in the playlist.
    */
    int count_favourite_songs();

    /*
    * Return the total number of Songs in the Playlist.
    *
    * 
    * Precondition: None.
    * Postcondition: This should not affect the currently-selected song.
    */
    int count_total_songs();

    /*
    * Create a new Playlist which contains only the songs of a specified
    * artist from the original Playlist.
    * 
    * The songs should appear in this new Playlist in the same order as they
    * appeared in the original Playlist.
    *
    * If there are no matching songs, this function should return an
    * empty Playlist.
    *
    * The songs should appear in this Playlist in the same order as they
    * appeared in the original Playlist.
    * 
    * Precondition: None.
    * Postcondition: The current song should then be set to the first song in the playlist. 
    * This function should not alter the original Playlist (apart from the current song)
    * It should create copies of any songs which are in the original Playlist, and
    * insert those copies into the new Playlist.
    */
    Playlist filter_songs_of_artist(std::string& artist);

    /*
    * Create a new Playlist which contains only the Song that have
    * previously been 'favourited' from the original Playlist.
    *
    * The songs should appear in this new Playlist in the same order as they
    * appeared in the original Playlist.
    *
    * If there are no favourite songs, this function should return an
    * empty Playlist.
    * 
    * Precondition: None.
    * Postcondition: The current song should then be set to the first song in the playlist. 
    * This function should not alter the original Playlist (apart from the current song)
    * It should create copies of any songs which are in the original Playlist, and
    * insert those copies into the new Playlist.
    */
    Playlist filter_favourite_songs();

private:
    LinkedList<Song> playlist;
    
};

#endif
