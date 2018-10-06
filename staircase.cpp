#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    int spaces_count = n-1;
    
    for (;spaces_count >= 0; spaces_count--){
        for (int i = 0; i < spaces_count; i++){
            cout << " ";
        }
        for (int i =0; i < n - spaces_count; i++){
            cout << "#";
        }
        cout << endl;
    }
    
    return;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}

