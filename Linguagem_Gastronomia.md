# Grupo
O grupo e composto por Pedro Henrique, Joao Pedro Sales e Vinicius Menezes.

# Linguagem tematica de gastronomia - Estado final do projeto

Este documento descreve o estado final implementado no projeto, com integracao entre analisador lexico (Flex) e analisador sintatico (Bison), incluindo geracao de arvore sintatica (AST).

---

## 1. Visao geral da arquitetura final

A linguagem segue paradigma imperativo, com tipagem estatica para `medida`, `liquido` e `tempero`, suporte a vetor numerico, expressoes, condicionais, repeticao e funcoes.

No estado final:

- O **Flex** (`scanner_c.l`) faz tokenizacao.
- O **Bison** (`parser.y`) valida a sintaxe.
- O parser constroi e imprime a **arvore sintatica** no formato hierarquico.

Arquivos principais:

- `scanner_c.l`: regras lexicas e retorno de tokens para o parser.
- `parser.y`: gramatica, AST e `main` com `yyparse()`.
- `teste.lang`: teste base da linguagem.
- `teste_sintatico.lang`: teste completo com funcoes e chamada de funcao.
- `teste_erro_sintatico.lang`: teste com erro proposital.

---

## 2. Palavras-chave e operadores da linguagem

### 2.1 Palavras-chave

| Lexema | Papel |
|--------|-------|
| `prove` | condicional (`if`) |
| `se_ruim` | ramo alternativo (`else`) |
| `cozinhando` | repeticao (`while`) |
| `medida` | tipo inteiro |
| `liquido` | tipo flutuante |
| `tempero` | tipo caractere |
| `sirva` | retorno |
| `vazio` | retorno void |
| `receita` | declaracao de funcao |

### 2.2 Operadores

| Lexema | Papel |
|--------|-------|
| `vira` | atribuicao |
| `adiciona`, `tira`, `vezes`, `fatiado_por` | operadores aritmeticos |
| `se_for`, `se_nao_for`, `menos_que`, `mais_que`, `no_maximo`, `no_minimo` | operadores relacionais |

---

## 3. Especificacao lexica implementada (Flex)

Principais classes reconhecidas em `scanner_c.l`:

- Identificadores: `ID_TOKEN`
- Inteiros: `INTEIRO`
- Flutuantes: `FLOAT_NUM`
- Strings: `STRING_LITERAL`
- Char literal: `CHAR_LITERAL`
- Comentarios de linha e bloco
- Separadores: `;`, `,`, `(`, `)`, `{`, `}`, `[`, `]`

Detalhe importante do estado final:

- IDs e literais sao enviados ao parser por `yylval.str = strdup(yytext)`.
- O scanner **nao** imprime mais sequencia de tokens; ele alimenta o parser.
- Erro lexico reporta linha e retorna caractere inesperado para o parser.

---

## 4. Gramatica sintatica implementada (Bison)

A gramatica final em `parser.y` cobre:

- Declaracoes simples e com vetor.
- Atribuicoes em variavel e acesso de vetor.
- Blocos.
- `if` e `if/else`.
- `while`.
- `return` com e sem expressao.
- Declaracao de funcao com `receita`, parametros tipados e retorno tipado/`vazio`.
- Chamada de funcao com lista de argumentos.
- Expressoes aritmeticas com precedencia (`+`, `-`, `*`, `/`).
- Condicoes relacionais no formato:
  - `expression relop expression`.

Tokens e tipos sintaticos sao centralizados no Bison (`%token`, `%union`, `%type`) e compartilhados com o scanner por `parser.tab.h`.

---

## 5. Arvore sintatica (AST) e saida

A AST e montada no parser com nos hierarquicos, por exemplo:

- `program`
- `statement list`
- `statement`
- `declaration`
- `attribution`
- `if statement`
- `while statement`
- `function declaration`
- `function call`
- `return`
- `rlop`

Quando a analise termina com sucesso:

1. O parser imprime `Arvore sintatica:`
2. Exibe a arvore em formato textual com prefixo por profundidade (`-`).

Em erro sintatico:

- `yyerror` imprime `Erro sintatico na linha X: ...`.

---

## 6. Como compilar e executar

Exemplo no WSL/Linux:

```bash
bison -d -o parser.tab.c parser.y
flex -o lex.yy.c scanner_c.l
gcc -o parser parser.tab.c lex.yy.c
./parser teste.lang
./parser teste_sintatico.lang
./parser teste_erro_sintatico.lang
```

Saidas esperadas:

- `teste.lang` e `teste_sintatico.lang`: arvore sintatica impressa.
- `teste_erro_sintatico.lang`: mensagem de erro sintatico.

---

## 7. Alteracoes realizadas e motivo

Esta secao registra o que foi alterado para sair do estado de T1 (lexico) para T2 (sintatico).

### 7.1 Integracao Flex + Bison

**Alteracao feita**
- O scanner passou a incluir `parser.tab.h` e retornar tokens definidos no parser.
- O fluxo principal passou para `yyparse()` no `parser.y`.

**Motivo**
- Evitar duplicacao e divergencia de tokens entre scanner e parser.
- Atender ao requisito de integracao entre analise lexica e sintatica.

### 7.2 Migracao de saida de tokens para AST

**Alteracao feita**
- Remocao da estrategia antiga de imprimir apenas sequencia de tokens no scanner.
- Implementacao de construcao e impressao de AST no parser.

**Motivo**
- O enunciado do Trabalho 2 exige exibicao da arvore sintatica com atributos.

### 7.3 Ajuste de identificadores e literais

**Alteracao feita**
- IDs e literais passaram a trafegar via `yylval.str`.

**Motivo**
- Permitir que o parser monte nos da AST com nomes de identificadores e valores literais.

### 7.4 Inclusao de funcoes na linguagem implementada

**Alteracao feita**
- Implementadas regras para declaracao de funcao (`receita`) com parametros, retorno tipado ou `vazio`, chamada e `sirva`.

**Motivo**
- Cobrir requisito obrigatorio do Trabalho 2 sobre funcoes.

### 7.5 Atualizacao dos testes

**Alteracao feita**
- Adicao de `teste_sintatico.lang` e `teste_erro_sintatico.lang`.

**Motivo**
- Validar cenarios de sucesso e erro sintatico de forma objetiva.

---

## 8. Conclusao

O projeto agora representa o estado final esperado para o Trabalho 2:

- Scanner lexico funcional.
- Parser sintatico integrado.
- Geracao de arvore sintatica textual.
- Cobertura de estruturas obrigatorias da linguagem.

Com isso, a implementacao deixa de ser somente lexico (T1) e passa a atender os requisitos centrais de analise sintatica (T2).
