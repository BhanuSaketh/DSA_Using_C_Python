##Given an integer array nums of unique elements, return all possible subsets
temp,ans=[],[]
def backtrack(nums,start,end):
  ans.append(temp[:])
  for i in range(start,end):
    temp.append(nums[i])
    backtrack(nums,start+1,end)
    temp.pop()

nums=[1,2,3]
backtrack(nums,0,len(nums))

#output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
