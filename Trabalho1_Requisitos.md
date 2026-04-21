Trabalho 1 - Análise Léxica 
Compiladores 
Prof.: Adriano Maia 

O grupo deve criar uma linguagem de programação simples, que pode 
ser totalmente inventada ou baseada em alguma linguagem já existente, 
que contenha pelo menos: 
● Deve ser imperativa e compatível com o ASCII. 
● Deve ser possível inicializar variáveis do tipo numérico, seja inteiro ou de número flutuante, com tipagem estática, além de vetores do tipo numérico. 
● Deve ser possível fazer acessos e atribuições às variáveis inicializadas, incluindo os elementos individuais dos vetores. As atribuições devem ser expressões aritméticas que podem conter números pré-definidos e/ou variáveis e/ou funções.
● Deve ser possível criar desvios condicionais simples e compostos, com a condição sendo feita com uma operação de comparação. 
● Deve ser possível criar um comando de repetição, com a condição para a repetição sendo feita com uma operação de comparação. 
● Deve ser possível criar funções que, a partir de um número definido de parâmetros (com tipagem estática), retorne, um número inteiro, ponto flutuante ou não retorne nada. O tipo de retorno deve ser explicitado na definição da função. Após a criação da função, é possível chamá-la no código. 

ATENÇÃO: A linguagem criada não poderá ser um subconjunto da linguagem C. 
Com a linguagem criada, o grupo deverá criar um analisador léxico em C que faça a sequência de tokens de um código qualquer da linguagem. 

A forma exata da saída é pode ser feita da forma que o grupo achar melhor, porém os identificadores devem ter a indicação da sua posição na tabela de símbolos. 
Exemplo:
public static void main (String [] args) {
    int a = 10, b = 4;
    float c = a / b;
    System.Out.Print (c);
}

Sequência de Tokens:
<public> <static> <void> <id, 1> <(> <id, 2> <[> <]> <id, 3> <)>
<{> <int> <id, 4> <= > <num, 10> <,> <id, 5> <= > <num, 4> <; >
<float> <id, 6> <= > <id, 4> </ > <id, 5> <; > <id, 7> <. > <id, 8>
<. > <id, 9> <(> <id, 6> <)> <; > <}>

Uma vez que a linguagem será criada pelo grupo, deve-se fazer uma documentação robusta, explicando e detalhando os comandos, padrões utilizados, etc. Sem uma boa documentação não é possível analisar o código Flex.