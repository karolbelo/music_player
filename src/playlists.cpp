#include <iostream>

#include "playlist_node.h"
#include "playlists.h"

//insere playlist por nome
void Playlists::insert(std::string name) {
  PlaylistNode* playlist =  this->search(name, false);

  //verifica se já existe uma playlist com o nome informado
  if (playlist == nullptr) {
    //verifica se existe pelo menos uma playlist
    if (first_playlist != nullptr) {
      //cria uma nova playlist
      PlaylistNode* new_playlist = new PlaylistNode(name);
      
      last_playlist->setNext(new_playlist);
      last_playlist = new_playlist;
    } else {
      //cria a primeira playlist
      PlaylistNode* other = new PlaylistNode(name);
      
      first_playlist = other;
      last_playlist = other;
    }

    //incrementa tamanho da lista de playlists
    playlists_count++;
    std::cout << "Playlist criada com sucesso!" << std::endl << std::endl;
  } else {
    std::cout << "Já existe uma playlist com esse nome. Por favor, crie playlists com nomes únicos." 
    << std::endl << std::endl;
  }
}

//remove playlist por nome
void Playlists::remove(std::string name) {
  PlaylistNode* playlist =  this->search(name, false);
  PlaylistNode* first = first_playlist;
  PlaylistNode* last = last_playlist;
  PlaylistNode* current_playlist = first;
  PlaylistNode* aux = playlist;
  PlaylistNode* prev = nullptr;

  if (playlist != nullptr) {
    /*
      se a lista tiver só uma playlist,
      seta o primeiro e o ultimo elemento como null
    */
    if (playlists_count == 1) {
      first_playlist = nullptr;
      last_playlist = nullptr;
    } else {
      //percorre elementos da lista
      while (current_playlist <= aux) {
        if (current_playlist == playlist) {
          //se for o primeiro elemento
          if (playlist == first) {
            first_playlist = playlist->getNext();
          } else if (playlist == last) {
            //se for o último elemento
            prev->setNext(nullptr);
            last_playlist = prev;
          } else {
            prev->setNext(current_playlist->getNext());
          }
          break;
        }
        prev = current_playlist;
        current_playlist = current_playlist->getNext();
      }
    }
    //deleta playlist
    delete playlist;
    //decrementa contador de playlists
    playlists_count--;

    std::cout << "Playlist removida com sucesso!" << std::endl << std::endl;
  }
}

//procura playlist por nome
PlaylistNode* Playlists::search(std::string name, bool show_not_found_message) {
  PlaylistNode* first = first_playlist;
  PlaylistNode* playlist_position = nullptr;

  //verifica se lista tem pelo menos uma playlist
  if (first != nullptr) {
    while (first != nullptr) {
      //verifica igualdade de nome da playlist
      if (first->getPlaylist()->getName() == name) {
        playlist_position = first;
        break;
      }
      first = first->getNext();
    }

    //se a playlist existir, retorna seu endereço
    if (playlist_position != nullptr) {
      return playlist_position;
    } else {
      if (show_not_found_message) {
        std::cout << "Playlist não encontrada." << std::endl << std::endl;
      }
      return nullptr;
    }
  } else {
    if (show_not_found_message) {
      std::cout << "Nenhuma playlist foi criada ainda." << std::endl << std::endl;
    }
    return nullptr;
  }
}

//lista todas as playlist criadas
void Playlists::listAll() {
  PlaylistNode* first = first_playlist;

  //verifica se lista está vazia
  if (playlists_count == 0) {
    std::cout << "Nenhuma playlist foi criada ainda." << std::endl << std::endl;
    return;
  } else {
    //lista todas as playlists
    std::cout << "Playlists criadas:" << std::endl;
    while (first != nullptr) {
      std::cout << first->getPlaylist()->getName() << std::endl;
      first = first->getNext();
    }
  }
}

//remove música de playlists por título
void Playlists::removeMusicFromAll(std::string music_title) {
  PlaylistNode* first = first_playlist;

  //verifica se lista de playlists está vazia
  if (playlists_count == 0) {
    return;
  } else {
    //remove música das playlists que a contem
    while (first != nullptr) {
      first->getPlaylist()->removeMusic(music_title, false);
      first = first->getNext();
    }
  }
}

//construtor
Playlists::Playlists(){
  this->first_playlist = nullptr;
  this->last_playlist = nullptr;
  this->playlists_count = 0;
}

//destrutor
Playlists::~Playlists() {
  if (playlists_count == 0) {
    return;
  } else {
    //incializa valores
    PlaylistNode* current_node = first_playlist;
    PlaylistNode* next = nullptr;

    //percorre lista de playlists deleta elementos alocados
    while (current_node != nullptr) {
      next = current_node->getNext();

      delete current_node;
      current_node = next;
    }
  }
}