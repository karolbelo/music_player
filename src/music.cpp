#include <iostream>
#include "music.h"

//retorna titulo da música
std::string Music::getTitle(){
  return this->title;
}

//seta titulo da música
void Music::setTitle(std::string title) {
  this->title = title;
}

//retorna nome do artista da música
std::string Music::getArtistName() { 
  return this->artist_name;
}

//seta nome do artista da música
void Music::setArtistName(std::string artist_name) {
  this->artist_name = artist_name;
}

//construtor
Music::Music(std::string title, std::string artist_name){
  this->title = title;
  this->artist_name = artist_name;
}

//destrutor
Music::~Music() {}