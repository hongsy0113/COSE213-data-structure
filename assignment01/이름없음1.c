#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_YEAR_DURATION	10	// �Ⱓ

// ����ü ����
typedef struct {
	char	name[20];		// �̸�
	char	sex;			// ���� M or F
	int		freq[MAX_YEAR_DURATION]; // ������ ��
} tName;

typedef struct {
	int		len;		// �迭�� ����� �̸��� ��
	int		capacity;	// �迭�� �뷮 (�迭�� ���� ������ �̸��� ��)
	tName	*data;		// �̸� �迭�� ������
} tNames;

// �Լ� ���� ����

// ������ �Է� ������ �о� �̸� ����(�̸�, ����, ��)�� �̸� ����ü�� ����
// �̹� ����ü�� �����ϴ�(�����) �̸��� �ش� ������ �󵵸� ����
// ���� ������ �̸��� ����ü�� �߰�
// ���ǻ���: ���� �̸��� ��/�� ���� ���� �� �����Ƿ�, �̸��� ������ �����ؾ� ��
// names->capacity�� 2�辿 ����
void load_names( FILE *fp, int year_index, tNames *names);

// ����ü �迭�� ȭ�鿡 ���
void print_names( tNames *names, int num_year);

// qsort�� ���� �� �Լ�
int compare( const void *n1, const void *n2);

// �Լ� ����

// �̸� ����ü �ʱ�ȭ
// len�� 0����, capacity�� 1�� �ʱ�ȭ
// return : ����ü ������
tNames *create_names(void)
{
	tNames *pnames = (tNames *)malloc( sizeof(tNames));
	
	pnames->len = 0;
	pnames->capacity = 1;
	pnames->data = (tName *)malloc(pnames->capacity * sizeof(tName));

	return pnames;
}

// �̸� ����ü�� �Ҵ�� �޸𸮸� ����
void destroy_names(tNames *pnames)
{
	free(pnames->data);
	pnames->len = 0;
	pnames->capacity = 0;

	free(pnames);
}	
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
	tNames *names;
	
	int num = 0;
	FILE *fp;
	int num_year = 0;
	
	if (argc == 1) return 0;

	// �̸� ����ü �ʱ�ȭ
	//names = create_names();

	// ù ���� �˾Ƴ��� "yob2009.txt" -> 2009
	int start_year = atoi( &argv[1][3]);
	
	for (int i = 1; i < argc; i++)
	{
		num_year++;
		fp = fopen( argv[i], "r");
		assert( fp != NULL); // '�����̸� ���α׷� ����'
		
		int year = atoi( &argv[i][3]); // ex) "yob2009.txt" -> 2009
		
		fprintf( stderr, "Processing [%s]..\n", argv[i]);
		   
		// ������ �Է� ����(�̸� ����)�� ����ü�� ����
		//load_names( fp, year-start_year, names);
		
		fclose( fp);
	}
	
	// ���� (�̸��� (�̸��� ���� ��� ������))
	//qsort( names->data, names->len, sizeof(tName), compare);
	
	// �̸� ����ü�� ȭ�鿡 ���
	//print_names( names, num_year);

	// �̸� ����ü ����
	//destroy_names( names);
	
	return 1;
}

