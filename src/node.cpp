#include <iostream>
#include "node.h"
#include "music.h"

//retorna endereço do próximo elemento da lista
Node* Node::getNext(){
  return this->next;
}

 //seta endereço do próximo elemento da lista
void Node::setNext(Node* next) {
  this->next = next;
}

//retorna endereço da música do elemento
Music* Node::getMusic() {
  return this->music;
}

//seta endereço da mpusica do elemento
void Node::setMusic(Music* music) {
  this->music = music;
}

//construtor
Node::Node(std::string title, std::string artist_name){
  music = new Music(title, artist_name);
  next = nullptr;
}

//destrutor
Node::~Node() {
  delete music;
}