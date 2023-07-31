#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10000 // 10�� �¼� ��ŭ ����/���� ���� �����غ� ��
#define MAX_QUEUE_SIZE 10000

typedef struct ColorPen {
    int number;  //�������
    char pen_ID[10]; //����ID
    char color[20]; //������
}ColorPen;

int black_cnt, red_cnt, blue_cnt, total_cnt;
typedef int element;

typedef struct { // ť Ÿ��
    element  data[MAX_QUEUE_SIZE];
    int  front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ����ť ��� �Լ�
void queue_print(QueueType* q)
{
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
    if (is_full(q))
        error("ť�� ��ȭ�����Դϴ�");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// ���� �Լ�
element peek(QueueType* q)
{
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main()
{
    FILE* p; // ���� ������ ����

    clock_t start, stop;
    double duration;

    srand(time(NULL));

    QueueType red_queue;  // ���� ���� ť
    QueueType blue_queue;  // �Ķ� ���� ť
    QueueType black_queue;  // ���� ���� ť

    init_queue(&red_queue);  // ť �ʱ�ȭ
    init_queue(&blue_queue);  // ť �ʱ�ȭ
    init_queue(&black_queue);  // ť �ʱ�ȭ


    start = clock();    // ���� ����

    p = fopen("04.txt", "a+");   // ����� ���� ���� ����

    for (int i = 1; i <= MAX; i++)
    {
        int rand1 = rand();
        while (1) {  // �ߺ� ����
            int flag = 0;
            int arr[MAX] = { 0 };
            for (int j = 0; j < i; j++) {
                if (arr[j] == rand1) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                arr[i - 1] = rand1;
                break;
            }
            else {
                rand1 = rand();
            }
        }

        fprintf(stdout, "%������� %05d��° -> ����ID: %d ", i, rand1);  // ������ȣ �ο��ϸ� ���� ����
        fprintf(p, "%������� %05d��° -> ����ID: %d ", i, rand1);

        if (rand1 % 10 == 0 && !is_full(&red_queue))  // ������ ����
        {
            red_cnt++;
            enqueue(&red_queue, red_cnt);
            fprintf(stdout, "RED");  // ���� ���
            fprintf(p, "RED");
        }
        if (rand1 % 10 == 1 && !is_full(&blue_queue))  // �Ķ��� ����
        {
            blue_cnt++;
            enqueue(&blue_queue, blue_cnt);
            fprintf(stdout, "BLUE");   // ���� ���
            fprintf(p, "BLUE");
        }
        if ((rand1 % 10 >= 2) && (rand1 % 10 <= 9) && !is_full(&black_queue))  // ������ ����
        {
            black_cnt++;
            enqueue(&black_queue, black_cnt);
            fprintf(stdout, "BLACK");   // ���� ���
            fprintf(p, "BLACK");
        }

        fprintf(stdout, "\n\n");
        fprintf(p, "\n\n");
    }

    total_cnt = black_cnt + red_cnt + blue_cnt;  // �� ����

    fprintf(stdout, "------------------------------------------------------");
    fprintf(p, "------------------------------------------------------");

    fprintf(stdout, "\n\n�ѻ��꺼�� %d��: BLACK %d��, RED %d��, BLUE %d��\n\n", total_cnt, black_cnt, red_cnt, blue_cnt);  // �� ���� ���� ���
    fprintf(p, "\n\n�ѻ��꺼�� %d��: BLACK %d��, RED %d��, BLUE %d��\n\n", total_cnt, black_cnt, red_cnt, blue_cnt);

    stop = clock();   // ���� ����
    duration = (double)(stop - start) / CLOCKS_PER_SEC; // �����ð� ���

    fprintf(stdout, "\n�� ���� �ð�: %.2lf��\n\n", duration);  // �ð� ���
    fprintf(p, "\n�� ���� �ð�: %.2lf��\n\n", duration);

    fclose(p);

    system("notepad.exe 04.txt");  // ���� ����

    return 0;
}