#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


static int FindByName(const struct Contact* str, char name[NAME_MAX])
{
	int i = 0;
	for (i = 0; i < str->size; i++)
	{
		if ((strcmp(str->data[i].name, name)) == 0)
		{
			return i;
		}
	}
	return -1;
}


//初始化通讯录
void init_contact(struct Contact* str) {
	/*memset(str->data, 0, sizeof(str->data));
	str->size = 0;*/
	str->data = (struct PeoInfo*)malloc(value * sizeof(struct PeoInfo));
	if (str->data == NULL)
	{
		return;
	}
	str->size = 0;
	str->capacity = value;
	Load_Contact(str);
}

//声明
void check_capacity(struct Contact* str);

void Load_Contact(struct Contact* str)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfread = fopen("contact.dat","rb");
	if (pfread==NULL)
	{
		printf("Load_Contact::%s\n", strerror(errno));
		return;
	}

	while (fread(&tmp,sizeof(struct PeoInfo),1,pfread))
	{
		check_capacity(str);
		str->data[str->size] = tmp;
		str->size++;
	}

	//关闭文件
	fclose(pfread);
	pfread = NULL;
}

void check_capacity(struct Contact* str)
{
	if (str->size == str->capacity)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(str->data, (str->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			str->data = ptr;
			str->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}



//添加一个用户信息到通讯录
void Add_Contact(struct Contact* str) {
	//检测当前通讯录文件容量
	check_capacity(str);
	printf("请输入 姓名:");
	scanf("%s", str->data[str->size].name);
	printf("请输入 年龄:");
	scanf("%d", &(str->data[str->size].age));
	printf("请输入 性别:");
	scanf("%s", str->data[str->size].sex);
	printf("请输入 电话:");
	scanf("%s", str->data[str->size].tele);
	printf("请输入 住址:");
	scanf("%s", str->data[str->size].adress);
	str->size++;
	printf("添加成功\n");

	/*if (str->size == 1000)
	{
		printf("该通讯录已满，不能再录入信息");
	}
	else
	{
		printf("请输入 姓名:");
		scanf("%s", str->data[str->size].name);
		printf("请输入 年龄:");
		scanf("%d", &(str->data[str->size].age));
		printf("请输入 性别:");
		scanf("%s", str->data[str->size].sex);
		printf("请输入 电话:");
		scanf("%s", str->data[str->size].tele);
		printf("请输入 住址:");
		scanf("%s", str->data[str->size].adress);
		str->size++;
		printf("添加成功\n");
	}*/

}

//展示通讯录的所有信息
void Show_Contact(struct Contact* str)
{
	int i = 0;
	if (str->size == 0)
	{
		printf("该通讯录为空！\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n", "姓名", "年龄", "性别", "电话", "住址");
		for (i = 0; i < str->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",
				(str->data)[i].name,
				(str->data)[i].age,
				(str->data)[i].sex,
				(str->data)[i].tele,
				(str->data)[i].adress);
		}
	}
}


void Del_Contact(struct Contact* str) {
	char name[NAME_MAX];
	printf("请输入要删除的名字:>");
	scanf("%s", name);
	//如果找到了，返回该名字的下标
	//如果没找到，返回-1
	int res = FindByName(str, name);
	if (res == -1)
	{
		printf("该通讯录没有改名字");
	}
	else
	{
		int i = 0;
		for (i = res; i < str->size - 1; i++)
		{
			str->data[res] = str->data[res + 1];
		}
		str->size--;
		printf("删除成功\n");
	}
}

void Search_Contact(const struct Contact* str)
{
	char name[NAME_MAX];
	printf("请输入要查询的用户信息:>");
	scanf("%s", &name);
	int sor = FindByName(str, name);
	if (sor == -1) {
		printf("该通讯录没有该用户的信息");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",
			(str->data)[sor].name,
			(str->data)[sor].age,
			(str->data)[sor].sex,
			(str->data)[sor].tele,
			(str->data)[sor].adress);
	}
}

void Modify_Contact(struct Contact* str)
{
	char name[NAME_MAX];
	printf("请输入要查询的用户信息:>");
	scanf("%s", &name);
	int sor = FindByName(str, name);
	if (sor == -1)
	{
		printf("该通讯录没有该用户的信息");
	}
	else
	{
		printf("请输入 姓名:");
		scanf("%s", str->data[sor].name);
		printf("请输入 年龄:");
		scanf("%d", &(str->data[sor].age));
		printf("请输入 性别:");
		scanf("%s", str->data[sor].sex);
		printf("请输入 电话:");
		scanf("%s", str->data[sor].tele);
		printf("请输入 住址:");
		scanf("%s", str->data[sor].adress);

		printf("修改成功\n");
	}
}

int s_name(const void* str1, const void* str2)
{
	//return strcmp(((struct Contact*)str1)->data->name, ((struct Contact*)str2)->data->name);
	return strcmp((struct peoInfo*)(((struct Contact*)str1)->data)->name, (struct peoInfo*)(((struct Contact*)str2)->data)->name);
}

void Sort_Contact(const struct Contact* str)
{
	int sz = sizeof(str->data) / sizeof(str->data[0]);
	qsort(str->data, sz, sizeof(str->data[0]), s_name);
	printf("排序成功\n");
}


void Destory_contact(struct Contact* str)
{
	free(str->data);
	str->data = NULL;
}


void Save_Contact(struct Contact* str)
{
	FILE* pfwrite = fopen("contact.dat", "wb");
	if (pfwrite == NULL)
	{
		printf("Save_Contact%s::\n", strerror(errno));
		return;
	}

	int i = 0;
	for (i = 0; i < str->size; i++)
	{
		fwrite(&(str->data[i]), sizeof(struct PeoInfo), 1, pfwrite);
	}


	//释放文件
	fclose(pfwrite);
	pfwrite = NULL;
	printf("保存成功\n");
}
