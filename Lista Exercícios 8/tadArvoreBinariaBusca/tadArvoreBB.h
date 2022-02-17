typedef struct reg_no_arvore tipo_no_arvore;

void incluir_no_arvore(tipo_no_arvore **, int);
void percurso_em_ordem(tipo_no_arvore *);
void percurso_em_pre_ordem(tipo_no_arvore *);
void percurso_em_pos_ordem(tipo_no_arvore *);
int encontrar_elemento(tipo_no_arvore *, int);
int excluir_menor(tipo_no_arvore **);
int excluir_elemento(tipo_no_arvore **, int);
