#include <iostream>
#include "playlist_node.h"
#include "playlist.h"

//retorna endereço da próxima playlist
PlaylistNode* PlaylistNode::getNext(){
  return this->next;
}

//seta endereço da próxima playlist
void PlaylistNode::setNext(PlaylistNode* next) {
  this->next = next;
}

//retorna endereço da playlist
Playlist* PlaylistNode::getPlaylist() {
  return this->playlist;
}

//seta endereço da playlist
void PlaylistNode::setPlaylist(Playlist *playlist) {
  this->playlist = playlist;
}

//construtor
PlaylistNode::PlaylistNode(std::string name){
  playlist = new Playlist(name);
  next = nullptr;
}

//destrutor
PlaylistNode::~PlaylistNode() {
  delete playlist;
}