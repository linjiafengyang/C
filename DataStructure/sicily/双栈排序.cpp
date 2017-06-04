// Problem#: 19143
// Submission#: 4815915
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>  
#include <cmath>  
#include <stack>  
#include <string>  
using namespace std;  
  
// global  
bool edges[1005][1005]; // if there is edges between pos i and pos j num  
int color[1005]; // color of each num, 0 initial, 1 color A, 2 color B  
bool can_output; // if can be sort  
  
// put color on num using dfs  
void dfs(int keyPos, int color_, int n) {  
  color[keyPos] = color_;  
  for (int i = 0; i < n; i++) {  
    if (edges[keyPos][i]) {  
      if (color[i] == color_) {  
        can_output = false;  
        break;  
      } else if (!color[i]) {  
        dfs(i, 3 - color_, n);  
      }  
    }  
    if (edges[i][keyPos]) {  
      if (color[i] == color_) {  
        can_output = false;  
        break;  
      } else if (!color[i]) {  
        dfs(i, 3 - color_, n);  
      }  
    }  
  }  
}  
  
int main () {  
  int n;  
  int num[1005];  
  int postMin[1005]; // smallest num behind each pos  
  while (cin >> n) {  
    // initialize  
    for (int i = 0; i < 1005; i++) {  
      color[i] = 0;  
      for (int j = 0; j < 1005; j++) {  
        edges[i][j] = false;  
      }  
    }  
    can_output = true;  
    // input  
    for (int i = 0; i < n; i++) {  
      cin >> num[i];  
    }  
    // compute postMin  
    for (int i = n - 1; i >= 0; i--) {  
      if (i == n - 1) {  
        postMin[i] = num[i];  
      } else {  
        postMin[i] = min(num[i], postMin[i + 1]);  
      }  
    }  
    // make edges  
    //int count = 0;  
    for (int i = 0; i < n - 1; i++) {  
      for (int j = i + 1; j < n; j++) {  
        if (num[i] < num[j] && postMin[j] < num[i]) {  
          // cannot be put into same stack;  
          edges[i][j] = edges[j][i] = true;  
          //count++;  
        }  
      }  
    }  
    //cout << "Edges: " << count << endl;  
    // color the num  
    for (int i = 0; i < n; i++) {  
      if (!color[i]) {  
        dfs(i, 1, n);  
      }  
    }  
  
    // output  
    // cout << "Start output" << endl;  
    stack<int> s1, s2;  
    string order;  
    if (can_output) {  
      // simulate output  
      // cout << "Start simulation" << endl;  
      int output_num = 1; // the num to be output  
      int pos = 0; // the pos of the numbers  
      // no edge between two num means they can be put into one stack  
      while (output_num <= n) {  
        if (color[pos] == 1) {  
          order += "a";  
          s1.push(num[pos++]);  
          // cout << "Push: " << num[pos - 1] << " a" << endl;  
        }  
        while (!s1.empty() && s1.top() == output_num) {  
          // cout << "Pop: " << s1.top() << " b" << endl;  
          s1.pop();  
          order += "b";  
          output_num++;  
        }  
        if (color[pos] == 1 && (s1.empty() || s1.top() > num[pos])) {  
          continue;  
        }  
        while (!s2.empty() && s2.top() == output_num) {  
          // cout << "Pop: " << s2.top() << " d" << endl;  
          s2.pop();  
          order += "d";  
          output_num++;  
        }  
        if (color[pos] == 2) {  
          order += "c";  
          s2.push(num[pos++]);  
          // cout << "Push: " << num[pos - 1] << " c" << endl;  
        }  
      }  
      for (int i = 0; i < order.length(); i++) {  
        if (i) {  
          cout << " ";  
        }  
        cout << order[i];  
      }  
      cout << endl;  
    } else {  
      cout << "0" << endl;  
    }  
  
    while (!s1.empty()) {  
      s1.pop();  
    }  
    while (!s2.empty()) {  
      s2.pop();  
    }  
    order.clear();  
  }  
  
  
  return 0;  
}                                 