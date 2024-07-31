#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void setMatrixtoZeroesOptimal(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
       
    int col0 = 1;
    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;

                if( j!=0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
               
            }
        }
    }


    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            if(matrix[i][j] != 0)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                            matrix[i][j] = 0;
                    }
            }
            
        }
    }

    if(matrix[0][0] == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 0;
        }
    }

    if(col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
// Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
// Reason: In this approach, we are also traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.

// Space Complexity: O(1) as we are not using any extra space.
    }

void setMatrixtoZeroesBetter(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();

    int rows[n] = {0};
    int cols[m] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if( matrix[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if( rows[i] || cols[j])
            {
                matrix[i][j] = 0;
            }
        }

    }
// Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
// Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.

// Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
// Reason: O(N) is for using the row array and O(M) is for using the col array.
}

void markRows(vector<vector<int>>& matrix , int row , int col , int n , int m )
{
    for (int j = 0; j < n; j++)
    {
        if(matrix[row][j] != 0)
        {
            matrix[row][j] = -1;
        }
    }
    
}

void markCols(vector<vector<int>>& matrix , int row , int col , int n , int m )
{
    for (int j = 0; j < m; j++)
        {
            if(matrix[j][col] != 0)
            {
                matrix[j][col] = -1;
            }
        }

}

void setMatrixtoZeroesBF(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if( matrix[i][j] == 0)
            {
                markRows(matrix , i , j , n, m );
                markCols(matrix , i , j , n, m );
            }
        }
        
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if( matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }

    }
    
//     Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.

// Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M). Now, whenever we find any such cell we mark that row and column with -1. This process takes O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)).

// Another O(N*M) is taken to mark all the cells with -1 as 0 finally.

// Space Complexity: O(1) as we are not using any extra space.
}

int main()
{
    vector<vector<int>> matrix {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    //setMatrixtoZeroesBF(matrix);

    for( auto it : matrix)
    {
        for( auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << endl;

    //setMatrixtoZeroesBetter(matrix);

    for( auto it : matrix)
    {
        for( auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << endl;
    setMatrixtoZeroesOptimal(matrix);

    for( auto it : matrix)
    {
        for( auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}