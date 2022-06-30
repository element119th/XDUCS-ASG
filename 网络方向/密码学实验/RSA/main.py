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
	print(num)
	clist = []
	for i in mes:
		m = ord(i)
		t = (m ** e) % n
		c = bin(t)[2:].zfill(len(num))
		clist.append(c)

	return clist

def CryptFiles(e, n):
	base = './files/'
	fileslist = []
	for i in findAllFile(base):
		fileslist.append(i)
	clist = []

	for filename in fileslist:
		# 读取文件内容
		print("开始加密: " + filename)
		with open("./files/" + filename, encoding="utf8", errors='ignore') as f:
			f_str = f.read()
			f.close()

			c = encrypt(f_str, e, n)
			clist.append(c)
			text = ""

			print("加密过后的内容为:")
			for i in range(len(c)):
				print(c[i], end=" ")
				text += c[i] + " "
				if (i+1) % 4 == 0:
					print("")
					text += "\n"

			print("")
			crypt_file = open('files/' + 'crypt_' + filename, 'w')
			crypt_file.write(text)
			crypt_file.close()

	return clist

def DeCryptFiles(ctext, d, n):
	base = './files/'
	fileslist = []
	for i in findAllFile(base):
		fileslist.append(i)
	i = 0

	for filename in fileslist:
		# 读取文件内容
		if filename.find("crypt") == -1:
			continue
		print("开始解密: " + filename)
		text = ctext[i]
		print("解密密文为: ")
		for j in text:
			c = int(j, 2)
			mt = (c ** d) % n
			m = chr(mt)
			print(m, end="")
		i += 1
		print("")

if __name__ == '__main__':
	key1 = int(input("请输入第一个素数："))
	key2 = int(input("请输入第二个素数："))
	n = key1 * key2
	fn = (key1 - 1) * (key2 - 1)
	e = get_E(key1, key2)
	print("自动生成公钥对：({}, {})".format(n, e))
	ctext = CryptFiles(e, n)
	com = input("输入y以解密, 否则退出：")
	if com == "y":
		d = ModReverse(e, fn)
		print("计算出私钥d：{}".format(d))
		DeCryptFiles(ctext, d, n)
