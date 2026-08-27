*Este projeto foi criado como parte do currículo da 42 por rafreire e tmorais-.*

# cub3D

## Descrição

**cub3D** é uma introdução ao mundo da raycasting 3D, inspirado no clássico
*Wolfenstein 3D*. O objetivo do projeto é construir, em C e usando a
biblioteca gráfica **MiniLibX**, um jogo em primeira pessoa capaz de renderizar
um labirinto tridimensional a partir de um mapa 2D fornecido em um arquivo de
configuração (`.cub`).

O projeto está dividido em três grandes blocos:

- **Parsing**: leitura e validação completa do arquivo `.cub` — texturas das
  paredes (Norte, Sul, Leste, Oeste), cores do chão e do teto, e o mapa em si
  (formato, caracteres válidos, fechamento por paredes, posição e orientação
  do jogador).
- **Raycasting**: cálculo, para cada coluna de pixels da tela, do raio que
  parte da posição do jogador até a parede mais próxima (algoritmo DDA),
  determinando distância, lado atingido e coordenada de textura.
- **Renderização e movimentação**: desenho do chão, teto, paredes texturizadas
  e um minimapa 2D no canto da tela, além da movimentação e rotação do
  jogador em tempo real através do teclado.

## Instruções

### Dependências

- `gcc` (ou `cc`) e `make`
- Bibliotecas de desenvolvimento do X11 (`libx11-dev`, `libxext-dev`) —
  necessárias para compilar a MiniLibX
- `libbsd-dev` (usada pela MiniLibX em sistemas Linux)

Em distribuições baseadas em Debian/Ubuntu:

```bash
sudo apt-get install libx11-dev libxext-dev libbsd-dev
```

### Compilação

O `Makefile` compila automaticamente a `libft` e a `MiniLibX` antes do
projeto:

```bash
make        # compila tudo e gera o binário ./cub3D
make clean  # remove os arquivos objeto
make fclean # remove objetos e o binário
make re     # fclean + all
```

### Execução

```bash
./cub3D <caminho_para_o_mapa.cub>
```

Exemplos de mapas válidos e inválidos (usados para testes) estão disponíveis
em `maps/valid/` e `maps/invalid/`.

```bash
./cub3D maps/valid/simple.cub
```

### Formato do arquivo `.cub`

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111111111111111
100000000000000010
100011110000000010
1000N0000000000010
100000000000000010
111111111111111111
```

- `NO`, `SO`, `WE`, `EA`: caminhos para as texturas (`.xpm`) das paredes
  voltadas para cada ponto cardeal.
- `F` e `C`: cor do chão (*floor*) e do teto (*ceiling*), no formato
  `R,G,B` (0-255).
- O mapa é composto pelos caracteres `0` (espaço livre), `1` (parede) e
  `N`, `S`, `E`, `W` (posição e orientação inicial do jogador). Ele precisa
  estar completamente fechado por paredes.

### Controles

| Tecla         | Ação                          |
|---------------|-------------------------------|
| `W` / `A` / `S` / `D` | Mover / deslocar lateralmente |
| `←` / `→`     | Girar a câmera                |
| `ESC`         | Fechar o jogo                 |
| Botão de fechar da janela | Fechar o jogo     |

### Verificação de norma e memória

```bash
make norm      # roda a norminette sobre includes/ e src/
make valgrind  # roda o binário sob valgrind com o supressor mlx.supp
```

## Recursos

### Referências clássicas

- [Lode's Computer Graphics Tutorial – Raycasting](https://lodev.org/cgtutor/raycasting.html) —
  a referência mais usada pela comunidade 42 para entender o algoritmo DDA de
  raycasting e o mapeamento de texturas nas paredes.
- [Documentação oficial da MiniLibX (42 Paris)](https://github.com/42Paris/minilibx-linux) —
  funções disponíveis, inicialização de janelas e imagens.
- [Ray Casting - Wikipedia](https://en.wikipedia.org/wiki/Ray_casting) — base
  teórica do algoritmo.
- *Wolfenstein 3D* (id Software, 1992) — o jogo que inspirou o subject e serve
  de referência visual/histórica para o gênero.
- [42 Norminette](https://github.com/42School/norminette) — ferramenta e
  documentação da norma de código usada para validar o estilo do projeto.

### Uso de Inteligência Artificial

A IA (Claude, da Anthropic) foi utilizada como ferramenta de apoio pontual
durante o desenvolvimento, nas seguintes tarefas:

- **Revisão de código já escrito pela equipe**: identificação de problemas de
  formatação (mistura de espaços e tabs) e sugestões de correção sem alterar
  a lógica original.
- **Geração deste `README.md`**: estruturação e redação do documento a partir
  da análise do código-fonte do repositório (parsing, raycasting, renderização
  e controles), seguindo os requisitos do subject.

A IA não foi utilizada para gerar a lógica de raycasting, o algoritmo DDA, o
parsing do mapa ou qualquer outra parte central do funcionamento do jogo —
esse trabalho foi feito integralmente pela equipe.
