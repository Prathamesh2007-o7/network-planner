#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 999999

char building[MAX][50];
int graph[MAX][MAX];
int n = 0;


void clearBuffer()
{
    while (getchar() != '\n');
}


int findBuilding(char name[])
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (strcmp(building[i], name) == 0)
            return i;
    }

    return -1;
}

void inputBuildings()
{
    int i;

    printf("\nEnter number of buildings: ");
    scanf("%d", &n);
    clearBuffer();

    for (i = 0; i < n; i++)
    {
        printf("Enter name of building %d: ", i + 1);
        fgets(building[i], 50, stdin);

    
        building[i][strcspn(building[i], "\n")] = '\0';
    }
}


void inputConnections()
{
    int i, j, cost;

    printf("\nEnter connection costs:\n");
    printf("Enter 0 if there is no direct connection.\n");

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("Cost between %s and %s: ",
                   building[i], building[j]);

            scanf("%d", &cost);

            graph[i][j] = cost;
            graph[j][i] = cost;
        }
    }
}

void displayGraph()
{
    int i, j;

    printf("\nConnection Cost Matrix:\n\n");

    printf("%-15s", "");

    for (i = 0; i < n; i++)
        printf("%-15s", building[i]);

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%-15s", building[i]);

        for (j = 0; j < n; j++)
        {
            printf("%-15d", graph[i][j]);
        }

        printf("\n");
    }
}


void prim()
{
    int key[MAX];
    int parent[MAX];
    int visited[MAX];

    int i, j;
    int start;
    int min;
    int u;
    int totalCost = 0;
    int edges = 0;

    char startName[50];

    clearBuffer();

    printf("\nEnter starting building: ");
    fgets(startName, 50, stdin);

    startName[strcspn(startName, "\n")] = '\0';

    start = findBuilding(startName);

    if (start == -1)
    {
        printf("Building not found!\n");
        return;
    }

    
    for (i = 0; i < n; i++)
    {
        key[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }

    
    key[start] = 0;

    
    for (i = 0; i < n; i++)
    {
        min = INF;
        u = -1;

        /* Find unvisited vertex with smallest key */
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && key[j] < min)
            {
                min = key[j];
                u = j;
            }
        }

       
        if (u == -1)
        {
            printf("\nGraph is disconnected.");
            printf("\nMST cannot be formed.\n");
            return;
        }

    
        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (graph[u][j] != 0 &&
                !visited[j] &&
                graph[u][j] < key[j])
            {
                key[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
   
    printf("\n====================================");
    printf("\nMinimum Spanning Tree");
    printf("\n====================================\n");

    printf("%-25s %-25s %-15s\n",
           "From Building",
           "To Building",
           "Cost");

    for (i = 0; i < n; i++)
    {
        if (parent[i] != -1)
        {
            printf("%-25s %-25s %-15d\n",
                   building[parent[i]],
                   building[i],
                   graph[parent[i]][i]);

            totalCost += graph[parent[i]][i];
            edges++;
        }
    }

    printf("\nTotal Installation Cost = %d\n", totalCost);
    printf("Number of MST connections = %d\n", edges);

    if (edges == n - 1)
        printf("Network successfully connects all buildings.\n");
}

/* Main menu */
int main()
{
    int choice;
    int i, j;

    /* Initialize graph */
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            graph[i][j] = 0;
        }
    }

    while (1)
    {
        printf("\n\n====================================");
        printf("\n University Campus Network Planner");
        printf("\n====================================");

        printf("\n1. Enter Buildings");
        printf("\n2. Enter Connection Costs");
        printf("\n3. Display Cost Matrix");
        printf("\n4. Generate Minimum Cost Network");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                inputBuildings();
                break;

            case 2:
                if (n == 0)
                    printf("\nPlease enter buildings first.");
                else
                    inputConnections();
                break;

            case 3:
                if (n == 0)
                    printf("\nPlease enter buildings first.");
                else
                    displayGraph();
                break;

            case 4:
                if (n == 0)
                {
                    printf("\nPlease enter buildings first.");
                }
                else
                {
                    prim();
                }
                break;

            case 5:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}
