#include <iostream>
#include "music.h"

//retorna titulo da música
std::string Music::getTitle(){
  return this->title;
}

//retorna nome do artista da música
std::string Music::getArtistName() { 
  return this->artist_name;
}

//construtor
Music::Music(std::string title, std::string artist_name){
  this->title = title;
  this->artist_name = artist_name;
}

//destrutor
Music::~Music() {}