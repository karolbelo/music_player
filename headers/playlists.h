#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include "playlist_node.h"

//representa uma lista ligada que guarda todas as playlists criadas
class Playlists {
  private:
    PlaylistNode* first_playlist; //guarda endereço da primeira playlist
    PlaylistNode* last_playlist; //guarda endereço da última playlist
    size_t playlists_count; //contador de playlist

  public:
    void insert(std::string name); //insere playlist por nome
    void remove(std::string name); //remove playlist por nome
    void removeMusicFromAll(std::string music_title); //remove música de playlist(s)
    PlaylistNode* search(std::string name, bool show_not_found_message); //procura playlist por nome
    void listAll(); //lista todas as playlists

    //contador e destrutor
    Playlists();
    ~Playlists();
};

#endif