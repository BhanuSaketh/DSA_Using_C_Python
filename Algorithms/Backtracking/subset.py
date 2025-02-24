##Given an integer array nums of unique elements, return all possible subsets
temp,ans=[],[]
nums=[1,2,3]

def backtrack(start,end):
  ans.append(temp[:])
  for i in range(start,end):
    temp.append(nums[i])
    backtrack(i+1,end)
    temp.pop()


backtrack(nums,0,len(nums))
print(ans)

#output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
