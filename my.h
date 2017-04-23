//headers
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <string.h>
// data defination
using namespace::std;
struct symboltable
{
	char name[20];
	char type[20];
	struct varlist *param;
	struct varlist *local; 
	int num_params;
	
};

struct varlist
{
	char var_name[20];
	char type[20];
	int level;
	int e_type;// 1- normal 2- array 3- pointer
	int num_b;
	struct array_index *array;
	struct varlist *next;
};

struct for_struct
{
	char name[20];
	struct varlist *local;
};


struct array_index
{
	int a;
	struct array_index *next;
};
typedef struct 
{
	char s[10000];
	int gotonum;


}quadraple;


typedef struct{
	vector<int> false_list;
	int begin;
}while_ex;

typedef struct {
		char value[100];
		int type;
	}expression;

int array_valid(char * , int);
int enter_num_b(char * , int);
int  search_func(char *);
void enter_func(char *,char *);
int search_param(char *);
void enter_param(char *,char *);
void print_table();
int  search_vars(char *);
void enter_vars(char *);
int search_struct(char *);
void enter_in_struct(char *);
int search_in_struct_var(char *);
void icprint();
char *nextvar();
void generate(char * );
int sti(char *);
void backpatch(vector<int> &,int );
void merger(vector<int> &,vector<int> &);