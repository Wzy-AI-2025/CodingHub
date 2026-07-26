/*
这是个记录单词的tries,只能记录小写单词,这是静态方式,
为了理解单词树的原理,这里不计较空间的浪费
*/


#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

//节点结构
typedef struct TrieNode {
	struct TrieNode* node[26];//如果node[i]==NULL表示该单词不存在,反之存在
	int IsEnd;
}TrieNode;

//创造节点
TrieNode* CreateNode() {
	TrieNode* cur = (TrieNode*)malloc(sizeof(TrieNode));
	if (cur) {
		cur->IsEnd = 0;//默认不是结尾
		for (int i = 0; i < 26; i++) {
			cur->node[i] = NULL;
		}
	}
	return cur;
}

//添加单词
void addWorld(const char* s, TrieNode* root) {
	TrieNode* cur = root;
	if (s == NULL || root == NULL)return;
	int size = strlen(s);
	for (int i = 0; i < size; i++) {
		int index = s[i] - 'a';//对应下标
		if (cur->node[index] == NULL)cur->node[index] = CreateNode();
		cur = cur->node[index];
	}
	cur->IsEnd = 1;//标记结尾
}

//查找单词是否存在
int CheckWorld(const char* s, TrieNode* root) {
	if (s == NULL || root == NULL)return 0;
	TrieNode* curr = root;
	int size = strlen(s);
	for (int i = 0; i < size; i++) {
		int index = s[i] - 'a';
		if (curr->node[index] == NULL)return 0;
		curr = curr->node[index];
	}
	if (curr->IsEnd == 0)return 0;
	return 1;
}

// 递归删除辅助函数
// 返回值：该节点是否可以被安全删除（没有子节点且不是单词结尾）
int deleteHelper(TrieNode* node, const char* s, int depth) {
    if (node == NULL) {
        return 0;
    }

    // 到达单词末尾
    if (s[depth] == '\0') {
        node->IsEnd = 0;  // 清除结尾标记

        // 检查是否可以删除此节点
        for (int i = 0; i < 26; i++) {
            if (node->node[i] != NULL) {
                return 0;  // 还有其他单词经过此节点
            }
        }
        return 1;  // 可以安全删除
    }

    int index = s[depth] - 'a';

    // 递归处理子节点
    if (deleteHelper(node->node[index], s, depth + 1)) {
        free(node->node[index]);
        node->node[index] = NULL;

        // 检查当前节点是否可以删除
        if (!node->IsEnd) {
            for (int i = 0; i < 26; i++) {
                if (node->node[i] != NULL) {
                    return 0;
                }
            }
            return 1;
        }
    }
    return 0;
}

// 删除单词（对外接口）
void deleteWord(const char* s, TrieNode* root) {
    if (s == NULL || root == NULL) return;

    // 先判断单词是否存在
    if (!CheckWorld(s, root)) {
        printf("单词 '%s' 不存在，无法删除\n", s);
        return;
    }

    deleteHelper(root, s, 0);
    printf("单词 '%s' 删除成功\n", s);
}


//释放整棵树的函数
void freeTree(TrieNode* root) {
    if (root == NULL) return;
    for (int i = 0; i < 26; i++) {
        if (root->node[i] != NULL) {
            freeTree(root->node[i]);
        }
    }
    free(root);
}


//主函数测试
int main() {
    TrieNode* root = CreateNode();

    printf("========== 测试1：添加单词 ==========\n");
    addWorld("hello", root);
    addWorld("hel", root);
    addWorld("help", root);
    addWorld("world", root);
    addWorld("hi", root);
    printf("已添加：hello, hel, help, world, hi\n\n");

    printf("========== 测试2：查找单词 ==========\n");
    printf("查找 'hello': %s\n", CheckWorld("hello", root) ? "存在" : "不存在");
    printf("查找 'hel': %s\n", CheckWorld("hel", root) ? "存在" : "不存在");
    printf("查找 'help': %s\n", CheckWorld("help", root) ? "存在" : "不存在");
    printf("查找 'hell': %s\n", CheckWorld("hell", root) ? "存在" : "不存在");
    printf("查找 'world': %s\n", CheckWorld("world", root) ? "存在" : "不存在");
    printf("查找 'hi': %s\n", CheckWorld("hi", root) ? "存在" : "不存在");
    printf("查找 'h': %s\n\n", CheckWorld("h", root) ? "存在" : "不存在");

    printf("========== 测试3：删除单词 ==========\n");

    // 测试删除不存在的单词
    printf("尝试删除不存在的单词 'hell':\n");
    deleteWord("hell", root);
    printf("\n");

    // 测试删除是其他单词前缀的单词
    printf("删除 'hel'（是 hello 和 help 的前缀）:\n");
    deleteWord("hel", root);
    printf("删除后查找 'hel': %s\n", CheckWorld("hel", root) ? "存在" : "不存在");
    printf("删除后查找 'hello': %s\n", CheckWorld("hello", root) ? "存在" : "不存在");
    printf("删除后查找 'help': %s\n\n", CheckWorld("help", root) ? "存在" : "不存在");

    // 测试删除有独立路径的单词
    printf("删除 'hello':\n");
    deleteWord("hello", root);
    printf("删除后查找 'hello': %s\n", CheckWorld("hello", root) ? "存在" : "不存在");
    printf("删除后查找 'help': %s\n\n", CheckWorld("help", root) ? "存在" : "不存在");

    // 测试删除独立单词
    printf("删除 'world':\n");
    deleteWord("world", root);
    printf("删除后查找 'world': %s\n\n", CheckWorld("world", root) ? "存在" : "不存在");

    printf("========== 测试4：删除后重新添加 ==========\n");
    printf("重新添加 'world':\n");
    addWorld("world", root);
    printf("查找 'world': %s\n\n", CheckWorld("world", root) ? "存在" : "不存在");

    // 释放内存
 
    printf("内存已释放，程序结束\n");
    freeTree(root);
    return 0;
}

