#include <stdio.h>
#include <string.h>

typedef struct person {
    int age;
    char name[20];
    double height;
} person;
typedef int (* sorton)(person *a,person*b);

int sortOnAge(person* a, person* b) // �������������ڻص�
{
    return a->age < b->age;
}

int sortOnName(person* a, person* b)// �������������ڻص�
{
    return strcmp(a->name, b->name);
}

int sortOnHeight(person* a, person* b)// ������������ڻص�
{
    return a->height < b->height;
}

void sort(person* a, int n,sorton callback) // �����ú��������ܴ�������ͱȽ��ûص�����
{
    int i, j;
    person t;
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n-i-1; ++j) // ��ð������
            if(callback(a+j, a+j+1)) { // ���ûص������Ƚ�
                memcpy(&t, a+j, sizeof(t));
                memcpy(a+j, a+j+1, sizeof(t));
                memcpy(a+j+1, &t, sizeof(t));
            }
    }
}

void show(const char* msg, person* p, int n) // �������
{
    puts(msg);
    int i;
    for(i = 0; i < n; ++i)
        printf("%d\t%s\t%.2f\n", p[i].age, p[i].name, p[i].height);
    putchar('\n');
}

int main()
{
    person a[5] = {
        {15, "lex", 153.5},
        {14, "jack", 155.8},
        {13, "liu", 144.8},
        {16, "king", 165.3},
        {15, "Ben", 159.7}
    };
    show("origin:", a, 5);
    sort(a, 5, sortOnAge); show("sort on age:", a, 5); // ����������
    sort(a, 5, sortOnName); show("sort on name:", a, 5); // ����������
    sort(a, 5, sortOnHeight); show("sort on height:", a, 5); // ���������
    return 1;
}
