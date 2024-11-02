#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Program Circular Linked List
// Fadhil Djibran 23081010030
// Struktur Data F081

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

// node *createNode(void);
void tambahAwal(node **list);
void tambahData(node **list);
void tambahAkhir(node **list);
void hapusAwal(node **list);
void hapusData(node **list);
void hapusAkhir(node **list);
void search(node **list);
void count(node **list);
void sum(node **list);
void traverse(node *list);

//========================================================

int main()
{
    node *list;
    char pilih;

    list = NULL;
    do
    {
        system("cls");
        printf("Pilihan program circular linked list:\n");
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
            tambahAwal(&list);
        else if (pilih == '2')
            tambahData(&list);
        else if (pilih == '3')
            tambahAkhir(&list);
        else if (pilih == '4')
            hapusAwal(&list);
        else if (pilih == '5')
            hapusData(&list);
        else if (pilih == '6')
            hapusAkhir(&list);
        else if (pilih == '7')
            search(&list);
        else if (pilih == '8')
            count(&list);
        else if (pilih == '9')
            sum(&list);
        else if (pilih == '0')
        {
            traverse(list);
            printf("\nTekan ENTER untuk melanjutkan.");
            getch();
        }
    } while (pilih != 'x');

    return 0;
}

void tambahAwal(node **list)
{
    int bil;
    node *pNew, *pPre;

    system("cls");
    traverse(*list);
    fflush(stdin);
    printf("\nMasukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = bil;
        if (*list == NULL)
        {
            pNew->next = pNew;
            *list = pNew;
        }
        else
        {
            pPre = *list;
            while (pPre->next != *list)
            {
                pPre = pPre->next;
            }

            pNew->next = *list;
            pPre->next = pNew;
            *list = pNew;
        }
    }
    else
    {
        printf("Alokasi memori gagal");
        getch();
    }

    traverse(*list);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void tambahData(node **list)
{
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    traverse(*list);
    printf("\nPosisi penyisipan terletak setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nMasukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*list == NULL)
    {
        printf("\nTekan ENTER untuk melanjutkan.");
        getch();
        return;
    }

    pCur = *list;

    while (pCur->data != pos)
    {
        pCur = pCur->next;

        if (pCur == *list)
        {
            printf("\nNode tidak ditemukan.");
            printf("\nTekan ENTER untuk melanjutkan.");
            getch();
            return;
        }
    }

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL)
    {
        printf("\nAlokasi memori gagal");
        getch();
        return;
    }

    pNew->data = bil;
    pNew->next = pCur->next;
    pCur->next = pNew;

    system("cls");
    traverse(*list);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void tambahAkhir(node **list)
{
    int bil;
    node *pNew, *pCur;

    system("cls");
    traverse(*list);
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
        if (*list == NULL)
        {
            *list = pNew;
            pNew->next = pNew;
        }
        else
        {
            pCur = *list;
            while (pCur->next != *list)
            {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->next = *list;
        }
    }

    system("cls");
    traverse(*list);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void hapusAwal(node **list)
{
    node *pCur, *pPre;

    system("cls");
    fflush(stdin);

    if (*list == NULL)
    {
        printf("List sudah kosong.\n");
    }
    else
    {
        pCur = *list;

        if (pCur->next == *list)
        {
            *list = NULL;
        }
        else
        {
            pPre = *list;
            while (pPre->next != *list)
            {
                pPre = pPre->next;
            }

            *list = pCur->next;
            pPre->next = *list;
        }

        free(pCur);
    }

    traverse(*list);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void hapusData(node **list)
{
    int pos;
    node *pCur, *pPre;

    system("cls");
    traverse(*list);
    printf("\nMasukkan data yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &pos);

    pCur = *list;
    pPre = NULL;

    if (*list != NULL)
    {
        while (pCur->data != pos)
        {
            if (pCur->next == *list)
            {
                pCur = NULL;
                break;
            }
            pPre = pCur;
            pCur = pCur->next;
        }
    }

    if (pCur == NULL)
    {
        printf("\nData tidak ditemukan.\n");
    }
    else
    {

        if (pPre == NULL)
        {
            if (pCur->next == *list)
            {
                *list = NULL;
            }
            else
            {
                pPre = *list;
                while (pPre->next != *list)
                {
                    pPre = pPre->next;
                }
                *list = pCur->next;
                pPre->next = *list;
            }
        }
        else
        {
            pPre->next = pCur->next;
        }
        free(pCur);
    }

    traverse(*list);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void hapusAkhir(node **list)
{
    node *pCur, *pPre;

    system("cls");

    if (*list == NULL)
    {
        printf("\nList sudah kosong.\n");
        return;
    }

    pCur = *list;
    pPre = NULL;

    while (pCur->next != *list)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    if (pPre == NULL)
    {
        *list = NULL;
    }
    else
    {
        pPre->next = *list;
    }

    free(pCur);
    traverse(*list);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void search(node **list)
{
    node *pCur, *pPre;
    int bil;
    int index = 0;

    system("cls");
    printf("\nMasukkan bilangan yang ingin dicari: ");
    fflush(stdin);
    scanf("%d", &bil);

    pPre = *list;
    pCur = *list;

    if (pCur == NULL)
    {
        printf("List kosong.\n");
        printf("\nTekan ENTER untuk melanjutkan.");
        getch();
        return;
    }

    while (pCur->next != *list && pCur->data != bil)
    {
        pPre = pCur;
        pCur = pCur->next;
        index++;
    }

    system("cls");
    if (pCur->data == bil)
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

void count(node **list)
{
    node *pCur;
    int index = 0;

    system("cls");
    pCur = *list;

    if (pCur == NULL)
    {
        printf("List kosong. Total jumlah data adalah 0\n");
        printf("\nTekan ENTER untuk melanjutkan.");
        getch();
        return;
    }

    while (pCur != *list || index == 0)
    {
        index++;
        pCur = pCur->next;
    }

    printf("Total jumlah data di list adalah %d\n", index);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void sum(node **list)
{
    node *pCur;
    int sum = 0;

    system("cls");

    pCur = *list;

    while (pCur != *list || sum == 0)
    {
        sum += pCur->data;
        pCur = pCur->next;
    }

    printf("Total hasil penjumlahan semua data di list adalah %d\n", sum);
    printf("\nTekan ENTER untuk melanjutkan.");
    getch();
}

//========================================================

void traverse(node *list)
{
    node *pWalker;

    system("cls");

    if (list == NULL)
    {
        printf("List kosong");
        return;
    }

    pWalker = list;
    printf("List berisi:\n");

    while (pWalker->next != list)
    {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    }

    printf("%d", pWalker->data);
}

//========================================================
