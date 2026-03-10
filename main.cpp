/*
* main.cpp
* Written by : SENG1120 Staff (c1234567)
* Modified   : 03/08/2023
*
* This class represents the main driver for a playlist program.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 

#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>

#include "playlist.h"

/*
* Display a welcome message.
*/
static void show_welcome() 
{
    std::cout
    << "===========================[ Playlist ]=========================" << std::endl 
    << "                 Welcome to the SENG1120 Playlist!              " << std::endl 
    << "                  Enter ? for a list of commands.               " << std::endl 
    << "================================================================" << std::endl
    << std::endl;
}

/*
* Display a the help menu.
*/
void show_help()
{
    std::cout
    << "============================================[ Commands ]============================================" << std::endl 
    << "  a [id] [artist] [title] [year] " << std::endl 
    << "      Add a song to the playlist" << std::endl 
    << "  p" << std::endl 
    << "      Print all of the songs in the playlist (in the order they were added)" << std::endl 
    << "  d" << std::endl 
    << "      Display details of the currently selected song" << std::endl 
    << "  >" << std::endl 
    << "      Move the cursor to the next song in the playlist" << std::endl 
    << "  <" << std::endl 
    << "      Move the cursor to the previous Song in the playlist" << std::endl 
    << "  l [id]" << std::endl 
    << "      Locate (find) the song with the specified id, setting current to this song" << std::endl 
    << "  i [id] [artist] [title] [year]" << std::endl 
    << "      Insert a song before the currently selected song" << std::endl 
    << "  c" << std::endl 
    << "      Count of the songs that are favourites" << std::endl 
    << "  D" << std::endl 
    << "      Delete (remove) the current song from the playlist" << std::endl 
    << "  f " << std::endl 
    << "      Flip the current song's 'favourite' status (if true, set to false. If false, set to true)" << std::endl 
    << "  n" << std::endl 
    << "      Display the total number of songs in the playlist" << std::endl 
    << "  F" << std::endl 
    << "      Filters the current playlist to only contain only songs that are favourites" << std::endl 
    << "  A [artist]" << std::endl 
    << "      Filters the current playlist to only contain songs that have the specified artist" << std::endl 
    << "  q" << std::endl 
    << "      Quit" << std::endl 
    << "  ?" << std::endl 
    << "      Show this help menu" << std::endl 
    << "=====================================================================================================" << std::endl ;
}

/*
* Present the user with a prompt, returning the user's input command
*/
std::string prompt() 
{
    std::string command;
    std::cout << "Enter command: ";
    //read entire line from cin, not just next token
    std::getline(std::cin, command);

    return command;
}

/*
* Break a command into a vector of tokens (i.e., split by space)
*/
std::vector<std::string> parse_command(std::string& command)
{
    std::vector<std::string> tokens;

    std::istringstream iss(command);
    std::string s;

    while (std::getline(iss, s, ' ')) 
    {
        tokens.push_back(s);
    }

    return tokens;
}

/*
* Wrapper for adding a Song to the playlist. Handles argument parsing and calling the method.
*/
void add_song(Playlist& playlist, std::string& command)
{
    std::vector<std::string> tokens = parse_command(command);
    if (tokens.size() < 5) 
    {
        std::cout << "Invalid add command. Size: " << tokens.size() << std::endl;
        return;
    }

    //tokens[0] is the command, which we can ignore
    int id = std::stoi(tokens[1]);
    std::string artist = tokens[2];
    std::string title = tokens[3];
    int year = std::stoi(tokens[4]);
    
    Song song(id, artist, title, year);
    playlist.add_song(song);

    std::cout << "Added " << title << " to the end of the playlist!" << std::endl;
}

/*
* Wrapper for inserting a Song to the playlist. Handles argument parsing and calling the method.
*/
void insert_song(Playlist& playlist, std::string& command)
{
    std::vector<std::string> tokens = parse_command(command);
    if (tokens.size() < 5) 
    {
        std::cout << "Invalid insert command. Size: " << tokens.size() << std::endl;
        return;
    }

    //tokens[0] is the command, which we can ignore
    int id = std::stoi(tokens[1]);
    std::string artist = tokens[2];
    std::string title = tokens[3];
    int year = std::stoi(tokens[4]);
    
    Song song(id, artist, title, year);

    playlist.insert_song_before_current(song);

    std::cout << "Inserted " << title << " into the playlist before current!" << std::endl;
}

/*
* Wrapper for locating a Song in the playlist. Handles argument parsing and calling the method.
*/
void locate_song(Playlist& playlist, std::string& command)
{
    std::vector<std::string> tokens = parse_command(command);
    if (tokens.size() < 2) 
    {
        std::cout << "Invalid locate command. Size: " << tokens.size() << std::endl;
        return;
    }

    //tokens[0] is the command, which we can ignore
    int id = std::stoi(tokens[1]);

    playlist.locate_song(id);
}

/*
* Wrapper for filtering Songs by artist in the playlist. Handles argument parsing, calling the method, and printing the result.
*/
void filter_by_artist(Playlist& playlist, std::string& command)
{
    std::vector<std::string> tokens = parse_command(command);
    if (tokens.size() < 2) 
    {
        std::cout << "Invalid filter by artist command. Size: " << tokens.size() << std::endl;
        return;
    }

    //tokens[0] is the command, which we can ignore
    //remove the last character, which is a newline
    std::string artist = tokens[1];
    Playlist filtered = playlist.filter_songs_of_artist(artist);

    filtered.print();
}

/*
* Helper method to determine the method to execute based on the command.
* The return value determines whether to continue execution.
*/
bool execute_command(Playlist& playlist, std::string& command)
{
    char cmd = command[0]; //the first character is the command code

    switch (cmd)
    {
    case 'a':
        try
        {
            add_song(playlist, command);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 'p':
        playlist.print();
        break;
    case 'd':
        playlist.detail_current_song();
        break;
    case '>':
        playlist.next_song();
        break;
    case '<':
        playlist.prev_song();
        break;
    case 'l':
        try
        {
            locate_song(playlist, command);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 'i':
        try
        {
            insert_song(playlist, command);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 'c':
        std::cout << "Number of favourite songs: " << playlist.count_favourite_songs() << std::endl;
        break;
    case 'D':
        playlist.remove_song();
        break;
    case 'f':
        playlist.flip_current_favourite();
        break;
    case 'n':
        std::cout << "There are " << playlist.count_total_songs() << " songs in the playlist" << std::endl;
        break;
    case 'F':
    { // enclose the scope of filtered - weird C++ thing!
        Playlist filtered = playlist.filter_favourite_songs();
        filtered.print();
    }
        break;
    case 'A':
        try
        {
            filter_by_artist(playlist, command);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 'q':
        return false; //used to flag that we want to exit
        break;
    case '?':
        show_help();
        break;
    default:
        std::cout << "Unknown command: " << command << std::endl;
        break;
    }

    return true;
}

/*
* Run the program in prompt (interactive) mode, where the commands are supplied by the user.
*/
void run_prompt_mode()
{
    show_welcome();

    Playlist playlist;

    bool do_continue = true;
    // Here, we have a valid reason for a do-while loop
    // This is because we want to always display the prompt at least once
    // and continue only if we didn't use quit!
    do
    {
        std::string command = prompt();
        do_continue = execute_command(playlist, command);
    } while(do_continue);

}

/*
* Run the program in file mode, where the input commands are read from a file.
*/
void run_file_mode(char* file_name)
{
    Playlist playlist;

    std::ifstream infile(file_name);
    std::string command;

    bool do_continue = true;
    //exit if we run out of lines, or encounter the quit command
    while(std::getline(infile, command) && do_continue)
    {
        //remove the newline character
        command = command.substr(0, command.length() - 1);
        std::cout << "Executing command: " << command << std::endl;
        do_continue = execute_command(playlist, command);
    }
}

/*
* The main method. When no arguments are supplied, run in interactive mode. 
* When one argument is supplied, it is assumed to be a valid file of commands, one per line.
*/
int main(int argc, char* argv[])
{
    if(argc > 1)
    {
        std::cout << "Using file " << argv[1] << " as input." << std::endl;
        run_file_mode(argv[1]);
    }
    else
    {
        run_prompt_mode();
    }
    std::cout << "Goodbye!" << std::endl;

    return 0;
}