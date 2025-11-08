#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// estrututa Sala
typedef struct Room {
    char name[50];           
    struct Room* left;  
    struct Room* right; 
} Room;
// Criador de nova sala
Room* createRoom(char* name) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    if (newRoom == NULL) {
        printf("Erro ao alocar memoria para a sala.\n");
        exit(1);
    }
    strcpy(newRoom->name, name); 
    newRoom->left = NULL;     
    newRoom->right = NULL;
    return newRoom;
}
// navegador de salas
void navigatorRoom(Room* actual) {
    while (actual != NULL) {
        printf("Sua localizacao atual: >>> %s <<<\n\n", actual->name);
        if (actual->left == NULL && actual->right == NULL) {
            printf("Este comodo nao tem caminhos para esquerda ou direita. Exploracao terminada.\n");
            break; 
        }
        char option;
        printf("e - Ir para a esquerda\n");
        printf("d - Ir para a direita\n");
        printf("s - Sair da exploracao\n");
        printf("Digite uma letra inicial de acordo com o caminho a ir: ");
        scanf(" %c", &option);
        if (option == 'e' || option == 'E') {
            if (actual->left != NULL) {
                actual = actual->left;
            } else {
                printf("Nao ha caminho para a esquerda. Tente novamente.\n");
            }
        } else if (option == 'd' || option == 'D') {
            if (actual->right != NULL) {
                actual = actual->right; 
            } else {
                printf("Nao ha caminho para a direita. Tente novamente.\n");
            }
        } else if (option == 's' || option == 'S') {
            printf("Saindo..\n");
            break;
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
}
//inicia interacao com o ususario
void startNavigation(){
    Room* root = createRoom("Hall de entrada");
    root->left = createRoom("Sala de estar");
    root->right = createRoom("Cozinha");
    root->left->left = createRoom("Quarto principal");
    root->left->right = createRoom("Banheiro");
    root->right->left = createRoom("Jardim");
    root->right->right = createRoom("Garagem");
    root->left->left->left = createRoom("Closet");
    root->right->left->right = createRoom("Piscina");
    printf("= = = = = = = = = = = = = = = = = = = = == = = =\n");
    printf("               Detective Quest!                  \n");
    printf("= = = = = = = = = = = = = = = = = = = = == = = =\n");
    printf("Explore a mansao a partir do Hall de entrada.\n\n");
    navigatorRoom(root);
}
int main() {
startNavigation();
    return 0;
}