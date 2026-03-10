/*
* playlist.cpp
* Written by : 
* Modified   :
*
* This class represents the implementation for a playlist class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 

#include "playlist.h"


Playlist::Playlist()
{
 
}

Playlist::~Playlist()
{

}

void Playlist::add_song(Song song)
{
    
   playlist.push_back(song); 
   get_current_song();
   
}


void Playlist::print()
{
    if (playlist.empty())
    {
        std::cout << "Playlist is Empty" << std::endl;
        return;
    }

    int count = 1;
    Song currentSong = playlist.get_current();
    std::cout << "#" << count << ": " << currentSong.get_title() << " by " << currentSong.get_artist();

    if (currentSong.get_favourite())
    {
        std::cout << " *";
    }

    std::cout << std::endl;
}


void Playlist::detail_current_song()
{
    if (playlist.empty())
    {
        std::cout<< "Playlist is Empty"<<std::endl;
        return;
    }

    Song currentSong = get_current_song();
    std::cout<< "ID :"<< currentSong.get_id()<<std::endl;
    std::cout<< "Title :"<< currentSong.get_title()<<std::endl;
    std::cout<< "Artist :"<< currentSong.get_artist()<<std::endl;
    std::cout<< "Year :"<< currentSong.get_year()<<std::endl;
    std::cout<< "Favourite :"<<(currentSong.get_favourite() ? "1" : "0")<<std::endl;
    
}



Song& Playlist::get_current_song()
{
    if (playlist.empty()) {
        throw std::runtime_error("exception thrown");
    }

    return playlist.get_current();
}






void Playlist::next_song()
{
 
   Song currentSong = get_current_song();
   return playlist.forward();
}




void Playlist::prev_song()
{
   Song currentSong = get_current_song();
   return playlist.backward();
}



void Playlist::locate_song(int song_id)
{
   Song currentSong = get_current_song();

   if (currentSong.get_id() == song_id){
    playlist.forward();
    return;
    }
    else if (currentSong.get_id() != song_id){
        std::cout<< "Could not find a Song with that ID" <<std::endl;
        playlist.begin();
    }

}




void Playlist::flip_current_favourite()
{
    Song currentSong = get_current_song();
    currentSong.flip_favourite();
}



void Playlist::insert_song_before_current(Song song)
{
    Song currentSong = get_current_song();
    if(playlist.empty()){
        playlist.push_front(song);
    }
    currentSong.flip_favourite();
}




void Playlist::remove_song()
{
   Song currentSong = get_current_song();
    playlist.remove();
    playlist.begin();
}




int Playlist::count_favourite_songs()
{
    int count = 0;

    playlist.begin();

    while (true)
    {
        Song currentSong = get_current_song();

        if (currentSong.get_favourite())
        {
            count++;
        }

        playlist.forward();

        
        if (playlist.get_current() == Song()) {
            break; 
        }
    }

    return count;
}






int Playlist::count_total_songs()
{
  int totalSongs = playlist.size();
  return totalSongs;

}



Playlist Playlist::filter_songs_of_artist(std::string& artist)
{
    Playlist result;
    playlist.begin();

    while (true)
    {
        Song currentSong = get_current_song();

        if (currentSong.get_artist() == artist)
        {
            result.add_song(currentSong);
        }

        if (playlist.get_current() == Song())
        {
            break; 
        }

        playlist.forward();
    }

    return result; 
}





Playlist Playlist::filter_favourite_songs()
{
    Playlist result;
    playlist.begin();

    while (true)
    {
        Song currentSong = get_current_song();

        if (currentSong.get_favourite())
        {
            result.add_song(currentSong);
        }
        if (!currentSong.get_favourite())
        
        {
            return Playlist();
        }

        playlist.forward();
    }

    return result; 
}



/**/