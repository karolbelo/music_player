#include <iostream>
#include "music.h"
#include "node.h"
#include "linked_list.h"
#include "playlist.h"
#include "playlists.h"
#include "playlist_node.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


void showWelcomeMessage() {
  cout << " - - - - - - - - - - - - - - - - - - - - - - " << endl;
  cout << "|       Bem vindo(a) ao projeto de LP I     |" << endl;
  cout << " - - - - - - - - - - - - - - - - - - - - - - " << endl << endl;
}

void showMenu() {
  cout << "/nGerenciar músicas no sistema" << endl;
  cout << "----------------------------" << endl;
  cout << "1 - Adicionar música no sistema" << endl;
  cout << "2 - Procurar música no sistema" << endl;
  cout << "3 - Visualizar músicas do sistema" << endl;
  cout << "4 - Remover música do sistema" << endl << endl;

  cout << "Gerenciar playlists"<< endl;
  cout << "-------------------" << endl;
  cout << "5 - Criar playlist" << endl;
  cout << "6 - Visualizar todas as playlists" << endl;
  cout << "7 - Tocar playlist" << endl;
  cout << "8 - Remover playlist" << endl << endl;

  cout << "Gerenciar músicas em playlist"<< endl;
  cout << "-----------------------------" << endl;
  cout << "9 - Adicionar música à playlist" << endl;
  cout << "10 - Visualizar todas as músicas da playlist" << endl;
  cout << "11 - Remover música de playlist" << endl;
  cout << "12 - Sair" << endl << endl;

  cout << "Digite uma das opções acima:" << endl;
}

int main() {
  LinkedList* linked_list = new LinkedList();
  Playlists* playlists = new Playlists();
  string music_title = "", artist_name = "", playlist_name = "";
  
  size_t option = 0;
  
  showWelcomeMessage();

  while (option != 12) {
    showMenu();
    cin >> option;
  
    if (option == 1) {
      cout << "Digite o nome da música:" << endl;
      //ignora quebra de linha de cout
      cin.ignore();
      getline(cin, music_title);

      cout << "Digite o nome do artista:" << endl;
      getline(cin, artist_name);

      linked_list->insert(music_title, artist_name);
    } else if (option == 2) {
      cout << "Digite o nome da música que deseja buscar:" << endl;
      cin.ignore();
      getline(cin, music_title);

      linked_list->listAt(music_title);
    } else if (option == 3) {
      linked_list->listAll();
    } else if (option == 4) {
      cout << "Digite o nome da música que deseja remover:" << endl;
      cin.ignore();
      getline(cin, music_title);

      //remove música das playlists e do sistema
      playlists->removeMusicFromAll(music_title);
      linked_list->remove(music_title, true);
    } else if (option == 5) {
      cout << "Digite o nome da playlist que deseja criar:" << endl;
      cin.ignore();
      getline(cin, playlist_name);

      playlists->insert(playlist_name);
    } else if (option == 6) {
      playlists->listAll();
    } else if (option == 7) {
      cout << "Digite o nome da playlist:" << endl;
      cin.ignore();
      getline(cin, playlist_name);
    
      //busca playlist pelo nome
      PlaylistNode* playlist_node = playlists->search(playlist_name, true);

      //verifica se playlist existe
      if (playlist_node != nullptr ) {
        playlist_node->getPlaylist()->playNext();
      }
    } else if (option == 8) {
      cout << "Digite o nome da playlist que deseja remover:" << endl;
      cin.ignore();
      getline(cin, playlist_name);
        
      playlists->remove(playlist_name);
    } else if (option == 9) {
      cout << "Digite o nome da playlist:" << endl;
      cin.ignore();
      getline(cin, playlist_name);
      
      cout << "Digite o nome da música:" << endl;
      getline(cin, music_title);

      //busca playlist e musica
      PlaylistNode* playlist_node = playlists->search(playlist_name, true);
      Node* node = linked_list->search(music_title, true);

      //verifica se playlist já existe e a música também
      if (playlist_node != nullptr && node != nullptr) {
        playlist_node->getPlaylist()->insertMusic(node->getMusic());
      }
    } else if (option == 10) {
      cout << "Digite o nome da playlist:" << endl;
      cin.ignore();
      getline(cin, playlist_name);
      
      PlaylistNode* playlist_node = playlists->search(playlist_name, true);
      Node* node = playlist_node->getPlaylist()->getLinkedList()->getFirstNode();
      
      if (playlist_node != nullptr) {
        if (node != nullptr) {
          cout << "Músicas da playlist" << endl;
        } else {
          cout << "Nenhuma música foi adicionada à playlist." << endl << endl;
        }
        playlist_node->getPlaylist()->listAll(node);
      }
    } else if (option == 11) {
      cout << "Digite o nome da playlist:" << endl;
      cin.ignore();
      getline(cin, playlist_name);
      
      cout << "Digite o nome da música que deseja remover:" << endl;
      getline(cin, music_title);

      //busca playlist pelo nome
      PlaylistNode* playlist_node = playlists->search(playlist_name, true);

      //verifica se playlist já existe
      if (playlist_node != nullptr ) {
        playlist_node->getPlaylist()->removeMusic(music_title, true);
      }
    } else if (option == 12 || option > 12) {
      break;
    }
  }

  delete linked_list;
  delete playlists;

  return 0;
}