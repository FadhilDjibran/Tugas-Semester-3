#include <stdio.h>
#include <stdlib.h>

// Program Mengubah Infix ke postfix
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

void destroyStack(stack *s);
int isDigit(char c);
int isEmpty(stack *s);
void push(stack *s, char c);
char pop(stack *s);
char stackTop(stack *s);
void infixToPostfix(stack *s, char *input);

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
        printf("Program Mengubah Infix ke postfix\n");
        printf("Masukkan ekspresi infix: ");
        fgets(input, sizeof(input), stdin);

        printf("Ekspresi postfix: ");
        infixToPostfix(&s, input);
        printf("\n");

        printf("\nApakah Anda ingin mengulang program? (tekan X untuk keluar, tekan tombol apapun untuk melanjutkan): ");
        pilih = getchar();

    } while (pilih != 'x' && pilih != 'X');

    return 0;
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

int isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

//========================================================

int isEmpty(stack *s)
{
    return s->counter == 0;
}

//========================================================

void push(stack *s, char c)
{
    node *pnew = (node *)malloc(sizeof(node));
    if (pnew != NULL)
    {
        pnew->data = c;
        pnew->next = s->top;
        s->top = pnew;
        s->counter++;
    }
    else
        printf("Memori tidak cukup\n");
}

//========================================================

char pop(stack *s)
{
    if (!isEmpty(s))
    {
        node *temp = s->top;
        char value = temp->data;
        s->top = s->top->next;
        free(temp);
        s->counter--;
        return value;
    }
}

//========================================================

char stackTop(stack *s)
{
    if (!isEmpty(s))
    {
        return s->top->data;
    }
    return 0;
}

//========================================================

void infixToPostfix(stack *s, char *input)
{
    destroyStack(s);
    int i = 0;
    char c;

    while ((c = input[i++]) != '\0')
    {
        if (isDigit(c))
        {
            printf("%c ", c);
        }
        else if (c == '(')
        {
            push(s, c);
        }
        else if (c == ')')
        {
            while (!isEmpty(s) && stackTop(s) != '(')
            {
                printf("%c ", pop(s));
            }
            pop(s);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int precedence1;
            if (c == '+' || c == '-')
            {
                precedence1 = 1;
            }
            else if (c == '*' || c == '/')
            {
                precedence1 = 2;
            }

            while (!isEmpty(s))
            {
                int precedence2;
                if (stackTop(s) == '+' || stackTop(s) == '-')
                {
                    precedence2 = 1;
                }
                else if (stackTop(s) == '*' || stackTop(s) == '/')
                {
                    precedence2 = 2;
                }
                else
                {
                    break;
                }

                if (precedence2 < precedence1)
                {
                    break;
                }
                printf("%c ", pop(s));
            }
            push(s, c);
        }
    }

    while (!isEmpty(s))
    {
        printf("%c ", pop(s));
    }
}

//========================================================
