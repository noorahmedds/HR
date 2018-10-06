#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

inline void nextNumberAt(int m, int n, int layer, int &curr_i, int &curr_j){
    //0+layer, n-1-layer
    //0+layer, 0+layer
    //m-1-layer, 0+layer
    //m-1-layer, n-1-layer
    
    if (curr_i == 0+layer && curr_j != 0+layer){ //i.e. top left to top right
        curr_j--;
    }
    else if (curr_i != m-1-layer && curr_j == 0+layer){ // top left to bottom left
        curr_i++;
    }
    else if(curr_i == m-1-layer && curr_j != n-1-layer){ //bottom left to bottom right
        curr_j++;
    }
    else if(curr_i != 0+layer && curr_j == n-1-layer){
        curr_i--;
    }
}

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> &matrix, int r) {
    int m = matrix.size();
    int n = matrix[0].size();
    int Ln = min(m, n) / 2; //number of layers
    
    int curr_i = 0;
    int curr_j = 0;
    
    // iterate Ln layers
    for (int layer =0; layer < Ln; layer++){
        // rotateLayer(m,n,i, matrix, r);

            //store next number in buffer until buffer is filled
            //replace next r numbers 
            //do until curr_i and curr_j != 0 + layer

            int ne = (2*(m-(2*layer))) + (2*(n-(2*layer))) - 4; //number of elements in that layer
            int prev;
            int buff;
            int total_rot = r % ne;
            
            for (int j = 0; j < total_rot; j++){ // number of rotations
                curr_i = 0+layer;
                curr_j = 0+layer;
                prev = matrix[curr_i][curr_j];
                for (int i =0; i < ne; i++){ //number of elements
            //      swap the next number with the previous
                    nextNumberAt(m,n,layer, curr_i, curr_j);
                    buff = matrix[curr_i][curr_j];
                    matrix[curr_i][curr_j] = prev;
                    prev = buff;
                }
            }
    }
    
    for (int i =0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

