#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "linked_list.h"

//representa uma playlist
class Playlist {
  private:
    std::string name; //nome da playlist
    LinkedList* linked_list; //lista ligada de músicas da playlist
    Node* playing_music; //música que está tocando no momento

  public:
    void insertMusic(Music* music); //insere música na playlist
    void removeMusic(std::string music_title, bool show_success_message); //remove música da playlist por título
    void listAll(Node* node); //lista todas as músicas da playlist
    Node* playNext(); //toca músicas da playlist

    std::string getName(); //retorna nome da playlist
    void setName(std::string name); //seta nome da playlist
    LinkedList* getLinkedList(); //retorna lista com músicas da playlist

    //construtor e destrutor
    Playlist(std::string name);
    ~Playlist();
};

#endif