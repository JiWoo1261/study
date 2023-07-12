#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENTS 10

typedef struct studentTag {
    char name[MAX_ELEMENTS];  // 이름
    double score; // 학점
    int student_id;  // 학번 
}student;

double score[MAX_ELEMENTS];

double get_max_score(student students[], int n);

int main(void)
{
    FILE* p;  // 파일 포인터 생성
    p = fopen("02.txt", "a+");  // a+ 모드로 파일 오픈

    int result;

    srand(time(NULL));   // srand로 시드값 초기화

    student students[MAX_ELEMENTS] = {
       { "kim",  rand() % 501 / 100.0, 2022156001 },  // rand()%501/100.0 -> 0부터 5까지의 실수값 난수
       { "Park", rand() % 501 / 100.0, 2022156002 },
       { "Lim",  rand() % 501 / 100.0, 2022156003 },
       { "Lee",  rand() % 501 / 100.0, 2022156004 },
       { "ki",   rand() % 501 / 100.0, 2022156005 },
       { "Song", rand() % 501 / 100.0, 2022156006 },
       { "Min",  rand() % 501 / 100.0, 2022156007 },
       { "kang", rand() % 501 / 100.0, 2022156008 },
       { "Do",   rand() % 501 / 100.0, 2022156009 },
       { "Heon", rand() % 501 / 100.0, 2022156010 }
    };

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        score[i] = students[i].score;
    }

    result = get_max_score(students, MAX_ELEMENTS);  // 함수 호출 (최대 학점 result에 할당)

    fprintf(p, "[1등]\n%s %d %.2lf\n\n",
        students[result].name, students[result].student_id, students[result].score);
    // 파일을 통하여 출력

    fclose(p);  //파일 닫기

    system("notepad.exe 02.txt");    // 저장된 파일 오픈

    return 0;
}

double get_max_score(student students[], int n)
{
    int i, result = 0;

    for (i = 1; i < n; i++)  // 최대 학점 찾기
    {
        if (students[i].score > students[result].score)
        {
            result = i;
        }
    }
    return result;
}



----------------------------------------------------------------------
//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX 5
//#define MAX_ELEMENTS 10
//
//typedef struct student {
//	char name[30]; //이름
//	int student_ID; //학번
//	double score; //학점
//}student;  //구조체  정의,  typedef 선언으로 새로운 자료형 이름 명명
//
//double scores[MAX];
//double get_max_score(student students[],int n);
//
//int main(void)
//{
//	FILE* p;
//	p = fopen("02.txt", "a+");  // write 모드로 파일 오픈
//
//	int 
//	int a, b, c;
//
//	int array1[MAX_ELEMENTS] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	printf("3개의 정수를 입력하시오.\n");
//	scanf("%d", &a); 
//
//	result1 = get_max_score(MAX);   //main 함수에서 3을 get_max_score로 보냄
//	result2 = seq_search(array1, MAX_ELEMENTS, 5);  //main 함수에서 array1,MAX_ELEMENTS,5를 seq_search로 보냄
//
//	fprintf(p, "largest:%d\n", result1);
//	fprintf(p, "search:%d\n", result2);
//
//	fclose(p);  //파일 닫기
//	system("notepad.exe 02.txt");    // 저장된 파일 오픈
//
//	return 0;
//}
//
//int get_max_score(int n)
//{
//	int i, largest;
//	largest = scores[0]; //초기값  scores배열 인덱스 0
//
//	for (i = 1; i < n; i++)
//	{
//		if (scores[i] > largest)  // largest 찾기
//		{
//			largest = scores[i];
//		}
//	}
//	return largest;  // 입력: n, 처리: 큰점수 획득, 출력: int(정수)
//}
//
//int seq_search(int* list, int n, int key)
//{
//	int i;
//	for (i = 0; i < n; i++)   // i는 0~9
//	{
//		if (list[i] == key)
//			return i;  /* 탐색에 성공하면 키 값의 인덱스 반환 */
//	}
//
//	return -1;    /* 탐색에 실패하면 -1 반환 */
//}