typedef struct pilha tipo_pilha;

typedef struct pilha tipo_fila;


tipo_pilha* criarPilha (); //aloca memória iniciando uma nova pilha

void push (tipo_pilha *, int); //adiciona elemento no topo da pilha

int pull (tipo_pilha *); //remove e retorna o elemento do topo da pilha ou NULL se a pilha estiver vazia

int isPilhaVazia (tipo_pilha *); //Retorna 1 se a pilha está vazia e 0 se conter elementos

int tamanhoPilha (tipo_pilha *); //Retorna o tamanho da pilha

void apagarPilha (tipo_pilha *); //Apaga todos os elementos da pilha

tipo_fila *criarFila (); //aloca memória iniciando uma nova pilha

int addFila (tipo_fila* ,int); //adiciona um numero na fila, retorna 1 para sucesso e 0 para falha

void removeFila (tipo_fila *); //Remove o primeiro elemento da fila

int isFilaVazia (tipo_fila *); //Retorna 1 se a fila está vazia e 0 se conter elementos

int tamanhoFila (tipo_fila *); //Retorna o tamanho da fila

void apagarFila (tipo_fila *); //Apaga todos os elementos da fila
