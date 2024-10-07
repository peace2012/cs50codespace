#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Struct for counting pairs
    typedef struct
{
    int winner;
    int loser;
    int count;
} pair_lib;

pair_lib pair_counts[MAX];

int pair_counts_length = 0;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
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

    // // print reesults of record_preferences function
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         printf("[%i][%i] %i\n", i, j, preferences[i][j]);
    //     }
    // }

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
            int difference = preferences[i][j] - preferences[j][i];

            while (difference > 0)
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                ++pair_count;
                --difference;
            }
        }
    }

    // // print result of add_pairs function
    // for (int i = 0; i < pair_count; i++)
    // {
    //     printf("%i, ", pairs[i].winner);
    //     printf("%i\n", pairs[i].loser);
    // }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

// count pairs and record count into struct

int length_pairs = sizeof(pairs) / sizeof(pairs[0]);

for (int i = 0; i < pair_count; i++)
{
    bool found = false;

    for (int j = 0; j < pair_counts_length; j++)
    {
    if (pairs[i].winner == pair_counts[j].winner && pairs[i].loser == pair_counts[j].loser)
    {
        pair_counts[j].count +=1;
        found = true;
        break;
    }
    }
    if (!found)
    {
    pair_counts[pair_counts_length].winner = pairs[i].winner;
    pair_counts[pair_counts_length].loser = pairs[i].loser;
    pair_counts[pair_counts_length].count = 1;
    ++pair_counts_length;
    }
}

    // sort the struct
for (int j = 1; j < (pair_counts_length-1); j++)
    {
    for (int i = 0; i < (pair_counts_length-j); i++)
    {
        if (pair_counts[i].count < pair_counts[i+1].count)
        {
            pair_lib temp = pair_counts[i];
            pair_counts[i] = pair_counts[i+1];
            pair_counts[i+1] = temp;
        }
    }
    }

        // print result of sort_pairs function
    for (int i = 0; i < pair_counts_length; i++)
    {
        printf("%i, %i (%i)\n", pair_counts[i].winner, pair_counts[i].loser, pair_counts[i].count);
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_counts_length; i++)
    {
        if (i == pair_counts_length - 1) // (last pair of pair_counts)
        {
            bool found = false;
            for (int j = 0; j < candidate_count; j++)
            {
                if (locked[pair_counts[i].winner][j] == true)
                {
                     found = true;
                }
            }
            if (found)
            {
                locked[pair_counts[i].winner][pair_counts[i].loser] = true;
                break;
            }
            else
            break;
        }
        locked[pair_counts[i].winner][pair_counts[i].loser] = true;
    }

// print result of sort_pairs function
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

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}
