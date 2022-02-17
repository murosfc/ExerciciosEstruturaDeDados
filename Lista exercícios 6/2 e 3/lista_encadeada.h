
typedef struct no tipo_no;
typedef struct lista tipo_lista;

tipo_lista *CriarListaVazia ();
void InserirElemento (tipo_lista*, int);
void ExcluirElemento (tipo_lista*, int);
int listaVazia (tipo_lista*);
int quantidadeElementosLista(tipo_lista*);
void apagarLista(tipo_lista*);
int* obterElementosLista(tipo_lista* lista);
tipo_lista* concatenarListas (tipo_lista*, tipo_lista*); //lista 1 recebe lista 2 e lista 2
void excluirIguais (tipo_lista*, int);
float calcularMedia (tipo_lista*);
int verificarProfundidade (tipo_lista*, int);
int compararListas (tipo_lista*,tipo_lista*);
void inserirElementoOrdenado(tipo_lista*, int);
void ordernarElementos (tipo_lista *);
void CopiarLista (tipo_lista*, tipo_lista*); //copia da lista 2 para a lista 1