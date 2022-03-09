#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool isLoShuMagicSquare(int cSquare[3][3])
{
    bool row = false, column = false, diagonal = false;

    // Checking rows
    if (cSquare[0][0] + cSquare[0][1] + cSquare[0][2] == 15 && cSquare[1][0] + cSquare[1][1] + cSquare[1][2] == 15 && cSquare[2][0] + cSquare[2][1] + cSquare[2][2] == 15)
    {
        row = true;
    }

    // Checking columns
    if (cSquare[0][0] + cSquare[1][0] + cSquare[2][0] == 15 && cSquare[0][1] + cSquare[1][1] + cSquare[2][1] == 15 && cSquare[0][2] + cSquare[1][2] + cSquare[2][2] == 15)
    {
        column = true;
    }

    // Checking diagonal
    if (cSquare[0][0] + cSquare[1][1] + cSquare[2][2] == 15 && cSquare[2][0] + cSquare[1][1] + cSquare[0][2] == 15)
    {
        diagonal = true;
    }

    // Return true in case rows, columns and diagonals all add up to 15 else return false
    if (row && column && diagonal)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int testSquare1[3][3] = {4, 9, 2, 3, 5, 7, 8, 1, 6}; // <- Array is a Lo Shu Magic Square
    int testSquare2[3][3] = {6, 9, 2, 3, 5, 7, 8, 1, 4}; // <- Array isn't a Lo Shu Magic Square
    int randSquare[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  // <- Square generated randomly but initialized with numbers from 1 to 9
    int numRandSquares = 0;
    time_t t;

    srand((unsigned)time(&t));

    // Testing the first square which is a Lo Shu Magic Square
    if (isLoShuMagicSquare(testSquare1))
    {
        printf("Array is a Lo Shu Magic Square :)");
    }
    else
    {
        printf("Array is not a Lo Shu Magic Square :(");
    }

    // Testing the first square which isn't a Lo Shu Magic Square
    if (isLoShuMagicSquare(testSquare2))
    {
        printf("\nArray is a Lo Shu Magic Square :)");
    }
    else
    {
        printf("\nArray is not a Lo Shu Magic Square :(");
    }

    // Generate squares and check to see if the square is a Lo Shu Magic Square. If not repeat until success.
    do
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int temp = randSquare[i][j];
                int randIndexRow = rand() % 3;
                int randIndexColumn = rand() % 3;
                randSquare[i][j] = randSquare[randIndexRow][randIndexColumn];
                randSquare[randIndexRow][randIndexColumn] = temp;
            }
        }

        numRandSquares++;
    } while (!isLoShuMagicSquare(randSquare));

    printf("\nA random square was generated %d times.", numRandSquares);
    printf("\n[%d %d %d]\n[%d %d %d]\n[%d %d %d]", randSquare[0][0], randSquare[0][1], randSquare[0][2], randSquare[1][0], randSquare[1][1], randSquare[1][2], randSquare[2][0], randSquare[2][1], randSquare[2][2]);

    return 0;
}