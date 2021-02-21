<h1 align="center">music_player</h1>

<p align="center">
  <a href="#sobre">Sobre</a> –
  <a href="#como-rodar">Como rodar</a> –
  <a href="#funcionalidades-e-exemplos">Funcionalidades e Exemplos</a> –
  <a href="#autora">Autora</a>
</p>

## Sobre

O music_player é um gerenciador de músicas e playlists desenvolvido em C++ para a disciplina de Linguagem de Programação I.

## Como rodar

Execute os seguintes comandos no seu terminal:

```bash
#clone o projeto
$ git clone https://github.com/marianefelix/music_player.git
#compile o projeto
$ make
#execute o projeto
$ ./music_player
#para limpar tudo
$ make clean
```
## Funcionalidades e Exemplos
Ao rodar o projeto, será mostrado um menu com as opções de 1 a 12 que podem ser selecionadas.

### Gerenciar músicas no sistema
Opção 1 - *Adicionar música no sistema:* <br>
<b>Limitação:</b> As músicas devem ter título único
#### Exemplo
```bash
#para adicionar música no sistema basta digitar seu título e nome do artista
Digite o nome da música:
Try Again
Digite o nome do artista:
Jaehyun
Música adicionada com sucesso!
```
Opção 2 - *Procurar música no sistema:* <br>
Caso queira checar se uma música já está no sistema, basta buscá-la pelo nome
#### Exemplo
```bash
Digite o nome da música que deseja buscar:
Try Again
Try Again - Jaehyun
```

Opção 3 - *Visualizar músicas do sistema:* <br>
Lista todas as músicas registradas no sistema
#### Exemplo
```bash
Músicas registradas no sistema:
Try Again - Jaehyun
```

Opção 4 - *Remover música do sistema:* <br>
Remove música do sistema pelo título e também é removida de playlist(s), caso tenha sido adicionada em alguma
#### Exemplo
```bash
Digite o nome da música que deseja remover:
Try Again
Música removida com sucesso!
```

### Gerenciar playlists

Opção 5 - *Criar playlist:* <br>
<b>Limitação:</b> Playlists devem ter nome único
#### Exemplo
```bash
#para criar uma playlist basta digitar seu nome
Digite o nome da playlist que deseja criar:
kpop
Playlist criada com sucesso!
```

Opção 6 - *Visualizar todas as playlists:* <br>
Lista todas as playlists criadas
#### Exemplo
```bash
Playlists criadas:
kpop
```
Opção 7 - *Tocar playlist:* <br>
Imprime a música que está tocando no momento. Toda vez que essa opção for selecionada, será tocada a próxima música da playlist
```bash
Digite o nome da playlist:
kpop
Tocando:
Try Again - Jaehyun
```

Opção 8 - *Remover playlist:* <br>
Remove playlist pelo nome
```bash
Digite o nome da playlist que deseja remover:
kpop
Playlist removida com sucesso!
```

### Gerenciar músicas em playlist
Opção 9 - *Adicionar música à playlist:* <br>
<b>Obs.:</b> Para adicionar uma música a uma playlist, é necessário que a música já esteja cadastrada no sistema e a playlist exista
#### Exemplo
```bash
#para adicionar uma música à playlist basta digitar o nome da playlist
Digite o nome da playlist:
kpop
#e digitar o nome da música que deseja adicionar
Digite o nome da música:
Try Again
Música adicionada com sucesso!
```

Opção 10 - *Visualizar todas as músicas da playlist:* <br>
Lista todas as músicas da playlist
#### Exemplo
```bash
#para visualizar músicas da playlist basta digitar o nome
Digite o nome da playlist:
kpop
Músicas da playlist:
Try Again - Jaehyun
```

Opção 11 - *Remover música de playlist:* <br>
Remove música de playlist por título da música
#### Exemplo
```bash
Digite o nome da playlist:
kpop
Digite o nome da música que deseja remover:
Try Again
Música removida com sucesso!
```

### Sair 
Opção 12 - *Sair:* <br>
Encerra o programa

## Autora

Feito por [Mariane Felix Fernandes](https://www.linkedin.com/in/mariane-felix-642350171/).
