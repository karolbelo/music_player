#include <iostream>
#include "linked_list.h"
#include "playlist.h"

//insere música na playlist
void Playlist::insertMusic(Music* music) {
  linked_list->insert(music->getTitle(), music->getArtistName());

  /*
    playing_music vai receber a primeira música,
    quando ela for adicionada à playlist
  */
  if (this->linked_list->getListSize() == 1) {
    playing_music = this->linked_list->getFirstNode();
  }
}

//remove música da playlist por título
void Playlist::removeMusic(std::string music_title, bool show_success_message) {
  linked_list->remove(music_title, show_success_message);
}

//imprime todas as músicas da playlist por recursão
void Playlist::listAll(Node* node) {
  //caso base
  if (node == nullptr) {
    return;
  } else {
    Music* music = node->getMusic();
    std::cout << music->getTitle() << " - " << music->getArtistName() << std::endl;
    //chamada recursiva
    listAll(node->getNext());
  }
}

//imprime música que está tocando
Node* Playlist::playNext() {
  //verifica se playlist está vazia
  if (linked_list->getListSize() == 0) {
    std::cout << "Nenhuma música foi adicionada à playlist." << std::endl << std::endl;
    return nullptr;
  } else if (playing_music != nullptr) { //verifica se mpusica atual é diferente de null
    Node* temp = playing_music;
    Music* music = temp->getMusic();
    playing_music = playing_music->getNext();

    std::cout << "Tocando: \n" << music->getTitle() << " - " << music->getArtistName() << std::endl;
    return temp;
  } else {
    //se playing_music for null, quer dizer que chegou ao fim da playlist
    playing_music = linked_list->getFirstNode();

    std::cout << "Fim da playlist" << std::endl;
    return nullptr;
  }
}

//retorna nome da playlist
std::string Playlist::getName() {
  return this->name;
}

//seta nome da playlist
void Playlist::setName(std::string name) {
  this->name = name;
}

//retorna lista com músicas da playlist
LinkedList* Playlist::getLinkedList() {
  return this->linked_list;
}
    
//construtor com parametro
Playlist::Playlist(std::string name) {
  //inicializa nome, linked_list e playing_music 
  this->name = name;
  linked_list = new LinkedList();
  playing_music = nullptr;
}

//destrutor
Playlist::~Playlist() {
  delete linked_list;
}