#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct file_header_struct
{
	char file_name[256];
	long long file_offset;
	long long file_size;
}file_header_struct;

int main()
{
	int file_count;
	printf("패킹 할 파일 개수를 입력 해주세요 :");

	scanf_s("%d",&file_count);
	file_header_struct* header_list= malloc(sizeof(file_header_struct) * 256);
	
	// struct file_header_struct header_list[256] = { 0 };


	for (int i = 0; i < file_count; i++)
	{
		printf("%d 번 파일 이름: ",i);
		scanf_s("%s", header_list[i].file_name,(unsigned)_countof(header_list[i].file_name));
	}

	// 패킹 파일 만들기
	FILE* fp;
	fopen_s(&fp,"pack_file.pro", "wb");

	// 헤더 만들기
	const char* identify = "NAMUWIKI";

	fwrite(identify, 8, 1, fp); 
	fwrite(&file_count, 4, 1, fp);


	long long Cumulative_size = (long long)(sizeof(file_header_struct) * file_count);
	long file_size;
	for (int i = 0; i < file_count; i++)
	{
		FILE* temp_fp = NULL;
		int err = fopen_s(&temp_fp, header_list[i].file_name, "rb");

		if (err != 0)
		{
			printf("%s 파일이 존재하지 않습니다.\n", header_list[i].file_name);
			gets(header_list[255].file_name);
			gets(header_list[255].file_name);
			gets(header_list[255].file_name);
			return 0;
		}
		if ((long long)fseek(temp_fp, 0, SEEK_END) == 0)
		{
			file_size = ftell(temp_fp);
		}
		else
		{
			printf("offset error!\n");
			return 0;
		}


		header_list->file_size = file_size;
		header_list->file_offset = Cumulative_size;
		Cumulative_size += file_size;
		fclose(temp_fp);
	}

	for (int i = 0; i < file_count; i++)
	{
		fwrite(&header_list[i], sizeof(struct file_header_struct), 1, fp);
	}

	// 파일 데이터 부분 처리
	for (int i = 0; i < file_count; i++)
	{
		FILE* cur_file_fp;
		fopen_s(&cur_file_fp,header_list[i].file_name, "rb");
		printf("현재 패킹중인 파일: %s\n", header_list[i].file_name);
		char page[4096];
		int read_size;
		while ((read_size = fwrite(page, 4096, 1, cur_file_fp)) > 0)
		{
			fwrite(page, read_size, 1, fp);
		}
		printf("패킹 완료된 파일: %s\n", header_list[i].file_name);
		fclose(cur_file_fp);
	}

	printf("완료.\n");


	getchar();
	return 0;
}