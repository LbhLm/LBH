#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int str_count(char* str1 /*in*/, char* str2 /*in*/, int* count) {
	int ret = 0;
	if (str1 == NULL || str2 == NULL || count == NULL) {
		ret = -1;
		printf("func str_count() err:%d (str1 == NULL || str2 == NULL || count == NULL)\n", ret);
		return ret;
	}
	char* tmpstr1 = str1;
	char* tmpstr2 = str2;
	int tmpcount = 0;

	while ((tmpstr1 = strstr(tmpstr1, tmpstr2)) != NULL) {
		tmpcount++;
		tmpstr1 += strlen(tmpstr2);
		if (*tmpstr1 == '\0') {
			break;
		}
	}
	*count = tmpcount;
	return ret;
}

int trimAllSpace(char* inbuf, char* outbuf) {
	int ret = 0;
	if (inbuf == NULL || outbuf == NULL) {
		ret = -1;
		printf("func trimAllSpace() err:%d (inbuf == NULL || outbuf == NULL)\n", ret);
		return ret;
	}
	char* buf1 = inbuf;
	char* buf2 = outbuf;
	while ((*buf2 = *buf1++) != '\0') {
		if ((*buf2) != ' ') {
			buf2++;
		}
	}

	return ret;
}

int trimSpace(char* inbuf, char* outbuf) {
	int ret = 0;
	if (inbuf == NULL || outbuf == NULL) {
		ret = -1;
		printf("func trimSpace() err:%d (inbuf == NULL || outbuf == NULL)\n", ret);
		return ret;
	}
	char* buf1 = inbuf;
	/*char* buf3 = buf1 + strlen(inbuf) - 1;*/
	char* buf3 = buf1 + strlen(inbuf);
	char* buf2 = outbuf;
	/*if (buf1-- < buf3++)*/
	if (buf1-- < buf3) {
		while (*++buf1 == ' ');
		while (*--buf3 == ' ');
	}
	else {
		ret = -2;
		printf("func trimSpace() err:%d (buf1-- < buf3)\n", ret);
		return ret;
	}
	
	while ((*buf2++ = *buf1++) && buf1 != ++buf3);
	*buf2 = '\0';

	//char* in = inbuf;
	//char* out = outbuf;

	//int i = 0, j = 0, count = 0;
	//j = strlen(in) - 1;
	//while (isspace(in[i]) && in[i] != '\0') {
	//	i++;
	//}
	//while (isspace(in[j]) && j > 0) {
	//	j--;
	//}
	//count = j - i + 1;
	//memcpy(out, in + i, count);
	//out[count] = '\0';

	return ret;
}

int getStr1Str2(char* souce, char* buf1, char* buf2) {
	int ret = 0;
	if (souce == NULL || buf1 == NULL || buf2 == NULL) {
		ret = -1;
		printf("func getStr1Str2() err:%d (souce == NULL || buf1 == NULL || buf2 == NULL)\n", ret);
		return ret;
	}
	char* str = souce;
	char* valude1 = buf1;
	char* valude2 = buf2;
	int i = 0;
	while ((*valude1 = *valude2 = *str++) != '\0') {
		if ((i++ % 2) == 0) {
			valude2++;
		}
		else {
			valude1++;
		}
	}
	*valude1 = *valude2 = '\0';

	return ret;
}

int main() {
	int ret = 0;

	//strstr(str1, str2);  // 返回 str2 在 str1 的第一个位置的首地址


	char* str1 = "abcd121212abcd121212abcd121212qqqabcd";
	char* str2 = "abcd";
	char* str3 = NULL;
	int count = 0;

	ret = str_count(str1, str2, &count);
	{
		if (ret != 0) {
			printf("func str_count() err:%d\n", ret);
			return ret;
		}
	}
	printf("count: %d\n", count);


	char* buf1 = "    adw  isn    ";
	char buf4[100] = { 0 };
	char buf2[100];

	ret = trimAllSpace(buf1, buf2);
	{
		if (ret != 0) {
			printf("func trimAllSpace() err:%d\n", ret);
			return ret;
		}
	}
	printf("buf2: %s\n", buf2);

	char buf3[100];

	ret = trimSpace(buf1, buf3);
	{
		if (ret != 0) {
			printf("func trimSpace() err:%d\n", ret);
			return ret;
		}
	}
	printf("buf3: %s\n", buf3);

	char valude1[100];
	char valude2[100];

	ret = getStr1Str2(str1, valude1, valude2);
	{
		if (ret != 0) {
			printf("func getStr1Str2() err:%d\n", ret);
			return ret;
		}
	}
	printf("valude1: %s, valude2: %s\n", valude1, valude2);

	system("pause");
	return ret;
}
