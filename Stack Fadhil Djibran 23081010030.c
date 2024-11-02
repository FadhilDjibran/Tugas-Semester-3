#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Program Stack
// Fadhil Djibran 23081010030
// Struktur Data F081
// Push Stack
// Pop Stack
// Stack Top
// Empty Stack
// Full Stack
// Stack Count
// Destroy Stack

typedef struct node
{
    int data;
    struct node *next;

} node;

typedef struct stack
{
    int counter;
    node *top;

} stack;

// node *createNode(void);
void tambahStack(stack *stack);
void hapusStack(stack *stack);
void stackTop(stack *stack);
void traverse(stack *stack);
int isEmpty(stack *stack);
int isFull(stack *stack);
int stackCount(stack *stack);
void destroyStack(stack *stack);

//========================================================

int main()
{
    stack stack;
    char pilih;

    stack.top = NULL;
    stack.counter = 0;

    do
    {
        system("cls");
        printf("Pilihan program stack: (Maksimum 10 Data)\n");
        printf("0. Cetak isi stack\n");
        printf("1. Tambah data ke stack (Push Stack)\n");
        printf("2. Hapus data pada stack (Pop Stack)\n");
        printf("3. Cek data paling atas stack (Stack Top)\n");
        printf("4. Cek apakah stack kosong (Empty Stack)\n");
        printf("5. Cek apakah stack full (Full Stack)\n");
        printf("6. Cek jumlah data didalam stack (Stack Count)\n");
        printf("7. Hapus semua isi stack (Destroy Stack)\n");
        printf("MASUKKAN PILIHAN (pilih X untuk keluar) : ");
        fflush(stdin);
        scanf(" %c", &pilih);

        if (pilih == '1')
            tambahStack(&stack);
        else if (pilih == '2')
            hapusStack(&stack);
        else if (pilih == '3')
            stackTop(&stack);
        else if (pilih == '4')
        {
            system("cls");
            if (isEmpty(&stack))
                printf("Stack kosong.\n");
            else
                printf("Stack tidak kosong.\n");
            printf("\nTekan ENTER untuk melanjutkan.");
            getch();
        }
        else if (pilih == '5')
        {
            system("cls");
            if (isFull(&stack))
                printf("Stack penuh.\n");
            else
                printf("Stack tidak penuh.\n");
            printf("\nTekan ENTER untuk melanjutkan.");
            getch();
        }
        else if (pilih == '6')
        {
            system("cls");
            printf("Jumlah elemen dalam stack adalah %d\n", stackCount(&stack));
            printf("\nTekan ENTER untuk melanjutkan.");
            getch();
        }
        else if (pilih == '7')
        {
            system("cls");
            destroyStack(&stack);
            printf("Stack telah dihancurkan.\n");
            stack.top = NULL;
            stack.counter = 0;
            printf("\nTekan ENTER untuk melanjutkan.");
            getch();
        }
        else if (pilih == '0')
        {
            system("cls");
            traverse(&stack);
            printf("\nTekan ENTER untuk melanjutkan.");
            getch();
        }
    } while (pilih != 'x' && pilih != 'X');

    return 0;
}

//========================================================

void tambahStack(stack *stack)
{
    int bil;
    node *pNew;

    system("cls");
    traverse(stack);

    if (isFull(stack))
    {
        printf("Stack penuh! Tidak dapat menambah elemen baru.\n");
        getch();
        return;
    }

    printf("\nMasukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL)
    {
        pNew->data = bil;
        pNew->next = stack->top;
        stack->top = pNew;
        stack->counter++;
    }
    else
    {
        printf("Alokasi memori gagal");
        getch();
    }

    system("cls");
    traverse(stack);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void hapusStack(stack *stack)
{
    node *pCur;

    system("cls");
    fflush(stdin);

    if (isEmpty(stack))
    {
        printf("Stack sudah kosong.\n");
    }
    else
    {
        pCur = stack->top;
        stack->top = pCur->next;
        free(pCur);
        stack->counter--;
    }

    system("cls");
    traverse(stack);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void stackTop(stack *stack)
{
    system("cls");
    if (stack->top != NULL)
    {
        printf("Data paling atas: %d\n", stack->top->data);
    }
    else
    {
        printf("Stack kosong.\n");
    }
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void traverse(stack *stack)
{
    node *pWalker;

    system("cls");
    pWalker = stack->top;

    if (pWalker == NULL)
    {
        printf("Stack kosong.\n");
        return;
    }

    printf("Isi stack:\n");
    printf("Top -> ");
    while (pWalker != NULL)
    {
        printf("%d", pWalker->data);
        pWalker = pWalker->next;
        if (pWalker != NULL)
        {
            printf(" -> ");
        }
    }
    printf(" -> Bottom\n");
}

//========================================================

int isEmpty(stack *stack)
{
    return stack->top == NULL;
}

//========================================================

int isFull(stack *stack)
{
    return stack->counter >= 10;
}

//========================================================

int stackCount(stack *stack)
{
    return stack->counter;
}

//========================================================

void destroyStack(stack *stack)
{
    node *temp;

    while (stack->top != NULL)
    {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}
