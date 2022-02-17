
typedef struct pilha tipo_fila;


tipo_fila *criarFila (); //aloca memória iniciando uma nova pilha

int addFila (tipo_fila* ,int); //adiciona um numero na fila, retorna 1 para sucesso e 0 para falha

int removeFila (tipo_fila *); //Remove o primeiro elemento da fila e retorna o valor removido

int isFilaVazia (tipo_fila *); //Retorna 1 se a fila está vazia e 0 se conter elementos

int tamanhoFila (tipo_fila *); //Retorna o tamanho da fila

void apagarFila (tipo_fila *); //Apaga todos os elementos da fila