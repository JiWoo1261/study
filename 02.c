#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENTS 10

typedef struct studentTag {
    char name[MAX_ELEMENTS];  // �̸�
    double score; // ����
    int student_id;  // �й� 
}student;

double score[MAX_ELEMENTS];

double get_max_score(student students[], int n);

int main(void)
{
    FILE* p;  // ���� ������ ����
    p = fopen("02.txt", "a+");  // a+ ���� ���� ����

    int result;

    srand(time(NULL));   // srand�� �õ尪 �ʱ�ȭ

    student students[MAX_ELEMENTS] = {
       { "kim",  rand() % 501 / 100.0, 2022156001 },  // rand()%501/100.0 -> 0���� 5������ �Ǽ��� ����
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

    result = get_max_score(students, MAX_ELEMENTS);  // �Լ� ȣ�� (�ִ� ���� result�� �Ҵ�)

    fprintf(p, "[1��]\n%s %d %.2lf\n\n",
        students[result].name, students[result].student_id, students[result].score);
    // ������ ���Ͽ� ���

    fclose(p);  //���� �ݱ�

    system("notepad.exe 02.txt");    // ����� ���� ����

    return 0;
}

double get_max_score(student students[], int n)
{
    int i, result = 0;

    for (i = 1; i < n; i++)  // �ִ� ���� ã��
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
//	char name[30]; //�̸�
//	int student_ID; //�й�
//	double score; //����
//}student;  //����ü  ����,  typedef �������� ���ο� �ڷ��� �̸� ���
//
//double scores[MAX];
//double get_max_score(student students[],int n);
//
//int main(void)
//{
//	FILE* p;
//	p = fopen("02.txt", "a+");  // write ���� ���� ����
//
//	int 
//	int a, b, c;
//
//	int array1[MAX_ELEMENTS] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	printf("3���� ������ �Է��Ͻÿ�.\n");
//	scanf("%d", &a); 
//
//	result1 = get_max_score(MAX);   //main �Լ����� 3�� get_max_score�� ����
//	result2 = seq_search(array1, MAX_ELEMENTS, 5);  //main �Լ����� array1,MAX_ELEMENTS,5�� seq_search�� ����
//
//	fprintf(p, "largest:%d\n", result1);
//	fprintf(p, "search:%d\n", result2);
//
//	fclose(p);  //���� �ݱ�
//	system("notepad.exe 02.txt");    // ����� ���� ����
//
//	return 0;
//}
//
//int get_max_score(int n)
//{
//	int i, largest;
//	largest = scores[0]; //�ʱⰪ  scores�迭 �ε��� 0
//
//	for (i = 1; i < n; i++)
//	{
//		if (scores[i] > largest)  // largest ã��
//		{
//			largest = scores[i];
//		}
//	}
//	return largest;  // �Է�: n, ó��: ū���� ȹ��, ���: int(����)
//}
//
//int seq_search(int* list, int n, int key)
//{
//	int i;
//	for (i = 0; i < n; i++)   // i�� 0~9
//	{
//		if (list[i] == key)
//			return i;  /* Ž���� �����ϸ� Ű ���� �ε��� ��ȯ */
//	}
//
//	return -1;    /* Ž���� �����ϸ� -1 ��ȯ */
//}