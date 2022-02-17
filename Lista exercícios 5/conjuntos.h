typedef struct conjuntos tipo_conjunto;

typedef struct vet tipo_vet_print;

tipo_conjunto *cria_conjunto ();
void insere_conjunto (tipo_conjunto *, int);
void remove_conjunto (tipo_conjunto *, int);
tipo_conjunto *uniao (tipo_conjunto *,tipo_conjunto *);
tipo_conjunto *interseccao (tipo_conjunto *,tipo_conjunto *);
tipo_conjunto *diferenca (tipo_conjunto *,tipo_conjunto *);
int pertence (tipo_conjunto *, int);
int menor_valor (tipo_conjunto *);
int maior_valor (tipo_conjunto *);
int compara_conjunto (tipo_conjunto *,tipo_conjunto *);
int tamanho_conjunto (tipo_conjunto *);
int tamanho_conjuntop (tipo_vet_print *);
int is_conjunto_vazio (tipo_conjunto *);
tipo_vet_print *conjunto_para_impressao (tipo_conjunto *c);
