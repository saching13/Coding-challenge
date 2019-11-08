# def decodeVariations(S):
#   l = len(S)
#   d =  [1]*(l+1)
  
#   for i in range(l-1,-1,-1):
#     print(i)
#     if S[i] == '0':
#       d[i] = 0
#     elif S[i] == '1':
#       d[i] = d[i+1]+d[i+2]
#     elif S[i] ==  '2':
#       d[i] = d[i+1]
#       if i+1 < l and S[i+1] <= '6':
#         d[i] += d[i+2]
#     else:
#       d[i] = d[i+1]
  
#   return d[0]

def decodeVariations(S):
      l = len(S)
  d =  [1] * l
  
  for i in range(l-1,-1,-1):
    if i >= l-2:
      if i == l-1:
        if S[i] == '0':
          d[i] = 0
        else:
          d[i] = 1
      else:
        if S[i] == '0':
          d[i] = 0
        if S[i] == '1':
          d[i] = 1 + d[i+1] 
        elif S[i] == '2':
          if S[i+1] <= '6':
            d[i] = 1 + d[i+1]
        else:
            d[i] =  d[i+1]      
    else:  
      #d[i] = 1
      if S[i] == '0':
        d[i] = 0
      elif S[i] == '1':
        #if i+2 < l: 
        d[i] = d[i+1]+d[i+2]
        #else:
        #  d[i] = d[i+1]
      elif S[i] ==  '2':
        d[i] = d[i+1]
        if i+1 < l and S[i+1] <= '6':
          d[i] += d[i+2]
      else:
        d[i] = d[i+1]

  return d[0]




print(str(decodeVariations('1270')))



