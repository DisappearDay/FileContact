#pragma once
#pragma once

#define value 3
#define NAME_MAX 20
#define SEX_MAX 5
#define ADRESS_MAX 15
#define TELE_MAX 15
//#define MAX 1000




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


//通讯录用户信息的结构体
struct PeoInfo
{
	char name[NAME_MAX];  //名字
	int age;              //年龄
	char sex[SEX_MAX];    //性别 
	char tele[TELE_MAX];  //电话
	char adress[ADRESS_MAX];  //住址

};

//通讯录
struct Contact
{
	struct PeoInfo* data;//一个通讯录数组
	int size;    //计算通讯录里面用户的个数
	int capacity; //计算容量
};

enum Option
{
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Show,
	Sort,
	Save
};


//初始化通讯录
void init_contact(struct Contact* str);

//增加一个通讯录的用户信息
void Add_Contact(struct Contact* str);

//展示通讯录所有用户信息
void Show_Contact(const struct Contact* str);

//删除一个通讯录的用户信息
void Del_Contact(struct Contact* str);

//查询一个用户信息
void Search_Contact(const struct Contact* str);

//修改通讯录的信息
void Modify_Contact(struct Contact* str);

//对改通讯录进行排序
void Sort_Contact(const struct Contact* str);

//销毁通讯录
void Destory_contact(struct Contact* str);

//保存通讯录信息
void Save_Contact(struct Contact* str);

//加载通讯录
void Load_Contact(struct Contact* str);
