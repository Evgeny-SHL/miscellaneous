_sum = [0] * 101

_sum[0] = int(input())
for i in range(1, 101):
	_sum[i] = _sum[i-1] + int(input())

n = int(input())

print((100 * _sum[100] - 100 * _sum[n]) // _sum[100])