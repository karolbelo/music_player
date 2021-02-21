#include <iostream>
#include "linked_list.h"
#include "node.h"
#include "music.h"

//insere música na lista
void LinkedList::insert(std::string title, std::string artist_name) {
  Node* node =  this->search(title, false);

  /*
    verifica se já existe um elemento na lista com
    o título de música informado
  */
  if (node == nullptr) {
    //verifica se primeiro elemento existe
    if (first_node != nullptr) {
      //cria um novo elemento, caso a lista seja diferente de vazio
      Node* new_node = new Node(title, artist_name);
      
      last_node->setNext(new_node);
      last_node = new_node;
    } else {
      //cria o primeiro elemento e seta como primeiro e ultimo elemento
      Node* other = new Node(title, artist_name);

      first_node = other;
      last_node = other;
    }

    //incrementa tamanho da lista
    list_size++;
    std::cout << "Música adicionada com sucesso!" << std::endl << std::endl;
  } else {
    std::cout << "Já existe uma música com esse título. Por favor adicione músicas com títulos únicos." << std::endl << std::endl;
  }
}

//procura música na lista
Node* LinkedList::search(std::string title, bool show_not_found_message) {
  Node* first = first_node;
  Node* node_position = nullptr;

  /*
    verifica se lista tem pelo menos um elemento
    se tiver, percorre a lista para encontrar musica
  */
  if (first != nullptr) {
    while (first != nullptr) {
      if (first->getMusic()->getTitle() == title) {
        node_position = first;
        break;
      }
      first = first->getNext();
    }

    //se a música existir, retorna endereço do elemento
    if (node_position != nullptr) {
      return node_position;
    } else {
      if (show_not_found_message) {
        std::cout << "Música não encontrada." << std::endl << std::endl;
      }
      return nullptr;
    }
  } else {
    if (show_not_found_message) {
      std::cout << "Nenhuma foi música adicionada ainda." << std::endl << std::endl;
    }
    return nullptr;
  }
}

//lista todas as músicas
void LinkedList::listAll() {
  Node* first = first_node;
  Music* music = nullptr;

  //verifica se lista está vazia
  if (first == nullptr) {
    std::cout << "Nenhuma foi música adicionada ainda." << std::endl << std::endl;
    return;
  } else {
    std::cout << "Músicas registradas no sistema:" << std::endl;
    //lista todas músicas do sistema
    while (first != nullptr) {
      music = first->getMusic();
      std::cout << music->getTitle() << " - " << music->getArtistName() << std::endl;
      first = first->getNext();
    }
  }
}

//lista música por título
void LinkedList::listAt(std::string title) {
  Node* position = this->search(title, true);
  Music* music = nullptr;

  //imprime música, caso exista
  if (position != nullptr) {
    music = position->getMusic();
    std::cout << music->getTitle() << " - " << music->getArtistName() << std::endl << std::endl;
  }
}

//remove música da lista
void LinkedList::remove(std::string title, bool show_success_message) {
  Node* position = this->search(title, true);
  Node* first = first_node;
  Node* last = last_node;
  Node* current_node = first;
  Node* aux = position;
  Node* prev = nullptr;

  //verifica se elemento que contém a música existe
  if (position != nullptr) {
    /*
      se a lista tiver apenas um elemento,
      seta o primeiro e o ultimo elemento como null
    */
    if (list_size == 1) {
      first_node = nullptr;
      last_node = nullptr;
    } else {
      //percorre elementos da lista
      while (current_node <= aux) {
        if (current_node == position) {
          //se for o primeiro elemento
          if (position == first) {
            first_node = position->getNext();
          } else if (position == last) {
            //se for o último elemento
            prev->setNext(nullptr);
            last_node = prev;
          } else {
            prev->setNext(current_node->getNext());
          }
          break;
        }
        prev = current_node;
        current_node = current_node->getNext();
      }
    }
    //deleta elemento da lista
    delete position;
    //decrementa tamanho da lista
    list_size--;
    //mostra mensagem de sucesso
    if (show_success_message) {
      std::cout << "Música removida com sucesso!" << std::endl << std::endl;
    }
  }
}

//retorna primeiro elemento da lista
Node* LinkedList::getFirstNode() {
  return this->first_node;
}

//retorna tamanho da lista
size_t LinkedList::getListSize() {
  return this->list_size;
}

//construtor
//inicializa first_node, last_node e list_size
LinkedList::LinkedList(){
  first_node = nullptr;
  last_node = nullptr;
  list_size = 0;
}

//destrutor
LinkedList::~LinkedList() {
  if (list_size == 0) {
    return;
  } else {
    Node* current_node = first_node;
    Node* next = nullptr;

    //percorre lista e deleta elementos alocados
    while (current_node != nullptr) {
      next = current_node->getNext();
      delete current_node;

      current_node = next;
    }
  }
}