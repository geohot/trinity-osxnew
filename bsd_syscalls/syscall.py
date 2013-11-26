import os

stuff = open("syscalls.master").read().split("\n")[:-1]

out = "#ifndef _SYSCALLS_x86_64_H\n"
out += "#define _SYSCALLS_x86_64_H 1\n"

out += '#include "sanitise.h"\n'
out += '#include "syscall.h"\n'
out += '#include "syscalls/syscalls.h"\n'
out +=  'struct syscalltable syscalls_bsd[] = {\n'

for sc in stuff:
  sc = sc.split("\t")
  scname = sc[1][4:].lower()
  if sc[1] == "AUE_NULL" or not os.path.isfile('/Users/geohot/fuzzing/trinity/syscalls/'+scname+'.c'):
    out += "  NULL,\n"
  else:
    out += "  { .entry = &syscall_"+sc[1][4:].lower() + " },\n"

out += '};\n'
out += '#endif\n'

print out

f = open('/Users/geohot/fuzzing/trinity/include/syscalls-bsd.h', 'w')
f.write(out)
f.close()

