typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct ArNode {
    Node* firsth;
} ArNode;

typedef struct Graph {
    ArNode Gp[26];
} Graph;

void addNode(int u, int v, Graph* G) {
    Node* cur = (Node*)malloc(sizeof(Node));
    cur->val = v;
    cur->next = G->Gp[u].firsth;
    G->Gp[u].firsth = cur;
}

void init(Graph* G) {
    for (int i = 0; i < 26; i++) {
        G->Gp[i].firsth = NULL;
    }
}

char* alienOrder(char** words, int wordsSize) {
    if (words == NULL || wordsSize == 0) {
        char* res = (char*)malloc(1);
        res[0] = '\0';
        return res;
    }

    // Step 1: 初始化入度数组，标记所有出现的字符
    int degree[26];
    for (int i = 0; i < 26; i++) {
        degree[i] = -1;
    }

    int kinds = 0;
    // 遍历所有单词，记录所有出现的字符
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            int c = words[i][j] - 'a';
            if (degree[c] == -1) {
                degree[c] = 0;
                kinds++;
            }
        }
    }

    // Step 2: 构建图
    Graph G;
    init(&G);

    for (int i = 0; i < wordsSize - 1; i++) {
        char* left = words[i];
        char* right = words[i + 1];
        int len1 = strlen(left);
        int len2 = strlen(right);
        int minLen = (len1 < len2) ? len1 : len2;

        int j = 0;
        for (; j < minLen; j++) {
            if (left[j] != right[j]) {
                // 添加边: left[j] -> right[j]
                addNode(left[j] - 'a', right[j] - 'a', &G);
                degree[right[j] - 'a']++; // 入度+1
                break; // 只处理第一个不同字符
            }
        }

        // 非法情况：left 是 right 的前缀，但 left 更长
        if (j == minLen && len1 > len2) {

            char* res = (char*)malloc(1);
            res[0] = '\0';
            return res;
        }
    }

    // Step 3: 拓扑排序（Kahn 算法）
    int queue[26];
    int front = 0, rear = 0;

    // 将所有入度为 0 的节点入队
    for (int i = 0; i < 26; i++) {
        if (degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // BFS
    while (front < rear) {
        int u = queue[front++];
        Node* cur = G.Gp[u].firsth;
        while (cur != NULL) {
            degree[cur->val]--;
            if (degree[cur->val] == 0) {
                queue[rear++] = cur->val;
            }
            cur = cur->next;
        }
    }

    // Step 4: 判断是否所有字符都被排序（无环）
    if (rear != kinds) {
        char* res = (char*)malloc(1);
        res[0] = '\0';
        return res;
    }

    // Step 5: 构造结果字符串
    char* result = (char*)malloc((kinds + 1) * sizeof(char));
    for (int i = 0; i < kinds; i++) {
        result[i] = queue[i] + 'a';
    }
    result[kinds] = '\0';

    return result;
}