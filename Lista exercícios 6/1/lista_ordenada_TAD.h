
typedef struct reg_lista tipo_lista;

tipo_lista* criarListaVazia();
int listaVazia(tipo_lista*);
void inserirElementoOrdenado(tipo_lista*, int);
int excluirElementoOrdenado(tipo_lista*, int);
int quantidadeElementosLista(tipo_lista*);
int* obterElementosLista(tipo_lista*);
tipo_lista* apagarLista(tipo_lista*);
float calcularMedia (tipo_lista*);
int verificarProfundidade (tipo_lista*, int);
int compararListas (tipo_lista*,tipo_lista*);
