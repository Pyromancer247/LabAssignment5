#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count = 0;
	node* tmp = head;
	while(tmp != NULL) {
		count++;
		tmp = tmp->next;
	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int length = 0;
    node* tmp = head;

    while(tmp != NULL) {
        length++;
        tmp = tmp->next;
    }
    char* str = (char*)malloc((length+1)* sizeof(char));

    tmp = head;
    int i = 0;
    while(tmp != NULL) {
        str[i]= tmp->letter;
        tmp = tmp->next;
        i++;
    }
     str[i]= '\0';
     return str;
    }

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* new_node = (node*)malloc(sizeof(node));
	node* last = *pHead;
	new_node->letter = c;
	new_node->next = NULL;
	if(*pHead == NULL) {
		*pHead = new_node;
    }
    else{
	while(last->next != NULL){
		last = last->next;
	}
    last->next = new_node;
}

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* tmp = *pHead;
	node* ptr;
	while(tmp != NULL) {
		ptr = tmp;
        tmp = tmp ->next;
		free(ptr);
	}
	*pHead = NULL;
}

int main(void)
{
    printf("THIS WORKS");
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}