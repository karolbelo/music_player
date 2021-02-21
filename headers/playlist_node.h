#ifndef PLAYLIST_NODE_H
#define PLAYLIST_NODE_H

#include "playlist.h"

//representa elemento da lista ligada de playlists
class PlaylistNode {
  private:
    Playlist* playlist; //guarda endereço da playlist
    PlaylistNode* next; //guarda endereço da próxima playlist

  public: 
    PlaylistNode* getNext(); //retorna endereço da próxima playlist
    void setNext(PlaylistNode* next); //seta endereço da próxima playlist
    Playlist* getPlaylist(); //retorna endereço da playlist do elemento
    void setPlaylist(Playlist* playlist); //seta endereço da playlist do elemento

    //construtor e destrutor
    PlaylistNode(std::string name);
    ~PlaylistNode();
};

#endif