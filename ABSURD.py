def main():
	t = input()
	i=0
	while i < t:
		i+=1
		c = int(raw_input().strip('0'))
		llim = .95*c
		ulim = 1.05*c
		x1 = c - (c%10)
		if x1 >= llim and x1 <= ulim:
			print "absurd"
			continue
		x2 = x1 + 5
		if x2 >= llim and x2 <= ulim and x2 != c:
			print "absurd"
			continue
		x3 = x2 + 5
		if x3 >= llim and x3 <= ulim and x3 != c:
			print "absurd"
			continue
		else:
			print "not absurd"


if __name__ == '__main__':
	main()
