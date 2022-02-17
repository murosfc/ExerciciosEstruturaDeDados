typedef struct reg_no_arvore **tipo_no_arvore;

tipo_no_arvore inicializar_arvore(tipo_no_arvore);
void incluir_no_arvore(tipo_no_arvore, int);
void percurso_em_ordem(tipo_no_arvore);
void percurso_em_pre_ordem(tipo_no_arvore);
void percurso_em_pos_ordem(tipo_no_arvore);
int encontrar_elemento(tipo_no_arvore, int);
int excluir_menor(tipo_no_arvore);
int excluir_elemento(tipo_no_arvore, int);
int menor_elemento (tipo_no_arvore); // Exercicio 1
int soma_elementos (tipo_no_arvore); // Exercicio 2
int conta_nos(tipo_no_arvore); // Exercicio 3
int media_arvore (tipo_no_arvore); // Exercicio 4
int conta_folhas (tipo_no_arvore); // Exercicio 5
int conta_nulls (tipo_no_arvore); // Exercicio 6
int calcula_altura (tipo_no_arvore); // Exercicio 7
int conta_multiplos (tipo_no_arvore, int); // Exercicio 8
int encontrar_elemento_plus(tipo_no_arvore, int); // Exercicio 9
void copiar_arvore (tipo_no_arvore, tipo_no_arvore); //Lista 9 Exercicio 1