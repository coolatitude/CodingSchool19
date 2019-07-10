def print_stack(a, b):
	i = 0
	while i < len(a) and i < len(b):
		print(str(a[i]) + "\t|\t" + str(b[i]))
		i += 1
	while i < len(a) or i < len(b):
		if i >= len(a):
			print("\t|\t" + str(b[i]))
		else :
			print(str(a[i]))
		i += 1

def sx(s):
	s[0], s[1] = s[1], s[0]
	return s

def ss(a, b):
	a[0], a[1] = a[1], a[0]
	b[0], b[1] = b[1], b[0]
	return a, b

def px(i, out):
	tmp = []
	tmp.append(out[0])
	tmp.extend(i)
	out = out[1:]
	return tmp, out

def rx(r):
	tmp = []
	tmp.extend(r[1:])
	tmp.append(r[0])
	return tmp

def rr(a, b):
	tmp = []
	tmp.extend(a[1:])
	tmp.append(a[0])
	a = tmp
	tmp = []
	tmp.extend(b[1:])
	tmp.append(b[0])
	b = tmp
	return a, b

def rrx(r):
	tmp = []
	tmp.append(r[-1])
	tmp.extend(r[0:len(r) - 1])
	return tmp

def rrr(a, b):
	tmp = []
	tmp.append(a[-1])
	tmp.extend(a[0:len(a) - 1])
	a = tmp
	tmp = []
	tmp.append(b[-1])
	tmp.extend(b[0:len(b) - 1])
	b = tmp
	return a, b
