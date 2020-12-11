while True:
 a = input()
 if a == "test":
  import random
  lines = open('test.txt').read().splitlines()
  myline =random.choice(lines)
  print(myline)

