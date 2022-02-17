typedef struct reg_no_arvore tipo_no_arvore;
typedef struct reg_pilha tipo_pilha;

tipo_pilha* criarPilhaVazia();
int pilhaVazia(tipo_pilha*);
void empilhar(tipo_pilha* pilha, tipo_no_arvore *dado);
tipo_no_arvore* desempilhar(tipo_pilha* pilha);
int quantidadeElementosPilha(tipo_pilha*);
tipo_pilha* apagarPilha(tipo_pilha*);
