#include<bits/stdc++.h>

using namespace std;

int minUmbrella(int umb[], int m, int n)
{
   // base case
   if (n == 0) return 0;

   // Initialize result
   int res = INT_MAX;

   // Try every umbrella that covers lesser number of people than the number of people to be covered
   for (int i=0; i<m; i++)
   {
     if (umb[i] <= n)
     {
         int sub_res = minUmbrella(umb, m, n-umb[i]);

         // Check for INT_MAX to avoid overflow and see if
         // result can minimized
         if (sub_res != INT_MAX && sub_res + 1 < res)
            res = sub_res + 1;
     }
   }
   return res;
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
