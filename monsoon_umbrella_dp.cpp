#include<bits/stdc++.h>

using namespace std;

int minUmbrella(int umb[], int m, int n)
{
   // table[i] will be storing the minimum number of umbrella
    // required for i value.  So table[n] will have result
    int table[n+1];

    // Base case (If given value n is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i=1; i<=n; i++)
        table[i] = INT_MAX;

    // Compute minimum umbrella required for all
    // values from 1 to n
    for (int i=1; i<=n; i++)
    {
        // Go through all umbrella smaller which covers lesser/equal people than i
        for (int j=0; j<m; j++)
          if (umb[j] <= i)
          {
              int sub_res = table[i-umb[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[n];
}

int main(){
    int test_cases = 0;
    cin>>test_cases;
    while(test_cases--){
        int n,m;
        cin>>n>>m;
        int umb[m];
        int i =0;
        while(i<m){
            cin>>umb[i];
            i++;
            }
        int res = minUmbrella(umb,m,n);
        if(res == INT_MAX)
            cout<<-1<<"\n";
        else cout<<res<<"\n";
    }
}
