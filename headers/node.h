#ifndef NODE_H
#define NODE_H

#include "music.h"

//representa elemento da lista de músicas do sistema
class Node {
  private:
    Music* music; //ponteiro que guarda endereço de música
    Node* next; //ponteiro que guarda endereço do próximo elemento da lista

  public: 
    Node* getNext(); //retorna endereço do próximo elemento da lista
    void setNext(Node* next); //seta endereço do próximo elemento da lista
    Music* getMusic(); //retorna endereço da música do elemento
    void setMusic(Music* music); //seta endereço da mpusica do elemento

    //construtor e destrutor
    Node(std::string title, std::string artist_name);
    ~Node();
};

#endif