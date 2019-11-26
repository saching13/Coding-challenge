class Solution(object):
    def findCelebrity(self, n):
        """
        :type n: int
        :rtype: int
        """
        candidate = 0
        #celebrity = -1
        for i in range(1,n):
            if knows(candidate,i):
                candidate = i
        
        
        for i in range(0,n):
            if i == candidate:
                continue
            if knows(candidate,i) or not(knows(i,candidate)):
                return -1
            #elif knows(i,candidate):
        return candidate