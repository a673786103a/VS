#include "pch.h"
#include <stdio.h>
#include <vector>
#include <map>
#include <stack>
using namespace std;

struct list_node {
	int val;
	struct list_node * next;
};

list_node * input_list()
{
	int val, n;
	scanf_s("%d", &n);
	list_node * phead = new list_node();
	list_node * cur_pnode = phead;
	for (int i = 1; i <= n; ++i) {
		scanf_s("%d", &val);
		if (i == 1) {
			cur_pnode->val = val;
			cur_pnode->next = NULL;
		}
		else {
			list_node * new_pnode = new list_node();
			new_pnode->val = val;
			new_pnode->next = NULL;
			cur_pnode->next = new_pnode;
			cur_pnode = new_pnode;
		}
	}
	return phead;
}

//翻转链表
list_node* reverse_knode(list_node* head1) {

	list_node* head = new list_node();
	head->next = NULL;
	list_node* cur = head1;
	while (cur != NULL) {
		list_node* node = new list_node();
		node = cur;
		cur = cur->next;
		node->next = head->next;
		head->next = node;

	}
	return head->next;
}
list_node * reverse_knode(list_node * head1, int K)
{
	if (head1 == NULL)
		return head1;
	//////在下面完成代码
	vector<list_node*> v;			//记录下要翻转的头指针
	list_node* cur = head1;
	list_node* tmp = head1;
	map<list_node*, list_node*> m;		//记录头结点对应的尾节点
	int k = 0;
	stack<list_node*> sk;
	while (cur != NULL) {
		sk.push(cur);
		cur = cur->next;
		k++;
		if (k == K) {
			k = 0;
			list_node* head_node = new list_node();	//这个是头结点 不是头指针  为了统一操作  这个题目给的是不带头结点的
			head_node->next = NULL;
			list_node* mov = head_node;
			//采用尾插法
			while (!sk.empty()) {
				list_node* node = sk.top();
				sk.pop();
				mov->next = node;
				mov = mov->next;
			}
			mov->next = NULL;		//到最后一个几点了
			m[head_node->next] = mov;
			v.push_back(head_node->next);
		}
	}
	//如果栈里还有东西  说明 最后一组不够凑成K个  又因为栈的结构，所有采用头插法 保证原虚
	if (!sk.empty()) {
		list_node* head_node = new list_node();
		head_node->next = NULL;
		while (!sk.empty()) {
			list_node* node = sk.top();
			sk.pop();
			node->next = head_node->next;
			head_node->next = node;
		}
		v.push_back(head_node->next);
	}
	//每个元素 都是一个头指针   把这些个头指针连着的链表穿起来
	for (int i = 0; i < v.size() - 1; i++) {
		list_node* node = v[i];
		/*while (node->next != NULL)
			node = node->next;*/
		//node->next = v[i + 1];
		m[node]->next = v[i + 1];		//有了头和尾的映射关系  直接穿到下一个链表上就行了 就不用遍历每个链表
	}
	return v[0];
}

/*
5
1 2 3 4 5 
3

7
1 2 3 4 5 6 7
4
*/

void print_list(list_node * head)
{
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	puts("");
}

int main()
{
	list_node * head = input_list();
	int K;
	scanf_s("%d", &K);
	list_node * new_head = reverse_knode(head, K);
	//list_node * new_head = reverse_knode(head);
	print_list(new_head);
	return 0;
}