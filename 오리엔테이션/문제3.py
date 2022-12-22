import math

def solution(N):
  answer = 0

  for i in range(math.floor(N / 2)):
    if i * i == N:
      answer = 1
      break
  
  return answer

print(solution(26))


def solution2(N):
  for i in range(N):
    if i * i > N:
      return 0
    if i * i == N:
      return 1
  


print(solution2(20))