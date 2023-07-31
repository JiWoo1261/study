#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10000 // 10의 승수 만큼 감소/증가 시켜 실험해볼 것
#define MAX_QUEUE_SIZE 10000

typedef struct ColorPen {
    int number;  //생산순서
    char pen_ID[10]; //볼펜ID
    char color[20]; //색정보
}ColorPen;

int black_cnt, red_cnt, blue_cnt, total_cnt;
typedef int element;

typedef struct { // 큐 타입
    element  data[MAX_QUEUE_SIZE];
    int  front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
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

// 삽입 함수
void enqueue(QueueType* q, element item)
{
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// 삭제 함수
element peek(QueueType* q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main()
{
    FILE* p; // 파일 포인터 생성

    clock_t start, stop;
    double duration;

    srand(time(NULL));

    QueueType red_queue;  // 빨간 볼펜 큐
    QueueType blue_queue;  // 파란 볼펜 큐
    QueueType black_queue;  // 검정 볼펜 큐

    init_queue(&red_queue);  // 큐 초기화
    init_queue(&blue_queue);  // 큐 초기화
    init_queue(&black_queue);  // 큐 초기화


    start = clock();    // 측정 시작

    p = fopen("04.txt", "a+");   // 덮어쓰기 모드로 파일 오픈

    for (int i = 1; i <= MAX; i++)
    {
        int rand1 = rand();
        while (1) {  // 중복 방지
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

        fprintf(stdout, "%생산순서 %05d번째 -> 볼펜ID: %d ", i, rand1);  // 랜덤번호 부여하며 볼펜 생성
        fprintf(p, "%생산순서 %05d번째 -> 볼펜ID: %d ", i, rand1);

        if (rand1 % 10 == 0 && !is_full(&red_queue))  // 빨간색 볼펜
        {
            red_cnt++;
            enqueue(&red_queue, red_cnt);
            fprintf(stdout, "RED");  // 색상 출력
            fprintf(p, "RED");
        }
        if (rand1 % 10 == 1 && !is_full(&blue_queue))  // 파란색 볼펜
        {
            blue_cnt++;
            enqueue(&blue_queue, blue_cnt);
            fprintf(stdout, "BLUE");   // 색상 출력
            fprintf(p, "BLUE");
        }
        if ((rand1 % 10 >= 2) && (rand1 % 10 <= 9) && !is_full(&black_queue))  // 검정색 볼펜
        {
            black_cnt++;
            enqueue(&black_queue, black_cnt);
            fprintf(stdout, "BLACK");   // 색상 출력
            fprintf(p, "BLACK");
        }

        fprintf(stdout, "\n\n");
        fprintf(p, "\n\n");
    }

    total_cnt = black_cnt + red_cnt + blue_cnt;  // 총 개수

    fprintf(stdout, "------------------------------------------------------");
    fprintf(p, "------------------------------------------------------");

    fprintf(stdout, "\n\n총생산볼펜 %d개: BLACK %d개, RED %d개, BLUE %d개\n\n", total_cnt, black_cnt, red_cnt, blue_cnt);  // 총 생산 볼펜 출력
    fprintf(p, "\n\n총생산볼펜 %d개: BLACK %d개, RED %d개, BLUE %d개\n\n", total_cnt, black_cnt, red_cnt, blue_cnt);

    stop = clock();   // 측정 종료
    duration = (double)(stop - start) / CLOCKS_PER_SEC; // 측정시간 계산

    fprintf(stdout, "\n총 생산 시간: %.2lf초\n\n", duration);  // 시간 출력
    fprintf(p, "\n총 생산 시간: %.2lf초\n\n", duration);

    fclose(p);

    system("notepad.exe 04.txt");  // 파일 오픈

    return 0;
}