#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

//representa uma lista ligada que contém músicas
class LinkedList {
  private:
    Node* first_node; //primeiro elemento da lista
    Node* last_node; //último elemento da lista
    size_t list_size; //tamanho da lista

  public:
    void insert(std::string title, std::string artist_name); //insere música por título e nome de artista
    void remove(std::string title, bool show_success_message); //remove música por título
    Node* search(std::string title, bool show_not_found_message); //procura música por título e retorna o elemento do tipo Node*
    void listAt(std::string title); //lista música por título
    void listAll(); //lista todas as músicas do sistema

    Node* getFirstNode(); //retorna primeiro elemento da lista
    size_t getListSize(); //retorna tamanho da lista

    //construtor e destrutor
    LinkedList();
    ~LinkedList();
};

#endif