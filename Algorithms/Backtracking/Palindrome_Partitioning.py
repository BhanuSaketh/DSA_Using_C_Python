## Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

temp,ans=[],[]
s='aab'
def backtrack(start,end):
  if start==end:
    ans.append(temp[:])
  for i in range(start,end):
    curr=s[start:i+1]
    if curr==cur[::-1]:
      temp.append(curr)
      backtrack(start+1,end)
      temp.pop()
      
backtrack(0,len(s))
print(ans)

#output: [["a","a","b"],["aa","b"]]
