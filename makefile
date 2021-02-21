#chama os targets create_objects e o music_player
all: create_objects music_player

#cria a pasta exe
create_objects:
		mkdir -p objects

#compila todos os arquivos e cria o executável music_player
music_player: objects/main.o objects/music.o objects/node.o objects/linked_list.o objects/playlist.o objects/playlist_node.o objects/playlists.o
		g++ objects/*.o -Iheaders -Wall -pedantic -ansi -std=c++11 -g -o music_player

objects/main.o: src/main.cpp objects/music.o objects/node.o objects/linked_list.o objects/playlist.o objects/playlist_node.o objects/playlists.o
		g++ src/main.cpp -Iheaders -Wall -pedantic -ansi -std=c++11 -g -c -o objects/main.o

objects/music.o: src/music.cpp
		g++ src/music.cpp -Iheaders -Wall -pedantic -ansi -std=c++11 -g -c -o objects/music.o

objects/node.o: src/node.cpp objects/music.o
		g++ src/node.cpp -Iheaders -Wall -pedantic -ansi -std=c++11 -g -c -o objects/node.o objects/music.o

objects/linked_list.o: src/linked_list.cpp objects/music.o objects/node.o
		g++ src/linked_list.cpp -Iheaders -Wall -pedantic -ansi -std=c++11 -g -c -o objects/linked_list.o

objects/playlist.o: src/playlist.cpp objects/linked_list.o
		g++ src/playlist.cpp -Iheaders -Wall -pedantic -ansi -std=c++11 -g -c -o objects/playlist.o

objects/playlist_node.o: src/playlist_node.cpp objects/playlist.o
		g++ src/playlist_node.cpp -Iheaders -Wall -pedantic -ansi -std=c++11 -g -c -o objects/playlist_node.o


objects/playlists.o: src/playlists.cpp objects/playlist_node.o
		g++ src/playlists.cpp -Iheaders -Wall -pedantic -ansi -std=c++11 -g -c -o objects/playlists.o

#remove a pasta objects e o executável do projeto
clean:
		rm -rf objects music_player