#ifndef MUSIC_H
#define MUSIC_H

//representa a música do sistema
class Music {
  private:
    std::string title; //título da música
    std::string artist_name; //nome do artista

  public: 
    std::string getTitle(); //retorna título da música
    std::string getArtistName(); //retorna nome do artista

    //construtor e destrutor
    Music(std::string title, std::string artist_name);
    ~Music();
};

#endif