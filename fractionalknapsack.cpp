#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<float>> knapsnack(int n, int w, vector<vector<float>> arr) {
    vector<vector<float>> temp;
    vector<vector<float>> ans;
    
    for (int i = 0; i < n; i++) {
        float k = (arr[i][0]) / (arr[i][1]);
        temp.push_back({k, arr[i][1]});
    }
    
    sort(temp.begin(), temp.end(), greater<vector<float>>()); 

    int i = 0;
    while (w > 0 && i < n) {
        if (w >= temp[i][1]) {
            ans.push_back({arr[i][0], arr[i][1]});
            w -= temp[i][1]; 
        } else {
            float k = w / temp[i][1];
            ans.push_back({arr[i][0] * k, (float) w});
            w = 0; 
        }
        i++; 
    }
    
    return ans;
}

int main() {
    int n = 3, w = 50;
    vector<vector<float>> arr = {{100, 20}, {130, 20}, {50, 30}};
    arr = knapsnack(n, w, arr);
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i][0] << " " << arr[i][1] << endl;
    }
    
    return 0;
}
