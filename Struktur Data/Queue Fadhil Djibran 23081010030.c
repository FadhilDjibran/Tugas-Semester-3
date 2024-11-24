#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Program Queue
// Fadhil Djibran 23081010030
// Pemrograman Lanjut D081

typedef struct node {
    char data[50];
    struct node *link;
} node;

typedef struct queueHead {
    node *front;
    node *rear;
    int count;
} queueHead;

//========================================================

void createQueue(queueHead *queue);
void enqueue(queueHead *queue);
void dequeue(queueHead *queue);
void queueFront(queueHead *queue);
void queueRear(queueHead *queue);
int isEmpty(queueHead *queue);
int isFull(queueHead *queue);
int queueCount(queueHead *queue);
void destroyQueue(queueHead *queue);
void traverse(queueHead *queue);

#define jumlahMaksAntrian 10

//========================================================

int main() {
    queueHead queue;
    char pilih;

    createQueue(&queue);

    do {
        system("cls");
        printf("Pilihan program queue: (Maksimum %d Data)\n", jumlahMaksAntrian);
        printf("0. Cetak isi queue\n");
        printf("1. Tambah data ke belakang antrian (Enqueue)\n");
        printf("2. Hapus data terdepan pada antrian (Dequeue)\n");
        printf("3. Cek data paling depan antrian (Queue Front)\n");
        printf("4. Cek data paling belakang antrian (Queue Rear)\n");
        printf("5. Cek apakah antrian kosong (Empty Queue)\n");
        printf("6. Cek apakah antrian penuh (Full Queue)\n");
        printf("7. Cek jumlah data di dalam antrian (Queue Count)\n");
        printf("8. Hapus antrian (Destroy Queue)\n");
        printf("MASUKKAN PILIHAN (pilih X untuk keluar) : ");
        fflush(stdin);
        scanf(" %c", &pilih);

        switch (pilih) {
            case '1': enqueue(&queue); break;
            case '2': dequeue(&queue); break;
            case '3': queueFront(&queue); break;
            case '4': queueRear(&queue); break;
            case '5':
                system("cls");
                if (isEmpty(&queue)) {
                    printf("Queue kosong.\n");
                } else {
                    printf("Queue tidak kosong.\n");
                }
                printf("\nTekan tombol apapun untuk melanjutkan.");
                getch();
                break;
            case '6':
                system("cls");
                if (isFull(&queue)) {
                    printf("Queue penuh.\n");
                } else {
                    printf("Queue tidak penuh.\n");
                }
                printf("\nTekan tombol apapun untuk melanjutkan.");
                getch();
                break;
            case '7':
                system("cls");
                printf("Jumlah elemen dalam queue ada %d.\n", queueCount(&queue));
                printf("\nTekan tombol apapun untuk melanjutkan.");
                getch();
                break;
            case '8':
                system("cls");
                destroyQueue(&queue);
                printf("Queue telah dihancurkan.\n");
                printf("\nTekan tombol apapun untuk melanjutkan.");
                getch();
                break;
            case '0':
                system("cls");
                traverse(&queue);
                printf("\nTekan tombol apapun untuk melanjutkan.");
                getch();
                break;
        }
    } while (pilih != 'x' && pilih != 'X');

    return 0;
}

//========================================================

void createQueue(queueHead *queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
}

//========================================================

void enqueue(queueHead *queue) {
    system("cls");
    char str[50];
    node *pNew;

    if (isFull(queue)) {
        printf("Queue penuh! Tidak dapat menambah elemen baru.\n");
        getch();
        return;
    }

    printf("Masukkan data: ");
    fflush(stdin);
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Menghapus newline dari input

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        strcpy(pNew->data, str);
        pNew->link = NULL;
        if (queue->rear == NULL) {
            queue->front = pNew;
        } else {
            queue->rear->link = pNew;
        }
        queue->rear = pNew;
        queue->count++;
    } else {
        printf("Alokasi memori gagal.\n");
        getch();
    }
    system("cls");
    traverse(queue);
    printf("\nTekan tombol apapun untuk melanjutkan.");
    getch();
}

//========================================================

void dequeue(queueHead *queue) {
    system("cls");
    node *pTemp;

    if (isEmpty(queue)) {
        printf("Queue kosong. Tidak ada elemen untuk dihapus.\n");
        getch();
        return;
    }

    pTemp = queue->front;
    queue->front = queue->front->link;
    free(pTemp);
    queue->count--;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    system("cls");
    traverse(queue);
    printf("\nTekan tombol apapun untuk melanjutkan.");
    getch();
}

//========================================================

void queueFront(queueHead *queue) {
    system("cls");
    if (isEmpty(queue)) {
        printf("Queue kosong.\n");
    } else {
        printf("Data paling depan adalah '%s'\n", queue->front->data);
    }
    printf("\nTekan tombol apapun untuk melanjutkan.");
    getch();
}

//========================================================

void queueRear(queueHead *queue) {
    system("cls");
    if (isEmpty(queue)) {
        printf("Queue kosong.\n");
    } else {
        printf("Data paling belakang adalah '%s'\n", queue->rear->data);
    }
    printf("\nTekan tombol apapun untuk melanjutkan.");
    getch();
}

//========================================================

int isEmpty(queueHead *queue) {
    return queue->count == 0;
}

//========================================================

int isFull(queueHead *queue) {
    return queue->count >= jumlahMaksAntrian;
}

//========================================================

int queueCount(queueHead *queue) {
    return queue->count;
}

//========================================================

void destroyQueue(queueHead *queue) {
    node *pTemp;

    while (queue->front != NULL) {
        pTemp = queue->front;
        queue->front = queue->front->link;
        free(pTemp);
    }
    queue->rear = NULL;
    queue->count = 0;
}

//========================================================

void traverse(queueHead *queue) {
    node *pWalker = queue->front;

    if (pWalker == NULL) {
        printf("Queue kosong.\n");
        return;
    }

    printf("Isi queue:\nFront <- ");
    while (pWalker != NULL) {
        printf("%s", pWalker->data);
        pWalker = pWalker->link;
        if (pWalker != NULL) {
            printf(" <- ");
        }
    }
    printf(" <- Rear\n");
}

//========================================================
