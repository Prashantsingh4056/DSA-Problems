#include <bits/stdc++.h>
using namespace std;

vector<long long> findTwoElement(vector<int> &arr)
{
    // code here

    long long n = arr.size();

    // Sn = ((n) * (n + 1)) / 2
    // S2n = ((n) * (n + 1) * (2*n + 1)) / 2

    long long Sn = ((n) * (n + 1)) / 2;
    long long S2n = ((n) * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0, S2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        S += arr[i];
        S2 += ((long long)arr[i] * (long long)arr[i]);
    }

    // let missing number = x , repeated number = y

    long long val1 = S - Sn;   //   (repeated) - (missing)  =  y - x
    long long val2 = S2 - S2n; //   (repeated)^2  -  (missing)^2  =  y^2 - x^2;

    val2 = val2 / val1; // (y² - x²) / (y - x) = (y + x)

    long long y = (val1 + val2) / 2; //  ((y - x) + (y + x)) / 2  = y
    long long x = (val2 - val1) / 2; // ((y + x) - (y - x)) / 2  = x

    return {y, x};
}

int main()
{
    // Idea : 
    // 1. Calculate the sum of first n natural numbers (Sn) and sum of squares of first n natural numbers (S2n).
    // 2. Calculate the sum (S) and sum of squares (S2) of the given array.
    // 3. Let the missing number be x and the repeated number be y.
    // 4. We can derive two equations from the above calculations:
    //    -> (repeated) - (missing) = y - x  => val1 = S - Sn
    //    -> (repeated)^2 - (missing)^2 = y^2 - x^2 => val2 = S2 - S2n
    // 5. We can simplify val2 to get (y + x) by dividing it by val1.
    // 6. Finally, we can solve for y and x using the two equations.    


    vector<int> arr = {3, 1, 2, 5, 3};
    vector<long long> result = findTwoElement(arr); // output : {3, 4}
    cout << "Repeated number: " << result[0] << ", Missing number: " << result[1] << endl;

    return 0;
}