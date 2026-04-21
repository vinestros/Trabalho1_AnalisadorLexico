# Linguagem Tematica de Gastronomia

Este documento define o vocabulario oficial da tematica culinaria para a linguagem.

## Mapeamento de Palavras-Chave

- `prove` -> condicional simples
- `senao` -> desvio composto
- `cozinhando` -> repeticao
- `medida` -> tipo inteiro
- `liquido` -> tipo ponto flutuante
- `tempero` -> tipo caractere
- `sirva` -> retorno de funcao

## Observacoes

- O analisador lexico continua retornando os mesmos tokens internos.


## Exemplo de Regras Flex

```c
"cozinhando"   { return T_WHILE; }
"sirva"        { return T_RETURN; }
```

## Exemplo de Codigo

```txt
medida tempoForno;
tempoForno = 3;

cozinhando (tempoForno > 0) {
    tempoForno = tempoForno - 1;
}

sirva tempoForno;
```
