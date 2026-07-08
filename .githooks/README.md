# Git Hooks and Local Validation

Este diretório guarda os hooks versionados do projeto e a forma de usar as validações locais antes de fazer `push` ou abrir merge request.

## Instalação dos hooks

Rode uma vez na raiz do projeto:

```sh
sh scripts/install-hooks.sh
```

Isso configura `core.hooksPath=.githooks` no repositório local. Depois disso, o Git passa a usar:

- `pre-commit`
- `pre-push`

## Comandos principais

Na raiz do projeto:

- `make` compila o binário principal `cub3D`.
- `make clean` remove os objetos e o binário de teste.
- `make fclean` faz `clean` e remove o binário principal.
- `make re` executa `fclean` e depois recompila tudo.
- `make test` compila e executa o teste de fumaça em `tests/test_utils_mlx.c`.
- `make norm` roda `norminette` em `includes/` e `src/`, ignorando `tests/`.

Se `norminette` não estiver instalada localmente, `make norm` vai falhar com mensagem clara.

## O que os hooks fazem

- `pre-commit` roda `make test norm`.
- `pre-push` roda `make re test norm`.

Na prática, isso evita que código com erro de build, falha no teste de fumaça ou problema de norm seja enviado sem revisão.

## Como adicionar uma função de fumaça

Use uma função de fumaça quando você quiser validar um comportamento pequeno e local antes de fazer `push`.

Fluxo recomendado:

1. Escolha a função que vai ser alterada, por exemplo `my_pixel_put`.
2. Crie um teste pequeno em `tests/` que chame essa função diretamente.
3. Faça o teste falhar quando o comportamento estiver errado e passar quando estiver certo.
4. Ligue esse arquivo ao alvo `make test` no `Makefile`.
5. Rode `make test` localmente antes do `push`.
6. Rode `make norm` antes de abrir merge request.

## Exemplo de teste de fumaça

O arquivo `tests/test_utils_mlx.c` valida `my_pixel_put` com um buffer em memória:

- escreve em uma posição válida;
- confirma que o valor esperado foi alterado;
- tenta posições fora da tela;
- confirma que o buffer não muda nessas entradas inválidas.

Esse tipo de teste é bom para funções pequenas que manipulam memória, cores, strings ou validações simples.

## Como criar um novo teste de fumaça

Se quiser testar outra função localmente, siga este padrão:

- crie um arquivo como `tests/test_nome_da_funcao.c`;
- inclua `cub3D.h` e os headers extras que precisar;
- escreva um `main` simples com `assert`;
- compile o teste no alvo `make test`;
- deixe o teste com saída mínima: o ideal é falhar só quando algo estiver errado.

## Fluxo antes de push e merge

Antes de fazer `push`:

```sh
make test
make norm
```

Antes de abrir merge request ou mergear na branch principal:

```sh
make re
make test
make norm
```

## GitHub Actions

O workflow em `.github/workflows/ci.yml` já faz:

- build do projeto;
- `make test`;
- `make norm`.

Ele também baixa a MiniLibX antes de compilar, porque esse diretório precisa existir no ambiente do GitHub Actions para o `# include <mlx.h>` funcionar.

Então o ideal é manter o mesmo comportamento local e no CI.

## Dica prática

Se uma função nova ainda não tiver teste de fumaça, crie primeiro o teste mais simples possível e só depois faça o `push`. Isso reduz retrabalho e pega erro cedo.