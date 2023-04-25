#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *firstname;
    struct Node *father;
    struct Node *mother;
    struct Node *marriedto;
};

struct Node *createNode(char *name) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->firstname = name;
    newNode->father = NULL;
    newNode->mother = NULL;
    newNode->marriedto = NULL;
    return newNode;
}

void printTree(struct Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%s\n", root->firstname);

    if (root->father != NULL) {
        printf("father: ");
        printf("%s\n", root->father->firstname);
    }

    if (root->mother != NULL) {
        printf("mother:} ");
        printf("%s\n", root->mother->firstname);
    }

    if (root->marriedto != NULL) {
        printf("marriedto: ");
        printf("%s\n", root->marriedto->firstname);
    }

    printf("\n");

    printTree(root->father);
    printTree(root->mother);
}

int main() {
    struct Node *root = createNode("John");
    root->father = createNode("Peter");
    root->mother = createNode("Mary");
    root->marriedto = createNode("Jane");

    struct Node *child1 = createNode("Bob");
    child1->father = root;
    child1->mother = root->marriedto;

    struct Node *child2 = createNode("Sarah");
    child2->father = root;
    child2->mother = root->marriedto;

    root->father->father = createNode("George");
    root->father->mother = createNode("Alice");

    root->mother->father = createNode("David");
    root->mother->mother = createNode("Eva");

    printTree(root);

    return 0;
}
