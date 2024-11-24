
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Program Linked List
// Fadhil Djibran 23081010030
// Struktur Data F081

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

// node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void search(node **head);
void count(node **head);
void sum(node **head);
void traverse(node *head);

//========================================================

int main()
{
    node *head;
    char pilih;

    head = NULL;
    do
    {
        system("cls");
        printf("Pilihan program double linked list:\n");
        printf("0. Cetak isi list\n");
        printf("1. Tambah data di awal list\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir list\n");
        printf("4. Hapus data di awal list\n");
        printf("5. Hapus data di tengah list\n");
        printf("6. Hapus data di akhir list\n");
        printf("7. Pencarian isi list\n");
        printf("8. Cek jumlah data di list\n");
        printf("9. Cek hasil penjumlahan semua data di list\n");
        printf("MASUKKAN PILIHAN (pilih X untuk keluar) : ");
        fflush(stdin);
        scanf("%c", &pilih);
        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4')
            hapusAwal(&head);
        else if (pilih == '5')
            hapusData(&head);
        else if (pilih == '6')
            hapusAkhir(&head);
        else if (pilih == '7')
            search(&head);
        else if (pilih == '8')
            count(&head);
        else if (pilih == '9')
            sum(&head);
        else if (pilih == '0')
        {
            traverse(head);
            printf("\nTekan ENTER untuk melanjutkan.");
            getch();
        }
    } while (pilih != 'x');

    return 0;
}

//========================================================

void tambahAwal(node **head)
{
    int bil;
    node *pNew;

    system("cls");
    traverse(*head);
    fflush(stdin);
    printf("\nMasukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = bil;
        pNew->right = *head;

        if (*head != NULL)
        {
            (*head)->left = pNew;
        }

        pNew->left = NULL;
        *head = pNew;
    }
    else
    {
        printf("Alokasi memori gagal");
        getch();
    }

    traverse(*head);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void tambahData(node **head)
{
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    traverse(*head);
    printf("\nPosisi penyisipan terletak setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nMasukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos)
    {
        pCur = pCur->right;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL)
    {
        printf("\nNode tidak ditemukan ");
        printf("\nTekan ENTER untuk melanjutkan.");
        getch();
    }
    else if (pNew == NULL)
    {
        printf("\nAlokasi memori gagal");
        getch();
    }
    else
    {
        pNew->data = bil;
        pNew->left = pCur;
        pNew->right = pCur->right;

        if (pCur->right != NULL)
        {
            pCur->right->left = pNew;
        }

        pCur->right = pNew;
    }

    system("cls");
    traverse(*head);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void tambahAkhir(node **head)
{
    int bil;
    node *pNew, *pCur;

    system("cls");
    traverse(*head);
    printf("\nMasukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL)
    {
        printf("\nAlokasi memori gagal");
        getch();
    }
    else
    {
        pNew->data = bil;
        pNew->right = NULL;

        if (*head == NULL)
        {
            pNew->left = NULL;
            *head = pNew;
        }
        else
        {
            pCur = *head;
            while (pCur->right != NULL)
            {
                pCur = pCur->right;
            }
            pNew->left = pCur;
            pNew->right = pCur->right;
            pCur->right = pNew;
        }
    }

    system("cls");
    traverse(*head);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void hapusAwal(node **head)
{
    node *pCur;

    system("cls");
    fflush(stdin);

    if (*head == NULL)
    {
        printf("List sudah kosong.\n");
    }
    else
    {
        pCur = *head;
        *head = pCur->right;

        if (pCur->right != NULL)
        {
            pCur->right->left = pCur->left;
        }

        free(pCur);
    }

    traverse(*head);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void hapusData(node **head)
{
    int pos;
    node *pCur;

    system("cls");
    traverse(*head);
    printf("\nMasukkan data yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &pos);

    pCur = *head;

    // Traverse the list to find the node to delete
    while (pCur != NULL && pCur->data != pos)
    {
        pCur = pCur->right;
    }

    if (pCur == NULL)
    {
        printf("\nData tidak ditemukan\n");
    }
    else
    {
        if (pCur->left == NULL && pCur->right == NULL)
        {
            *head = NULL;
        }
        else if (pCur->left == NULL)
        {
            *head = pCur->right;
            pCur->right->left = NULL;
        }
        else
        {
            pCur->left->right = pCur->right;
            if (pCur->right != NULL)
            {
                pCur->right->left = pCur->left;
            }
        }

        free(pCur);
    }

    traverse(*head);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void hapusAkhir(node **head)
{
    node *pCur;

    system("cls");

    if (*head == NULL)
    {
        printf("\nList sudah kosong.\n");
        return;
    }

    pCur = *head;

    while (pCur->right != NULL)
    {
        pCur = pCur->right;
    }

    if (pCur->left == NULL)
    {
        *head = NULL;
    }
    else
    {
        pCur->left->right = NULL;
    }

    free(pCur);
    traverse(*head);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void search(node **head)
{
    node *pCur;
    int bil;
    int index = 0;

    system("cls");
    printf("\nMasukkan bilangan yang ingin dicari: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;

    while (pCur != NULL && pCur->data != bil)
    {
        pCur = pCur->right;
        index++;
    }

    system("cls");
    if (pCur != NULL)
    {
        printf("Data %d ditemukan pada urutan ke-%d\n", bil, index + 1);
    }
    else
    {
        printf("Data %d tidak ditemukan.\n", bil);
    }

    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void count(node **head)
{
    node *pCur;
    int index = 0;

    system("cls");
    pCur = *head;

    while (pCur != NULL)
    {
        pCur = pCur->right;
        index++;
    }

    printf("Total jumlah data di list adalah %d\n", index);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void sum(node **head)
{
    node *pCur;
    int sum = 0;

    system("cls");

    pCur = *head;

    while (pCur != NULL)
    {
        sum += pCur->data;
        pCur = pCur->right;
    }

    printf("Total hasil penjumlahan semua data di list adalah %d\n", sum);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void traverse(node *head)
{

    node *pWalker;

    system("cls");
    pWalker = head;
    while (pWalker != NULL)
    {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->right;
        printf(" -> ");
    }
    printf("NULL");
}
//========================================================
