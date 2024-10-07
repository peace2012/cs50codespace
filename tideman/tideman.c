#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];
bool visited[MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
    int strength;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool creates_cycle(int winner, int loser, bool *visited);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // place index of candidate name into ranks array
    // for i < candidate_count
    // if compare string name == candidates[i].name
    // put index of candidate at at ranks[rank]
    // return true

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])

// for i up to candidate count -1 (because the last candidate didn't win any votes)
//      for j = i + 1 (the loser is 1 place below the winner) up to candidate count
//          ++preferences[index of winner / ranks[i]][ index of loser / ranks[j]]

{
    for (int i = 0; i < (candidate_count - 1); i++)
    {
        for (int j = (i + 1); j < candidate_count; j++)
        {
            ++preferences[ranks[i]][ranks[j]];
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                ++pair_count;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    // count pairs and record count into struct

    for (int i = 0; i < pair_count; i++)
    {
        pairs[i].strength = preferences[pairs[i].winner][pairs[i].loser] -
                            preferences[pairs[i].loser][pairs[i].winner];
    }

    // sort the struct
    for (int j = 1; j < pair_count; j++)
    {
        for (int i = 0; i <= (pair_count - j); i++)
        {
            if (pairs[i].strength < pairs[i + 1].strength)
            {
                pair temp = pairs[i];
                pairs[i] = pairs[i + 1];
                pairs[i + 1] = temp;
            }
        }
    }

    // print result of sort_pairs function
    for (int i = 0; i < pair_count; i++)
    {
        printf("%i, %i (%i)\n", pairs[i].winner, pairs[i].loser, pairs[i].strength);
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{

    for (int i = 0; i < pair_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {
            visited[j] = false;
        }

        if (!creates_cycle(pairs[i].winner, pairs[i].loser, visited))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    // print result of lock_pairs function
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%s ", locked[j][i] ? "true" : "false");
        }
        printf("\n");
    }

    return;
}

bool creates_cycle(int winner, int loser, bool *nodes)
{
    if (nodes[winner])
    {
        return true;
    }
    nodes[winner] = true;

    // if (locked[loser][winner] == true)
    // {
    //     printf("true, edge back");
    //     return true;
    // }

    for (int i = 0; i < candidate_count; i++)
    {

        // printf("%i, %i, %s\n", loser, i, nodes[winner] ? "true" : "false");
        if (locked[loser][i] == true)
        {

            if (nodes[i]){
                return true;
            }

            if (creates_cycle(loser, i, nodes))
            {
                printf("true, cycle found\n");
                return true;
            }
        }

    }
    nodes[winner] = false;
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // if there's no true value in a candidates losing column of locked, print name as winner
    string winner;

    for (int i = 0; i < candidate_count; i++)
    {
        bool found = false;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            winner = candidates[i];
        }
    }
    printf("%s\n", winner);
    return;
}
