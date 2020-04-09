import sys

def lcs(str1, str2, i, j, dp):

	if (i > len(str1) - 1)  or j > (len(str2) - 1):
		return 0 
	
	# If the ith and jth elements of str1 and st2 respectively, are same
	if str1[i] == str2[j]:
		if dp[i+1][j+1] == None:
			smallans = lcs(str1, str2, i+1, j+1, dp)
			dp[i+1][j+1] = smallans
			ans = 1 + smallans
		else:
			ans = 1 + dp[i+1][j+1]

	# If the ith and jth elements of str1 and str2 respectively, aren't same
	else:
		if dp[i+1][j] == None:
			a2 = lcs(str1, str2, i+1, j, dp)
			dp[i+1][j] = a2
		else:
			a2 = dp[i+1][j]

		if dp[i][j+1] == None:
			a3 = lcs(str1, str2, i, j+1, dp)
			dp[i][j+1] = a3
		else:
			a3 = dp[i][j+1]
		ans = max(a2, a3) 

	return ans


string1 = input("Enter 1st string: ")
string2 = input("Enter 2nd string: ")

dp = [[None for j in range(len(string2) + 1)] for i in range(len(string1) + 1)]
result = lcs(string1, string2, 0, 0, dp)

print(f"Longest common subsequence has length: {result}")
