#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Program Compiler Garuda Programming Language Project
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
char top(stack *s);
void destroyStack(stack *s);
int compiler(stack *s, const char *input);

//========================================================

int main()
{
    stack s;
    char line[1000];
    char input[10000] = ""; 
    char pilih;

    s.counter = 0;
    s.top = NULL;

    do
    {
        system("cls");
        printf("Compiler Garuda Programming Language Project\n");
        printf("Masukkan kode anda (tekan Enter pada baris kosong untuk melanjutkan ke validasi):\n");

        while (1)
        {
            fgets(line, sizeof(line), stdin);
            line[strcspn(line, "\n")] = 0; 

            if (strlen(line) == 0) // Berhenti hanya pada line kosong
                break;

            strcat(input, line); 
        }

        if (compiler(&s, input))
        {
            printf("Brackets seimbang.\n");
        }
        else
        {
            printf("Brackets tidak seimbang.\n");
        }

        printf("\nApakah Anda ingin mengulang program? (tekan X untuk keluar, tekan tombol apapun untuk melanjutkan): ");
        pilih = getchar();

        strcpy(input, ""); 

    } while (pilih != 'x' && pilih != 'X');

    return 0;
}

//========================================================

int isEmpty(stack *s)
{
    return s->top == NULL;
}

//========================================================

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

char StackTop(stack *s)
{
    if (!isEmpty(s))
        return s->top->data;
    return '\0'; 
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
    s->counter = 0;
}

//========================================================

int compiler(stack *s, const char *input)
{
    destroyStack(s);

    for (int i = 0; input[i] != '\0'; i++)
    {
        char current = input[i];

        if (current == '(' || current == '[' || current == '{' || current == '<')
        {
            push(s, current);
        }
        else if (current == ')' || current == ']' || current == '}' || current == '>')
        {
            if (isEmpty(s)) // Memberhentikan program jika terdapat kurung tutup sebelum kurung buka
            {
                destroyStack(s);
                printf("Ada tanda '%c' sebelum pasangan yang sesuai.\n", current);
                return 0;
            }

            char topBracket = StackTop(s);

            if ((current == ')' && topBracket == '(') || // Mengecek pasangan bracket
                (current == ']' && topBracket == '[') ||
                (current == '}' && topBracket == '{') ||
                (current == '>' && topBracket == '<'))
            {
                pop(s);
            }
            else
            {
                destroyStack(s);
                printf("Bracket '%c' tidak cocok dengan '%c'.\n", topBracket, current); // Memberhentikan program jika tidak ditemukan pasangan
                return 0;
            }
        }
    }

    if (isEmpty(s))
    {
        destroyStack(s);
        return 1; 
    }
    else
    {
        destroyStack(s);
        return 0;
    }
}

//========================================================
