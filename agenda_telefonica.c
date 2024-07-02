#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct para armazenar o nome e número de telefone na agenda.
struct lista {

    char* nome;
    char* telefone;
    struct lista* prox;

};

typedef struct lista Lista;

//Função para criar lista.
Lista* cria_lista(){

    return NULL;

}

//Função para inserir um novo contato (nó) no inicio da lista.
Lista* insere_inicio(Lista* lst, char* n, char* tel){

    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->nome = n;
    novo->telefone = tel;
    novo->prox = lst;

    return novo;

}

//Função para inserir um contato (nó) ordenado pelo nome da pessoa na lista.
Lista* insere_ordenado(Lista* lst, char* n, char* tel){
    
    Lista* novo;
    Lista* ant = NULL;
    Lista* p = lst;

    while((p != NULL) && (strcmp(p->nome, n) < 0)){

        ant = p;
        p = p->prox;

    }

    novo = (Lista*) malloc(sizeof(Lista));
    novo->nome = n;
    novo->telefone = tel;

    if(ant == NULL){
        novo->prox = lst;
        lst = novo;
    } else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return lst;

}

//Função para remover o contato (nó) do nome especificado da lista.
Lista* remove_nome(Lista* lst, char* n){

    Lista* ant = NULL;
    Lista* p = lst;

    while((p != NULL) && (strcmp(p->nome, n) != 0)){

        ant = p;
        p = p->prox;

    }

    if(p == NULL){
        return lst;
    }

    if(ant == NULL){
        lst = p->prox;
    } else{
        ant->prox = p->prox;
    }

    free(p);
    return lst;

}

//Função para buscar o contato (nó) específico pelo nome na lista.
Lista* busca_nome(Lista* lst, char* n){

    Lista* p;

    for(p = lst; p != NULL; p = p->prox){
        if(p->nome == n){
            return p;
        }
    }

    return NULL;

}

//Função para imprimir a agenda completa.
void imprime_lista(Lista* lst){
    
    Lista* p;

    for(p = lst; p != NULL; p = p->prox){

        printf("Nome: %s\n", p->nome);
        printf("Telefone: %s\n", p->telefone);

    }

}

void limpar_agenda(Lista* lst){

    Lista* p = lst;

    while(p != NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }

}

int main(){

    //char nome[20];
    //char telefone[11];
    Lista* lista;
    Lista* contato;

    lista = cria_lista();

    lista = insere_ordenado(lista, "Yuri", "21984564308");
    lista = insere_ordenado(lista, "Git", "21999845701");
    lista = insere_ordenado(lista, "Teste", "21666664308");
    lista = insere_ordenado(lista, "Rafael", "21984566666");

    printf("\n");

    imprime_lista(lista);

    printf("\n");

    contato = busca_nome(lista, "Yuri");

    printf("%s\n%s\n", contato->nome, contato->telefone);

    remove_nome(lista, "Yuri");

    printf("\n");
    imprime_lista(lista);
    printf("\n");

    contato = busca_nome(lista, "Yuri");
    printf("%s\n%s\n", contato->nome, contato->telefone);
    printf("\n");
    
    /*int x = -1;
    while(x != 0){

        if(x == 0){
            break;
        } else if(x == 1){

            printf("Insira nome do contato: \n");
            scanf("%s", nome);
            printf("Insira o telefone do contato: \n");
            scanf("%s", telefone);

            lista = insere_ordenado(lista, nome, telefone);

        } else if(x == 2){

            printf("Insira nome do contato para buscar: \n");
            scanf("%s", nome);

            contato = busca_nome(lista, nome);

            if(contato == NULL){
                printf("Não existe esse contato!\n");
            } else{
                printf("Nome: %s\n", contato->nome);
                printf("Telefone: %s\n", contato->telefone);
            }

        } else if(x == 3){

            printf("Insira o nome do contato que quer deletar: \n");
            scanf("%s", nome);

            lista = remove_nome(lista, nome);

        } else if(x == 4){

            imprime_lista(lista);

        } else if(x == 5){

        }
                
        printf("1 - Inserir contato ordenado: \n");
        printf("2 - Buscar contato por nome: \n");
        printf("3 - Remover contato por nome: \n");
        printf("4 - Imprimir lista completa: \n");
        printf("5 - Limpar agenda\n");
        printf("0 - Sair\n");

        scanf("%d", &x);

    }*/

    return 0;
}