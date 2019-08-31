#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 拷贝字符串
int copy_str(char* from, char* to) {
	// 提高函数兼容性 不报无必要的bug
	if (from == NULL || to == NULL) {
		return -1;
	}
	// 声明辅助指针 把形参接过来 避免随意改变形参的值
	char* tmpfrom = from;
	char* tmpto = to;
	/*
	while (*from != '\0') {
		*to++ = *from++;
	}
	*to = '\0';
	*/
	/*
	while ((*to++ = *from++) != '\0' ) {
	}
	*/
	/*
	while (*to++ = *from++) {
	}
	*/
	while (*tmpto++ = *tmpfrom++);  // ';' 是一个独立出来的空语句 不建议 但要能看懂
	return 0;
}

int main21() {
	int ret = 0; // 程序是否正常运转标记，不为 0 时报错并退出，提高程序兼容性；
	char* from = "hellow world!";
	char to[100];

	ret = copy_str(from, to);
	printf("to: %s\n", to);

	// ret 标记 的 实例应用！
	/*
	{
		char* p = NULL;
		ret = copy_str(from, p);
		if (ret != 0) {
			printf("ret: copy_str(from, p); err%d", ret);
			return ret;
		}
	}
	*/

	system("pause");
	return ret;
}
