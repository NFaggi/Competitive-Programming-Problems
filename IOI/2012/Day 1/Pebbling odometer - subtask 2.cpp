//Score: 12/12
right
a:
pebble movD
right
move
jump fin1
b:
pebble movI
left
move
jump fin2
movD:
jump putA
movD2:
get
move
left
left
jump b
movI:
jump putB
movI2:
get
move
right
right
jump a

putA:
right
move
put
left
left
move
right
jump movD2

putB:
left
move
put
right
right
move
left
jump movI2

fin1:
pebble res1
left
move
jump fin12

res1:
get
left
left
move
put
right
right
move
jump fin1

fin12:
pebble res12
left
move
left
move
halt

res12:
get
left
move
put
right
right
move
left
jump fin12

fin2:
pebble res2
right
move
jump fin22

res2:
get
left
left
move
put
right
right
move
jump fin2

fin22:
pebble res22
right
move
right
move
halt

res22:
get
right
move
put
left
left
move
right
jump fin22
