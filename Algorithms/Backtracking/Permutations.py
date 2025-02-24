##Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

nums=[1,2,3]
ans=[]
def backtrack(start,end):
  if start==end:
    ans.append(nums[:])
  for i in range(start,end):
    nums[start],nums[i]=nums[i],nums[start]
    backtrack(start+1,end)
    nums[start],nums[i]=nums[i],nums[start]

backtrack(0,len(nums))
print(ans)

#output:[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
