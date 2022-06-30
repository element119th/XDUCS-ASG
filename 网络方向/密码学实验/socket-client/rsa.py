import os

def findAllFile(base):  # 获取文件内容
    for root, ds, fs in os.walk(base):
        for f in fs:
            yield f

def EX_GCD(a, b, arr):
	if b == 0:
		arr[0] = 1
		arr[1] = 0
		return a
	g = EX_GCD(b, a % b, arr)
	t = arr[0]
	arr[0] = arr[1]
	arr[1] = t - int(a / b) * arr[1]
	return g

def ModReverse(a, n):
	arr = [0, 1, ]
	gcd = EX_GCD(a, n, arr)
	if gcd == 1:
		return (arr[0] % n + n) % n
	else:
		return -1

def get_E(key1,key2):
	t = max(key1, key2) + 1
	fn = (key1 - 1) * (key2 - 1)
	r = min(t, fn)
	while(1):
		for i in range(2, r+1):
			if r % i == 0 and fn % i == 0:
				break
		if i == r:
			return r
		else:
			r += 1

def encrypt(mes, e, n):
	num = bin(n)[2:]

	t = (mes ** e) % n
	c = bin(t)[2:].zfill(len(num))

	return c




