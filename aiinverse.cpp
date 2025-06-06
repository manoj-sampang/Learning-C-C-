#include <iostream>
#include <iomanip>
using namespace std;

class inverse 
{
    float **mptr;  // Pointer to original matrix
    int order;

public:
    inverse(float **p, int num) 
    {
        mptr = p;
        order = num;
    }

    void input() 
    {
        cout << "Enter the matrix of order " << order << " x " << order << ":\n";
        for (int i = 0; i < order; i++) 
        {
            for (int j = 0; j < order; j++) 
            {
                cout << "A[" << i << "][" << j << "] = ";
                cin >> mptr[i][j];
            }
        }
    }

    void print_matrix() 
    {
        cout << fixed << setprecision(4);
        for (int i = 0; i < order; i++) 
        {
            for (int j = 0; j < order; j++) 
            {
                cout << mptr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    bool calc_inverse() 
    {
        int n = order;
        float **aug = new float *[n];
        for (int i = 0; i < n; i++) 
        {
            aug[i] = new float[2 * n];
        }

        // Construct augmented matrix [A | I]
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                aug[i][j] = mptr[i][j];
            }
            for (int j = n; j < 2 * n; j++) 
            {
                aug[i][j] = (i == j - n) ? 1.0f : 0.0f;
            }
        }

        // Gauss-Jordan elimination
        for (int i = 0; i < n; i++) 
        {
            // Find pivot
            float maxEl = abs(aug[i][i]);
            int maxRow = i;
            for (int k = i + 1; k < n; k++) 
            {
                if (abs(aug[k][i]) > maxEl) 
                {
                    maxEl = abs(aug[k][i]);
                    maxRow = k;
                }
            }

            // Swap rows
            if (maxRow != i) 
            {
                for (int k = 0; k < 2 * n; k++) 
                {
                    swap(aug[i][k], aug[maxRow][k]);
                }
            }

            if (aug[i][i] == 0) 
            {
                cout << "Matrix is singular.\n";
                for (int x = 0; x < n; x++) delete[] aug[x];
                delete[] aug;
                return false;
            }

            float pivot = aug[i][i];
            for (int j = 0; j < 2 * n; j++) 
            {
                aug[i][j] /= pivot;
            }

            for (int row = 0; row < n; row++) 
            {
                if (row != i) 
                {
                    float factor = aug[row][i];
                    for (int col = 0; col < 2 * n; col++) 
                    {
                        aug[row][col] -= factor * aug[i][col];
                    }
                }
            }
        }

        // Copy back the inverse from augmented matrix
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                mptr[i][j] = aug[i][j + n];
            }
        }

        // Cleanup augmented matrix
        for (int i = 0; i < n; i++) 
        {
            delete[] aug[i];
        }
        delete[] aug;

        return true;
    }
};

int main() 
{
    int order;
    cout << "Enter the order of matrix (n x n): ";
    cin >> order;

    // Allocate matrix dynamically
    float **mptr = new float *[order];
    for (int i = 0; i < order; i++) 
    {
        mptr[i] = new float[order];
    }

    inverse inv(mptr, order);
    inv.input();

    cout << "\nOriginal matrix:\n";
    inv.print_matrix();

    if (inv.calc_inverse()) 
    {
        cout << "\nInverse matrix:\n";
        inv.print_matrix();
    } else 
    {
        cout << "Matrix has no inverse.\n";
    }

    // Deallocate original matrix
    for (int i = 0; i < order; i++) 
    {
        delete[] mptr[i];
    }
    delete[] mptr;

    return 0;
}
