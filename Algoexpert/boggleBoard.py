def isvalid(row, col, board):
    	if  0 <= row <len(board) and 0 <= col < len(board[0]):
		return True
	else:
		False
		
def checkFOund(row, col, board, word, word_index, visited, visiting):
	if isvalid(row,col) and not visited[row][col] and not visiting[row][col] and board[row][col - 1] == word[word_index]:
		visiting[row][col] = True
		isFound = rec_wordMatch(row, col,board, word, word_index + 1)
		visiting = False
		if isFound:
			visited = True
		return isFound


def rec_wordMatch(row, col, board, word, word_index, visited, visiting):
	if not word_index <= len(word):
		return True
	top_left = checkFOund(row, col - 1, board, word, word_index, visited, visiting)
	top_right = checkFOund(row, col + 1, board, word, word_index, visited, visiting)
	top_left1 = checkFOund(row + 1, col, board, word, word_index, visited, visiting)
	top_left2 = checkFOund(row - 1, col, board, word, word_index, visited, visiting)
	top_left3 = checkFOund(row - 1, col - 1, board, word, word_index, visited, visiting)
	top_left4 = checkFOund(row + 1, col + 1, board, word, word_index, visited, visiting)
	top_left5 = checkFOund(row + 1, col - 1, board, word, word_index, visited, visiting)
	top_left6 = checkFOund(row - 1, col + 1, board, word, word_index, visited, visiting)
	
	return top_left or top_right or top_left1 or top_left2 or top_left3 or top_left4 or top_left5 or top_left6

def boggleBoard(board, words):
    # Write your code here.

	visited = []
	visiting = []
	if len(board) == 0: return []
	op = []
	
	for r in range(len(board)):
		sub_visit = [False for c in range(len(board[0]))]
		visited.append(sub_visit)
		visiting.append(sub_visit)
	
				   
	for r in range(len(board)):
		for c in range(len(board[0])):
			if  not visited[r][c]:
				for word in words:
				  	if board[r][c] == word[0]:
				  		visiting[r][c] == True
				  		isFound = rec_wordMatch(r,c,board, word, 1, visited, visiting)
						visiting[r][c] == False
				  		if isFound:
				  			visited[r][c] = True
							op.append(word)
				  			break
	return op