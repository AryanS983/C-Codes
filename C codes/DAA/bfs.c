#include <stdio.h>
#define MAX 100

int adj_matrix[5][5] = {
	{0, 1, 1, 0, 1},
	{1, 0, 1, 0, 0},
	{1, 1, 0, 1, 1},
	{0, 0, 1, 0, 1},
	{1, 0, 1, 1, 0}
};

int queue[MAX];
int front = -1;
int rear = -1;
int visited[5];

void enqueue(int value) {
	if (rear == MAX - 1) {
		printf("Queue is full\n");
		return;
	}
	if (front == -1) {
		front = 0;
	}
	queue[++rear] = value;
}

int dequeue() {
if (front == -1 || front > rear) {
		printf("Queue is empty\n");
		front = -1;
		return -1;
	}
	return queue[front++];
}

int isQueueEmpty() {
	return (front == -1 || front > rear);
}

void findRecommendationsBFS(int user) {
	int i;
	for (i = 0; i < 5; i++) {
		visited[i] = 0;
	}

	visited[user] = 1;
	int j;
	for (j = 0; j < 5; j++) {
		if (adj_matrix[user][j] == 1) {
			enqueue(j);
			visited[j] = 1;
		}
	}

	printf("Friend recommendations for user %d:\n", user);
	int recommendations_found = 0;

	while (!isQueueEmpty()) {
		int current_friend = dequeue();
		int i;
		for (i = 0; i < 5; i++) {
			if (adj_matrix[current_friend][i] == 1 && !visited[i] && i != user) {
				printf("Recommend friend %d (through %d)\n", i, current_friend);
				recommendations_found = 1;
				visited[i] = 1;
				
			}
		}
	}

	if (!recommendations_found) {
		printf("No recommendations available.\n");
	}
}

int main() {
	int user;
	printf("Enter the User to show their friend recommendations (0-4): ");
	scanf("%d", &user);

	if (user < 0 || user >= 5) {
		printf("Invalid user number. Please enter a number between 0 and 4.\n");
		return 1;
	}

	front = -1;
	rear = -1;

	findRecommendationsBFS(user);

	return 0;
}
