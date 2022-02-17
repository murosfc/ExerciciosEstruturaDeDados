
typedef struct racional tipo_racional;

tipo_racional *cria_racional (int,int);
void soma_racional (tipo_racional *, tipo_racional *, int*, int*);
void multiplica_racional (tipo_racional *, tipo_racional *, int*, int*);
int racionaiscmp (tipo_racional *, tipo_racional *);