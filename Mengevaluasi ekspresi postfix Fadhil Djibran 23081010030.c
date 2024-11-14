#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Program Mengevaluasi ekspresi postfix
// Fadhil Djibran
// 23081010030
// Struktur Data F081

//========================================================

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

//========================================================

void destroyStack(stack *s);
int isDigit(char c);
int isEmpty(stack *s);
void push(stack *s, int value);
int pop(stack *s);
int evaluasiPostfix(stack *s, char *input);

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
        printf("Program Mengevaluasi ekspresi postfix\n");
        printf("Masukkan ekspresi postfix (angka dipisah dengan spasi): ");
    	fgets(input, sizeof(input), stdin);
    	input[strcspn(input, "\n")] = 0;
    	printf("Hasil evaluasi postfix: %d\n", evaluasiPostfix(&s, input));
    	
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

void push(stack *s, int value)
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

int pop(stack *s)
{
    if (!isEmpty(s))
    {
        node *temp = s->top;
        int value = temp->data;
        s->top = s->top->next;
        free(temp);
        s->counter--;
        return value;
    }
}

//========================================================

int evaluasiPostfix(stack *s, char *input)
{
    destroyStack(s);
    char *token = strtok(input, " ");

    while (token != NULL)
    {
        if (isDigit(token[0]))
        {
            int num = atoi(token);
            push(s, num);
        }
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        {
            int val2 = pop(s);
            int val1 = pop(s);
            if (token[0] == '+')
            {
                push(s, val1 + val2);
            }
            else if (token[0] == '-')
            {
                push(s, val1 - val2);
            }
            else if (token[0] == '*')
            {
                push(s, val1 * val2);
            }
            else if (token[0] == '/')
            {
                push(s, val1 / val2);
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(s);
}

//========================================================
