def isUnique(s):

  dict = {}

  for c in s:
    if c in dict:
      return False
    else :
      dict[c] = True
  
  print("1")
  return True

def isUniqueNoDS(s):

  s = "".join(sorted(s))

  for count,c in enumerate(s):
    if(count == len(s)-1):
      break
    elif s[count] == s[count+1]:
      return False

  print(1)
  return True

if __name__== "__main__":
  test1 = "abjdhbadakdl"
  test2 = "lkjhgfdsa"
  test3 = "qwertyuio"
  test4 = "dablsdka;lndakd"
  test5 = "ldbhakjslnfap'daod"

  isUniqueNoDS(test1)
  isUniqueNoDS(test2)
  isUniqueNoDS(test3)
  isUniqueNoDS(test4)
  isUniqueNoDS(test5)




