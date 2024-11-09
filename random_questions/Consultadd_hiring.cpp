/*
!!Consultadd's Hiring Drive!!
There are N students (1 to N) participating in Consultadd's hiring drive, 
each student belongs to certain college. The ith student is from Ci(Ci college code, each college has it's unique code) college.
You have to make seating arrangement for them as they will sit on table.

You may buy any numbers of tables for their sitting arrangement, but students sitting at each table
should have consecutive numbers and if two students from same college (i.e Ci == Cj) 
sitting on same table they will cheat in hiring drive.

Cost of each table is K rupees.

Now you have to calculate MINIMUM total inefficieny of Hiring Drive.
Total inefficieny = (Total Cost of the tables + Total Students, who are indulge in cheating).

#Input Format
First line of input contains N (number of students participating, students are numbered from 1 to N) and K (cost of a table).
Second line contains N space separated integers C1,C2...Ci....Cn (College Code).

#Output
Print a single integer representing smallest inefficieny

#Constraints
1 <= N <= 1000
1 <= K <= 1000
1 <= Ci <= 100

Sample Input/Outputs
Example - 1
input
5(number of students) 14(cost of one table)
1 4 2 4 4 (college codes)
output
17
here optimal solution to let all the student seat on one table,
then student 2,4 and 5 are likely to indulge on cheating 
so Total minimum inefficiency will be K + 3, which will be 17.

Example - 2
input
5 1
5 1 3 3 3
output
3
here optimal way to seat students on 3 table in group of [1,2,3] , [4] , [5]
so total inefficiency would be 3*k -> 3.
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
		int n,k;cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int ar[n][n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ar[i][j] = 0;
            }
        }
		map<int,int>m;
		for(int i=0;i<n;i++){
			m.clear();
			for(int j=i;j<n;j++){
				if(j==0){
					ar[i][j] = 0;
				}else{
					ar[i][j] = ar[i][j-1];
				}
				if (m.count(arr[j])) {
                    if (m[arr[j]] == 1) {
                        ar[i][j]++;
                    }
                    ar[i][j]++;
                }
                m[arr[j]]++;
			}
		}
		int dp[101][1001];
		for(int i=0;i<101;i++){
			for(int j=0;j<1001;j++){
				dp[i][j] = 0;
			}
		}
		for(int i=1;i<= n;i++) {
            dp[1][i] = ar[0][i - 1];
        }
        for(int i = 2; i<=100;i++) {
            dp[i][1] = 0;
        }
        for(int i=2;i<=100;i++) {
            for(int j=2;j<=n;j++) {
                int best = INT_MAX;
                for(int p=1;p<j;p++) {
                    best = min(best,dp[i-1][p]+ar[p][j-1]);
                }
                dp[i][j] = best;
            }
        }
        int ans=INT_MAX;
        for(int i=1;i<=100;i++) {
            ans = min(i*k + dp[i][n], ans);
        }
        cout<<ans<<endl;
  return 0;
}

