import sys
# Python challenge 1, written by schenning1337

url = sys.argv[1]
log = []
for line in sys.stdin:
	line=line.replace(" ","") # Remove space
	log.append(line.rstrip()) # Remove chomp/newline
sep  = '<--'
src  = 'crap'
dst  = 'init'
path = []
path.append(url)
while dst != '[none]':
	tmp = [s  for s in log if url in s]
	dst = tmp[0].split(sep,1)[1]
	src = tmp[0].split(sep,1)[0]
	path.append(dst)
	url = dst
i=1
path.pop() #remove '[none]'
for elem in path[::-1]:
	print str(i)+'.', elem
	i+=1
 
