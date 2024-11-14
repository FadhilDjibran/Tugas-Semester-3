#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// Program Matching Balancing Parenthesis
// Fadhil Djibran
// 23081010030
// Struktur Data F081

//========================================================

typedef struct node
{
    char data;
    struct node *next;
} node;

typedef struct stack
{
    int counter;
    node *top;
} stack;

//========================================================

int isEmpty(stack *s);
void push(stack *s, char value);
void pop(stack *s);
void destroyStack(stack *s);
int MBP(stack *s, const char *input);

//========================================================

int main()
{
    stack s;
    char input[1000];
    char pilih;

    s.counter = 0;
    s.top = NULL;

    do
    {
        system("cls");
        printf("Program Matching Balancing Parenthesis\n");
        printf("Masukkan ekspresi dengan tanda kurung: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (MBP(&s, input))
        {
            printf("Tanda kurung seimbang.\n");
        }
        else
        {
            printf("Tanda kurung tidak seimbang.\n");
        }

        printf("\nApakah Anda ingin mengulang program? (tekan X untuk keluar, tekan tombol apapun untuk melanjutkan): ");
        pilih = getchar();

    } while (pilih != 'x' && pilih != 'X');

    return 0;
}

//========================================================

int isEmpty(stack *s)
{
    return s->top == NULL;
}

//========================================================0

void push(stack *s, char value)
{
    node *pnew = (node *)malloc(sizeof(node));
    if (pnew != NULL)
    {
        pnew->data = value;
        pnew->next = s->top;
        s->top = pnew;
        s->counter++;
    }
    else
        printf("Memori tidak cukup\n");
}

//========================================================

void pop(stack *s)
{
    if (!isEmpty(s))
    {
        node *temp = s->top;
        s->top = s->top->next;
        free(temp);
        s->counter--;
    }
}

//========================================================

void destroyStack(stack *s)
{
    while (s->top != NULL)
    {
        node *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

//========================================================

int MBP(stack *s, const char *input)
{
    destroyStack(s);

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '(')
        {
            push(s, '(');
        }
        else if (input[i] == ')')
        {
            if (isEmpty(s))
            {
                destroyStack(s);
                printf("Ada tanda ')' sebelum '('.\n");
                return 0;
            }
            pop(s);
        }
    }

    if (isEmpty(s))
    {
        destroyStack(s);
        return 1;
    }
}

//========================================================
